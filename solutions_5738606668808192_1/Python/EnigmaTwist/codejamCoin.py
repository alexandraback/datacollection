
import sys
from itertools import product

def makePrimeList(maxnum):
	primeList = []
	for i in range(2,maxnum+1):
		#if i%1000==0:
		#	print(i)
		isprime = True
		for p in primeList:
			if p > i**.5:
				break
			if i%p==0:
				isprime = False
				break
		if isprime:
			primeList.append(int(i))
	return primeList


def getDivisor(num, primeList):
	shorterPrimeList = []
	for p in primeList:
		if p > num**.5:
			break
		shorterPrimeList.append(p)
	for p in shorterPrimeList:
		if num%p==0:
			return p
	return 0



def main():

	if len(sys.argv)<3:
		print("Must provide input and output file names!")
		sys.exit(1)

	with open(sys.argv[1]) as f:
		flines = [x.strip() for x in f.readlines()]

	if len(flines) != int(flines[0])+1:
		print("Error! First line isn't equal to number of other lines?")
		print(len(flines))
		print(int(flines[0])+1)
		sys.exit(1)

	outf = open(sys.argv[2],"w")
	outf.write("Case #1:\n")
	#print("Case #1:\n")
	
	inputParams = [int(x) for x in flines[1].split()]
	coinlen = inputParams[0]
	numcoins = inputParams[1]
	
	#maxprime = int(10**(coinlen/2.0))
	#primeList = makePrimeList(maxprime)
	primeList = makePrimeList(10000)
	#print(primeList)
	
	coinctr = 0
	for midcoin in product("01",repeat=coinlen-2):
		testcoin = "1"+"".join(midcoin)+"1"
		#print(testcoin)
		coinSuccess = True
		divisorList = []
		for b in range(2,11):
			testint = int(testcoin, base=b)
			divisor = getDivisor(testint, primeList)
			if divisor==0:
				coinSuccess=False
				#print("XXXX {0} {1}".format(b, testint))
				break
			divisorList.append(str(divisor))
		if coinSuccess:
			outf.write("{0} {1}\n".format(testcoin, " ".join(divisorList)))
			coinctr += 1
			if coinctr >= numcoins:
				break
	#print("Num coins: " + str(coinctr))
	outf.close()

	sys.exit(0)

if __name__ == "__main__":
    main()
