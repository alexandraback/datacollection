import math

def main():
	f = open('input.txt')
	n = int(f.readline())
	for tt in range(1, n + 1):
		brd = []
		for i in range(4):
			brd.append(f.readline())

		res = -1
		for i in range(4):
			cnt1 = 0
			cnt2 = 0
			cnt3 = 0
			for j in range(4):
				cnt1 += brd[i][j] == 'X'
				cnt2 += brd[i][j] == 'O'
				cnt3 += brd[i][j] == 'T'
			if (cnt1 == 4 or (cnt1 == 3 and cnt3 == 1)):
				res = 1
			if (cnt2 == 4 or (cnt2 == 3 and cnt3 == 1)):
				res = 2

		for j in range(4):
			cnt1 = 0
			cnt2 = 0
			cnt3 = 0
			for i in range(4):
				cnt1 += brd[i][j] == 'X'
				cnt2 += brd[i][j] == 'O'
				cnt3 += brd[i][j] == 'T'
			if (cnt1 == 4 or (cnt1 == 3 and cnt3 == 1)):
				res = 1
			if (cnt2 == 4 or (cnt2 == 3 and cnt3 == 1)):
				res = 2
		
		cnt1 = 0
		cnt2 = 0
		cnt3 = 0
		for i in range(4):
			cnt1 += brd[i][i] == 'X'
			cnt2 += brd[i][i] == 'O'
			cnt3 += brd[i][i] == 'T'
		if (cnt1 == 4 or (cnt1 == 3 and cnt3 == 1)):
			res = 1
		if (cnt2 == 4 or (cnt2 == 3 and cnt3 == 1)):
			res = 2
			
		cnt1 = 0
		cnt2 = 0
		cnt3 = 0
		for i in range(4):
			cnt1 += brd[i][3 - i] == 'X'
			cnt2 += brd[i][3 - i] == 'O'
			cnt3 += brd[i][3 - i] == 'T'
		if (cnt1 == 4 or (cnt1 == 3 and cnt3 == 1)):
			res = 1
		if (cnt2 == 4 or (cnt2 == 3 and cnt3 == 1)):
			res = 2

		if res > 0:
			if res == 1:
				print 'Case #%d: X won' % (tt)
			else:
				print 'Case #%d: O won' % (tt)
		else:
			for i in range(4):
				for j in range(4):
					if brd[i][j] == '.':
						res = 3
			if not res == 3:
				print 'Case #%d: Draw' % (tt)
			else:
				print 'Case #%d: Game has not completed' % (tt)

		f.readline()


main()
