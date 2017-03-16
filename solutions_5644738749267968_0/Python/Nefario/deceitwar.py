#!/usr/bin/python
import sys

def main():
	nBlocks = []
	kBlocks = []
	f = open(sys.argv[1], 'r')
	for lineNum, line in enumerate(f):
		line = line.rstrip('\n')
		if lineNum == 0:
			continue
		if lineNum % 3 == 1:
			nBlocks = []
			kBlocks = []
		elif lineNum % 3 == 2:
			nBlocks = [float(n) for n in line.split(' ')]
		elif lineNum % 3 == 0:
			kBlocks = [float(n) for n in line.split(' ')]
			#process here
			print "Case #{}: {} {}".format(((lineNum-1)/3) + 1, deceit(nBlocks, kBlocks), war(nBlocks, kBlocks))
			# print "Case #{}: {}".format((lineNum-1)/3, war(nBlocks, kBlocks))

def deceit(n, k):
	naomiWin = 0
	nBlocks = sorted(n)
	kBlocks = sorted(k)
	kenBlockMax = max(kBlocks)
	for naomiBlock in nBlocks:
		for i, kenBlock in enumerate(kBlocks):
			if naomiBlock > kenBlock:
				# print "Naomi: {}, Ken: {}".format(naomiBlock, kenBlock)
				naomiWin += 1
				# print "Naomi Wins: {}".format(naomiWin)
				kBlocks.pop(0)
				# print kBlocks
				break
	return naomiWin

def war(n, k):
	naomiWin = 0
	n = sorted(n, reverse=True)
	k = sorted(k)
	# print k
	while len(n) > 0:
		naomiBlock = n.pop(0)
		# print "Naomi's Block: ".format(naomiBlock)
		for i, kenBlock in enumerate(k):
			if kenBlock > naomiBlock:
				# print "Ken Win: {}".format(k.pop(i))
				k.pop(i)
				break
		if len(k) > len(n):
			k.pop(0)
			naomiWin += 1
	return naomiWin

if __name__ == "__main__":
	main()