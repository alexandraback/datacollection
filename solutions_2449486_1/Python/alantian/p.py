

import itertools

def rl():
	return map(int,raw_input().split())

a = []
n = 0
m = 0

def bad(x,y):
	l1 = [a[x][y_]for y_ in range(0,m)if y_!=y]
	l2 = [a[x_][y]for x_ in range(0,n)if x_!=x]
	v1 = len(l1)>0 and max(l1) > a[x][y]
	v2 = len(l2)>0 and max(l2) > a[x][y]
	return v1 and v2

def ok():
	for x in range(n):
		for y in range(m):
			if bad(x,y):
				return False;
	return True;

def main():
	global a,n,m
	T = int(raw_input())
	for case in range(1,T+1):
		n,m = rl()
		a = []
		for i in range(n):
			a.append( rl() )

		print 'Case #%d: %s'%(case,'YES'if ok() else 'NO')


if __name__ == '__main__':
	main()