from collections import defaultdict

def solveIt(N,iList):
	NumS = defaultdict(int)
	for l in iList:
		for e in l:
			NumS[e] += 1
	eH = [k for k in NumS if NumS[k] % 2 != 0]
	eH.sort()
	return " ".join(map(str,eH))

T = int(input())
for t in range(T):
	N = int(input())
	iList = []
	for n in range((2*N)-1):
		iList.append(list(map(int,input().split())))
	print("Case #"+str(t+1)+":",solveIt(N,iList))