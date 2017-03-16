import sys
sys.setrecursionlimit(10000)

def foo2(s):
	if len(s) <= 1:
		return s	
	m = max(s)
	idx = s.rfind(m)
	return m + foo2(s[:idx]) + s[idx+1:]


def foo(ifile):
	s = ifile.readline().strip()
	return foo2(s)
 


def main():
    ifile = sys.stdin
    n = int(ifile.readline())
    for i in range(n):
        print 'Case #%d: %s' % (i+1, foo(ifile))

main()

