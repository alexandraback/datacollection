import sys

def pali(d, k):
    # returns k-th palindrome with d digits or 0 if k too big
    # start counting with k=0
    # 9 for d=1, d=2
    # 90 for d=3, d=4
    # ...
    e = (d-1)/2
    p = 10**e
    if k >= 9*p:
	return 0
    p += k
    s = str(p)
    r = s[::-1]
    if d%2 == 0:
	return int(s + r)
    else:
	return int(s + r[1:])

dd = 1
kk = 0

def firstpali():
    global dd
    global kk
    dd = 1
    kk = 0
    return pali(dd, kk)

def nextpali():
    global dd
    global kk
    kk += 1
    p = pali(dd, kk)
    if p > 0:
	return p
    else:
	kk = 0
	dd += 1
	return pali(dd, kk)

def ispali(p):
    s = str(p)
    return s == s[::-1]

data = sys.stdin.readlines()
n = int(data[0])
for i in range(1, n+1):
    a, b = tuple(map(int, data[i].split()))
    #print "testing range %d %d" % (a, b)
    p = firstpali()**2
    cnt = 0
    #while p < a:
    #dd += 1
    #	kk = 0
    #p = nextpali()**2
    #dd -= 1
    #p = nextpali()**2
    while p < a:
	p = nextpali()**2
	
    while p <= b:
	if ispali(p):
	    #print p
	    cnt += 1
	p = nextpali()**2
    print "Case #%d: %d" % (i, cnt)
