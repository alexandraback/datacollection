import sys

def sum(n, r):
	return n*(2*r+2*n-3)

def binSearch(ini, end, t, r):
	mid = (end+ini)/2
	s = sum(mid, r)
	s1 = sum(mid+1, r)
	if s<=t and s1>t:
		return mid
	elif s<=t:
		return binSearch(mid, end, t, r)
	else:
		return binSearch(ini, mid, t, r)

	
T = input()

for cases in range(0,T):
	r,t = raw_input().split()
	r = int(r)
	t = int(t)
	
	print 'Case #%d: %d' % (cases+1, binSearch(0, t, t, r+1))
	
