

l = []

def go(x,y,dx,dy,c):
	global l;
	a,b = 0,0
	for i in range(4):
		if l[x][y] == c:
			a += 1
		if l[x][y] == 'T':
			b += 1
		x,y = x+dx, y+dy
	return a,b


def win(c):
	res = []
	for i in range(4):
		res.append( go(i,0,0,1,c) )
		res.append( go(0,i,1,0,c) )
	res.append( go(0,0,1,1,c) )
	res.append( go(0,3,1,-1,c) )
	for a,b in res:
		if a + b == 4 and b <= 1:
			return True
	return False

def full():
	global l;
	return ''.join(l).find('.') != -1

def main():
	global l;
	n = int(raw_input())
	for case in range(1,n+1):
		l = []
		for i in range(4):
			l.append( raw_input() )
		raw_input()

		print 'Case #%d:'%case ,
		if win('X'):
			print 'X won'
		elif win('O'):
			print 'O won'
		elif full():
			print 'Game has not completed'
		else:
			print 'Draw'


if __name__ == '__main__':
	main()