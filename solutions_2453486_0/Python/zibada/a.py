def check(cells):
	res = 2
	for c in cells:
		if c == 'T': continue
		if c == '.': return 2
		if res == 2:
			res = c
		if res != c: return 2
	return 0 if res == 'O' else 1
		
def solve():
	a = [raw_input() for _ in xrange(4)]
	raw_input()
	win = [False, False, False]
	for i in xrange(4):
		win[check(a[i])] = True
		win[check([a[j][i] for j in xrange(4)])] = True
	win[check([a[i][i] for i in xrange(4)])] = True
	win[check([a[i][3 - i] for i in xrange(4)])] = True
	if win[0]: return "O won"
	if win[1]: return "X won"
	if ''.join(a).find('.') == -1: return "Draw"
	return "Game has not completed"

for i in xrange(input()):
	print "Case #%d: %s" % (i + 1, solve())
