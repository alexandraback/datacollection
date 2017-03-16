import sys
import numpy
sys.setrecursionlimit(10000)


b = [
"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
]
c = [[0]*26 for i in range(10)]
for i in range(10):
	for x in b[i]:
		c[i][ord(x)-ord('A')] += 1



def foo3(s, n):
	if sum(s) == 0:
		return ''
	if n == 10:
		return None
	s2 = s[:]
	for i in range(26):
		if s2[i] < c[n][i]:
			return foo3(s, n+1)
		s2[i] -= c[n][i]
	res = foo3(s2, n) 
	if res is not None:
		return str(n)+res
	return foo3(s, n+1)

def foo2(s):
	a = [0]*26
	for x in s:
		a[ord(x)-ord('A')] += 1
	return foo3(a, 0)




def foo(ifile):
	s = ifile.readline().strip()
	return foo2(s)
 


def main():
    ifile = sys.stdin
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%d: %s' % (i+1, foo(ifile))

main()

