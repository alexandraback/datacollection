
def solve():
	X = map(int, raw_input().split())
	n,s,p = X[:3]
	del X[:3]
	res = 0
	for x in X:
		if x>=p+2*max(0,p-1): res+=1
		elif x>=p+2*max(0,p-2) and s: res+=1; s-=1
	return res


t = input()
for testcase in range(t):
	print "Case #%d: %d" %(testcase+1, solve())
