gabiel = "GABRIEL"
richard = "RICHARD"

def who_win(X, row, col):  # assume row <= col
	if X == 1:
		return gabiel
	elif X == 2:
		if (row * col) % 2 == 0:
			return gabiel
		else:
			return richard
	elif X == 3:
		if (row * col) % 3 != 0 or row == 1:
			return richard
		else:
			return gabiel
	elif X == 4:
		if col < 4:
			return richard
		else:
			if row in [1, 2]:
				return richard
			else:
				return gabiel
	return None


if __name__ == "__main__":
	T = int(raw_input())
	for test in xrange(T):
		X, R, C = [int(i) for i in raw_input().split(" ")]
		if R > C:
			R, C = C, R
		who = who_win(X, R, C)
		print "Case #%d: %s" % (test + 1, who)
