def check():
	for i in range(N):
		for j in range(M):
			if l[i][j] < mi[i] and l[i][j] < mj[j]:
				return 'NO'
	return 'YES'

T=int(input())
for x in range(1,T+1):
	N,M = (int(i) for i in input().split())
	l = [[int(j) for j in input().split()] for i in range(N)]
	mi = [max(l[i]) for i in range(N)]
	mj = [max([sl[j] for sl in l]) for j in range(M)]
	print("Case #%d:" % x,check())
