# -*- coding: utf-8 -*-

def description():
	print """
	You have brought along J different jackets (numbered 1 through J), 
	P different pairs of pants (numbered 1 through P), and 
	S different shirts (numbered 1 through S). 

	You have at least as many shirts as pairs of pants, 
	and at least as many pairs of pants as jackets. (J ≤ P ≤ S.) 

	You will also immediately be taken to Fashion Jail if they find out 
	that you have worn the same two-garment combination more than K times in total.

	Input
		The first line of the input gives the number of test cases, T. 
		T test cases follow; each consists of one line with four integers J, P, S, and K.

	Output
		For each test case, output one line containing Case #x: y, 
		where x is the test case number (starting from 1) and y is an integer: 
		the maximum number of days you will be able to avoid being taken to Fashion Jail. 
		Then output y more lines, each of which consists of three integers: 
		the numbers of the jacket, pants, and shirt (in that order) for one day's outfit. 
		The list of outfits can be in any order, 
		but the outfits must not cause you to go to Fashion Jail as described in the statement above.

		If multiple answers are possible, you may output any of them.

	Limits
		1 ≤ T ≤ 100.
		1 ≤ J ≤ P ≤ S.
		1 ≤ K ≤ 10.

	Small dataset
		S ≤ 3.

	Large dataset
		S ≤ 10.
	"""


def solve(x):
	jpsk = x.split(" ")
	j = int(jpsk[0])
	p = int(jpsk[1])
	s = int(jpsk[2])
	k = int(jpsk[3])
	print "jpsk:", j,p,s,k

	outfits = []
	counterjs = dict()
	counterjp = dict()
	counterps = dict()

	for ji in range(1,j+1):
		for pi in range(ji,p+1)+range(1,ji):
			jipi = str(ji) + str(pi)
			if (jipi in counterjp) and (counterjp[jipi] == k):
				continue
			for si in range(pi,s+1)+range(1,pi):
				jisi = str(ji) + str(si)
				pisi = str(pi) + str(si)
				# skippin
				if (jisi in counterjs) and (counterjs[jisi] == k):
					continue
				if (pisi in counterps) and (counterps[pisi] == k):
					continue
				if (jipi in counterjp) and (counterjp[jipi] == k):
					continue

				# that one is valid, lets wear it
				outfits.append(str(ji)+" "+str(pi)+" "+str(si))

				# count them
				if jisi in counterjs:
					counterjs[jisi] += 1
				else:
					counterjs[jisi] = 1

				if jipi in counterjp:
					counterjp[jipi] += 1
				else:
					counterjp[jipi] = 1

				if pisi in counterps:
					counterps[pisi] += 1
				else:
					counterps[pisi] = 1

	#print counterjp, counterjs, counterps
	return outfits



FILENAME = "C-large"
FILENAME = "C-small-attempt5"
#FILENAME = "C-test"

with open(FILENAME + ".in","r") as f:
	content = f.read().splitlines()

no_of_cases = int(content[0])


outputs = []
for c in content[1:]:
	result = solve(c)
	print result, c
	outputs.append(result)

with open("" + FILENAME +".out","w") as f:
	for o in range(len(outputs)):
		cases = len(outputs[o])
		f.write("Case #"+ str(o+1) + ": " + str(cases) + "\n")
		for oi in outputs[o]:
			f.write(oi + "\n")
