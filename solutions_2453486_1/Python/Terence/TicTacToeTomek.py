def win(s):
	if '.' in s:
		return None
	if 'X' in s and 'O' in s:
		return None
	return s.replace('T', '')[0]

def play(b):
	for i in range(4):
		r = win(b[i])
		if r:
			return r+' won'
		r = win(''.join([b[k][i] for k in range(4)]))
		if r:
			return r+' won'
	r = win(''.join([b[i][i] for i in range(4)]))
	if r:
		return r+' won'
	r = win(''.join([b[i][3-i] for i in range(4)]))
	if r:
		return r+' won'
	if '.' in ''.join(b):
		return 'Game has not completed'
	else:
		return 'Draw'
t = int(raw_input())
for _ in range(1, t+1):
	if _>1:
		raw_input()
	b = [raw_input() for i in range(4)]
	print 'Case #%d: %s' % (_, play(b))
