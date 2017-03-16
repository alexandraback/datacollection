#! /Library/Frameworks/Python.framework/Versions/Current/bin/python

T = int(raw_input())

for t in range(1,T+1):

	inpArr = raw_input().split()

	A = int(inpArr[0])
	N = int(inpArr[1])

	sArr = [int(inp) for inp in raw_input().split()]
	sArr = sorted(sArr)

	sSumArr = [A]

	for s in sArr:
		sSumArr += [sSumArr[-1] + s]

	ans = N
	curInserts = 0

	if (A != 1):
		for i in range(N):
			while(A <= sArr[i]):
				curInserts += 1
				A += A - 1
			A += sArr[i]
			if (curInserts + N - (i + 1) < ans):
				ans = curInserts + N - (i + 1)

	print 'Case #'+str(t)+': '+str(ans)