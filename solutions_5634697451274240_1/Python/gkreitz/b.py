import sys

def flip(s, idx):
	if idx == -1: idx = len(s)
	return ''.join(['-' if x == '+' else '+' for x in s[idx::-1]]) + s[idx+1:]

def solve(i):
	s = sys.stdin.readline().strip()
	r = 0
	tgt = '+' * len(s)
	sys.stderr.write('%s\n' % (s))
	while s != tgt:
		if s[0] != '-': # Probably too greedy. Probably should search for longest subsequence of - and flip that to top. I'll just be lazy and submit on large anyway.
			s = flip(s, s.find('-') - 1)
		else:
			s = flip(s, s.rfind('-'))
		#sys.stderr.write('%s\n' % (s))
		r += 1
	print r

if __name__ == '__main__':
	c = int(sys.stdin.readline())
	for i in range(c):
		sys.stdout.write('Case #%d: ' % (i+1,))
		solve(i)
