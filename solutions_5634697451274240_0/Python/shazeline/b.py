


def flip(s, ind):
	right = s[ind+1:]
	left = s[:ind+1]
	rev_left = left[::-1]
	inv_left = ''.join(['+' if x == '-' else '-' for x in rev_left])
	wow = inv_left + right
	return wow

def find_deepest(s, c):
	i = 0
	while s[i] == c:
		i += 1
	return i - 1

def find_deepest_r(s):
	i = len(s) - 1
	while s[i] == '+':
		i -= 1
	return i

def done(s):
	fin = len(s) * '+'
	return s == fin


def solve(q):
	flips = 0
	while True:
		if done(q):
			break
		if q[0] == '-':
			deep_ind = find_deepest_r(q)
			q = flip(q, deep_ind)
			flips += 1
			continue
		if q[0] == '+':
			ind = find_deepest(q, '+')
			q = flip(q, ind)
			flips += 1
			continue
	return flips


tot = input()
for i in range(tot):
	q = raw_input()
	ans = solve(q)
	print 'CASE #%s: %s' % (i+1, ans)