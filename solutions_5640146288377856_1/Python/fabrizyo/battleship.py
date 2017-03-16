T=int(input())
for t in range(1,T+1):
	R,C,W=map(int,input().split())

	res=C//W*R
	res+=W-1
	if C%W!=0:
		res+=1
	print("Case #%d: %d"%(t,res))





