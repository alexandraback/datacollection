import sys

t = int(sys.stdin.readline())
f = open('a.out','w')

for i in range(t):
	str, n = sys.stdin.readline().split()
	n = int(n)
	t = 0
	z = -1
	for j in range(len(str)-n+1):
		flag = False
		for k in range(n):
			if str[j+k] in 'aeiou':
				flag = True
				break
		if not flag:
			s = (z+1)*(len(str)-j-n+1) if z != -1 else 0
			t += (j+1)*(len(str)-j-n+1)-s
			z = j
	#print 'Case #%d: %d' % (i+1, t)
	f.write('Case #%d: %d\n' % (i+1, t))
f.close()