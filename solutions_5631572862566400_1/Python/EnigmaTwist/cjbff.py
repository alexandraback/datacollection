import sys
from collections import defaultdict

# python.exe cjbase.py "..\..\..\Downloads\B-small-attempt0.in"


def findMutuals(bffdict, n):
	mutualList = []
	for i in range(1,n+1):
		if i == bffdict[bffdict[i]] and i < bffdict[i]:
			mutualList.append((i, bffdict[i]))
	return mutualList

def biggestLoopSize(bffdict, n):
	fullseenset = set()
	maxloopsize = 0
	for k in range(1,n+1):
		if k in fullseenset:
			continue
		seenlist = [int(k)]
		newk = 0
		getoutnow = False
		while True:
			newk = bffdict[int(k)]
			if newk in fullseenset:
				getoutnow = True
				break
			if newk in seenlist:
				break
			seenlist.append(int(newk))
			k = int(newk)
		if getoutnow:
			fullseenset |= set(seenlist)
			continue
		loopsize = len(seenlist) - seenlist.index(newk)
		if loopsize > maxloopsize:
			maxloopsize = int(loopsize)
		fullseenset |= set(seenlist)
	return maxloopsize


def longestBackChain(btkDict, currk, prevk, currlen):
	#print("TEST: " + str([currk, prevk, currlen]))
	longestlen = 0
	otherkids = set(btkDict[currk]) - set([prevk])
	for nextk in otherkids:
		newlen = longestBackChain(btkDict, nextk, currk, currlen+1)
		if newlen > longestlen:
			longestlen = int(newlen)
	#print("TEST2: " + str([currk, prevk, currlen, longestlen]))
	return currlen + longestlen


def main():

	with open(sys.argv[1]) as f:
		flines = [x.strip() for x in f.readlines()]

	if len(flines[-1])==0:
		flines = flines[:-1]

	outf = open(sys.argv[2],"w")

	casenum = 0
	
	for fl in flines[2::2]:
		casenum +=1
		linelist = [int(x) for x in fl.split()]
		numkids = len(linelist)
		kidToBff = {}
		for i in range(numkids):
			kidToBff[i+1] = linelist[i]
		#print(kidToBff)
		bffToKids = defaultdict(list)
		for k in range(1,len(kidToBff)+1):
			bffToKids[kidToBff[k]].append(k)
		#print(bffToKids)
		mutlist = findMutuals(kidToBff, numkids)
		#print(mutlist)
		bls = biggestLoopSize(kidToBff, numkids)
		#print("BLS = " + str(bls))
		# mut pairs
		mutscore = len(mutlist)*2
		if mutscore > bls:
			bls = int(mutscore)
		# If no mutuals, then just the biggest loop
		if len(mutlist)==0:
			#print("No mutuals!")
			outf.write("Case #{}: {}\n".format(str(casenum), str(bls)))
		# If mutuals, can start from that pairing then build outward
		else:
			#print("Some mutuals!")
			bestscore = bls
			thisscore = 0
			for mpair in mutlist:
				alen = longestBackChain(bffToKids, mpair[0], mpair[1], 1)
				#print("alen = " + str(alen))
				blen = longestBackChain(bffToKids, mpair[1], mpair[0], 1)
				alenfixed = (((8*(alen)+1)**.5)-1)/2
				blenfixed = (((8*(blen)+1)**.5)-1)/2
				score = alenfixed + blenfixed
				thisscore += int(score)
			if thisscore > bestscore:
				bestscore = int(thisscore)
			
			
			outf.write("Case #{}: {}\n".format(str(casenum), str(bestscore)))
	
	outf.close()

	sys.exit(0)

if __name__ == "__main__":
    main()





