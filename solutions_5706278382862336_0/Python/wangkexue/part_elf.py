import sys

def solve(f):
	#print f
	f = simple_frac(f)
	#print f
	if f[0] == 1 and f[1] == 0:
		return str(1)
	flag = 0
	for i in range(1, 41):
		if f[1] == long(2**i):
			flag = i
	#print flag
	if flag:
		for i in range(1, flag+1):
			f[1] = f[1] / 2
			if f[0] >= f[1]:
				return str(i)
	return "impossible"

def gcd(m, n):
    while n:
        m, n = n, m % n
    return m

def simple_frac(f):
 	cf = gcd(f[0], f[1])
 	return [f[0]/cf, f[1]/cf]

numcases = int(sys.stdin.readline())
for casenum in range(1,numcases+1):
  f = [long(x) for x in sys.stdin.readline().split('/')]
  #print f[0]+' '+f[1]
  #f = float(f[0]) / float(f[1])
  print 'Case #' + repr(casenum) + ': ' + solve(f)