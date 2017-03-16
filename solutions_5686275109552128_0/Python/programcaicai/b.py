import sys

sys.setrecursionlimit(1000000)
T = int(raw_input())

def solve(xs):
	if len(xs)==1:
		xs.append(0)
	sxs = sorted(xs)
	m = sxs[-1]
	if m == 1:
		return 1
	s1 = sxs[-1]
	s2 = solve(sxs[:-1]+[m//2,m-m//2])+1
	s3 = 10000
	if m>3:
	 	s3 = solve(sxs[:-1]+[m//3,m//3,m//3+m%3])+2
	return min(s1,s2,s3)






for casno in range(T):
	n = int(raw_input())
	xs = [int(x) for x in raw_input().split()]
	print 'Case #%d: %d' %(casno+1,solve(xs))