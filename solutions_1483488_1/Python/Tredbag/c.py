import sys, re

def solve(a, b):
	sa = str(a)
	l = len(sa)
	ans = 0
	
	for i in range(a, b):
		si = str(i)
		ex = []
		for j in range(1, l):
			sj = si[j:] + si[0:j]
			tj = int(sj)
			if (tj > i and tj >= a and tj <= b and ex.count(tj) == 0):
				ans = ans + 1
				ex.append(tj);
	return ans
		
def printf(format, *args):
	sys.stdout.write(format % args) 

t = int(raw_input())
for i in range(1, t+1):
	l = sys.stdin.readline()
	p = re.findall('\d+', l);
	a = int(p[0])
	b = int(p[1])
	printf('Case #%d: %d\n', i, solve(a, b))
