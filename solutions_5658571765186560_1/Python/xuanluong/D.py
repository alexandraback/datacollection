gabiel = "GABRIEL"
richard = "RICHARD"

def who_win(X, row, col):  # assume row <= col
	if X >= 7:
		return richard
	if col < X:
		return richard
	if (row * col) % X != 0:
		return richard
	if X == 1 or X == 2:
		return gabiel
	if X == 3:
		if row == 1:
			return richard
		return gabiel
	if X == 4:
		if row == 1 or row == 2:
			return richard
		return gabiel
	if X == 5:
		if row >= 4:
			return gabiel
		if row == 1 or row == 2:
			return richard
		elif row == 3:
			if col == 5:
				return richard
		return gabiel
	if X == 6:
		if row >= 5:
			return gabiel
		elif row == 1 or row == 2 or row == 3:
			return richard
		else: # row == 4:
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
