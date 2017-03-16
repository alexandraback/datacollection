import sys

def f(n, r):
    return 2*n*r + 2*n*(n-1) + n

data = sys.stdin.readlines()
n = int(data[0])
#print n
for i in range(1, n+1):
    r, t = tuple(map(int, data[i].split()))
    n = 0
    #print r, t
    hi = 1
    while f(hi, r) <=t:
	hi *= 2
    lo = hi / 2 - 1
    while lo < hi:
	n = (lo + hi) / 2
	if f(n, r) <= t:
	    lo = n+1
	else:
	    hi = n-1
    n -=2
    while f(n, r) <= t:
	n += 1
    n -= 1
    #print n, f(n, r), t
    print "Case #%d:" % i, n
