import sys
#fi = sys.stdin
#fo = sys.stdout
#fi = open('A-small-attempt0.in','r')
#fo = open('A-small-attempt0.out','w')
fi = open('A-large.in','r')
fo = open('A-large.out','w')
t = int(fi.readline())
for _ in range(t):
	n,s = fi.readline().split()
	n = int(n)
	s = s.strip()

	tot = ext = 0
	for i in range(n+1):
		if s[i] == '0':
			continue
		if tot < i:
			ext += i-tot
			tot = i
		tot += int(s[i])
	fo.write('Case #%d: %d\n' % (_+1, ext))
fi.close()
fo.close()
