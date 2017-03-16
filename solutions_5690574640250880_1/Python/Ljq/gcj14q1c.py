
import sys
sys.stdin = open('C-large.in')
sys.stdout = open('C-large.out', 'w')

def Work():
	r, c, m = map(int, input().split())

	if m == r*c-1:
		mm = [ [ '*' for j in range(c) ] for i in range(r) ]
		mm[r-1][c-1] = 'c'
		for i in range(r):
			print(''.join(mm[i]))
		return

	if r == 1:
		if c == 1 and m == 0:
			print('c')
			return
		if m > c - 2: print('Impossible')
		else: print('c' + '.' * (c-m-1) + '*' * m)
		return
	if c == 1: 
		if m > r - 2: print('Impossible')
		else: 
			print('c')
			for i in range(r-m-1): print('.')
			for i in range(m): print('*')
		return

	mm = [ [ '.' for j in range(c) ] for i in range(r) ]
	
	for rr in range(r-1):
		for cc in range(c-1):
			mn = rr * c + cc * (r - rr)
			num = (c - cc - 2) * (r - rr - 2)
			if m >= mn and m <= mn + num:
				for i in range(rr):
					for j in range(c):
						m -= 1
						mm[i][j] = '*'
				for i in range(rr, r):
					for j in range(cc):
						m -= 1
						mm[i][j] = '*'
				for i in range(r-rr-2):
					for j in range(c-cc-2):
						if m > 0: 
							mm[rr+i][cc+j] = '*'
							m -= 1
				mm[r-1][c-1] = 'c'
				for i in range(r):
					print(''.join(mm[i]))
				return

	print('Impossible')
 
if __name__ == '__main__':
	T = int(input())
	for t in range(1, T+1):
		print('Case #%d:' % t)
		Work()