import math

def main():
	f = open('B-large.in')
	T = int(f.readline())
	
	for tt in range(T):
		ss = map(int, f.readline().split())
		n = ss[0]
		m = ss[1]

		brd = []
		for i in range(n):
			brd.append(map(int, f.readline().split()))


		flag = 1
		y = [-1] * m
		yb = [-1] * m
		for i in range(n):
			mm = -1
			for j in range(m):
				if brd[i][j] > mm:
					mm = brd[i][j]

			for j in range(m):
				if brd[i][j] < mm:
					if (y[j] >= 0 and y[j] != brd[i][j]) or (brd[i][j] < yb[j]):
						flag = 0
					else:
						y[j] = brd[i][j]
				else:
					if y[j] >= 0 and y[j] < mm:
						flag = 0
					yb[j] = max(yb[j], mm)
		if flag == 1:
			print 'Case #%d: YES' % (tt + 1)
		else:
			print 'Case #%d: NO' % (tt + 1)


main()
