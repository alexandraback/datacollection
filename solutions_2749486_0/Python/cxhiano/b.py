fin = open('a.in', 'r')
fout = open('a.out', 'w')

T = eval(fin.readline())

def read():
	return fin.readline().split(' ')

def nread():
	return map(eval, read())


def direction(d):
	if d[0] + d[1] < 0:
		if d[0] == 0:
			return 'N'
		else:
			return 'E'
	else:
		if d[0] == 0:
			return 'S'
		else:
			return 'W'

def ok(x, y, k):
	if (1 + k) * k / 2 < abs(x) + abs(y):
		return None
	if x == y and x == 0 and k == 0:
		return ''
	for d in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
		seq = ok(x + d[0] * k, y + d[1] * k, k - 1)
		if seq != None:
			return seq + direction(d)
	return None

for t in range(T):
	X, Y = nread()
	for i in range(4, 30):
		seq = ok(X, Y, i)
		if seq:
			fout.write('Case #%d: %s\n' % (t + 1, seq))
			break
