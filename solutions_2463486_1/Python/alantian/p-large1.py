

import sys

def palin(v):
	s=str(v)
	return s == s[::-1]

q = []
f = {}
l = []

def solve():
	global q,f,l
	f = {}
	for (a,b) in q:
		f[a-1] = -1
		f[b] = -1
	for v in f:
		l.append( v )
	l = sorted(l)

	ptr = 0

	ans = 0
	v = 1
	while True:
		v2 = v*v
		#sys.stderr.write( '%d\n'%v2 )
		while ptr < len(l) and l[ptr] < v2:
			f[ l[ptr] ] = ans
			ptr += 1
		if ptr == len(l):
			break

		if palin(v) and palin(v2):
			ans += 1

		v += 1


def main():
	global p
	p = []

	T = int(raw_input())
	for case in range(1,T+1):
		a,b = map(int,raw_input().split())
		q.append( (a,b) )

	solve()

	case = 0
	for (a,b) in q:
		case += 1
		fb = f[b]
		fa = f[a-1]
		ans = fb - fa
		print 'Case #%d: %d'%(case,ans)

if __name__ == '__main__':
	main()