import sys

def read_ints():
	return map(int, sys.stdin.readline().split())
#	return [int(x) for x in sys.stdin.readline().split()]

(T,) = read_ints()
for case in range(1, T + 1):
	l1 = sys.stdin.readline()[:-1]
	l2 = sys.stdin.readline()[:-1]
	l3 = sys.stdin.readline()[:-1]
	l4 = sys.stdin.readline()[:-1]
	l5 = sys.stdin.readline()

	l5 = l1[0] + l2[1] + l3[2] + l4[3]
	l6 = l1[3] + l2[2] + l3[1] + l4[0]
	lines = [l1, l2, l3, l4, l5, l6]
	for i in xrange(4):
		lines.append(l1[i] + l2[i] + l3[i] + l4[i])

	ans = ''
	incomplete = 0
	for line in lines:
		l = line.replace('T', 'X')
		if ('.' in l):
			incomplete = 1
		if (l == 'XXXX'):
			ans = 'X won'
			break
	if (ans == ''):
		for line in lines:
			l = line.replace('T', 'O')
			if (l == 'OOOO'):
				ans = 'O won'
				break
	
	if (ans == ''):
		if (incomplete == 1):
			ans = 'Game has not completed'
		else:
			ans = 'Draw'

	print "Case #%d: %s" % (case, ans)
	

