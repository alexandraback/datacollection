def print_field(field):
	for row in field:
		print ''.join(row)

#ugly as all hell
def solve(R, C, M):
	field = [['*' for i in xrange(C)] for j in xrange(R)]
	field[0][0] = 'c'
	if R*C - M == 1:
		return field
	if R == 1:
		for c in xrange(1, C-M):
			field[0][c] = '.'
		return field
	elif C == 1:
		for r in xrange(1, R-M):
			field[r][0] = '.'
		return field

	minedif = R*C - M
	for r in xrange(2):
		for c in xrange(2):
			field[r][c] = '.'
	field[0][0] = 'c'
	minedif -= 4
	if minedif < 0:
		return None
	nextc = 2
	nextr = 2
	while minedif >= 2 and (nextc < C or nextr < R):
		if nextc < C and (nextc <= nextr or nextr == R):
			field[0][nextc] = '.'
			field[1][nextc] = '.'
			nextc += 1
		else:
			field[nextr][0] = '.'
			field[nextr][1] = '.'
			nextr += 1
		minedif -= 2
	if minedif == 0:
		return field
	if minedif == 1:
		if C == 2 or R == 2:
			return None
		else:
			if nextc == 2 or nextr == 2:
				return None
			else:
				field[2][2] = '.'
				return field
	nextc = 2
	nextr = 2
	while minedif >= R-2 and nextc < C:
		minedif -= (R-2)
		for r in xrange(R):
			field[r][nextc] = '.'
		nextc += 1
	if minedif < R-2:
		for r in xrange(minedif):
			field[2+r][nextc] = '.'
		minedif = 0
	while minedif >= C-2 and nextr < R:
		minedif -= (C-2)
		for c in xrange(C):
			field[nextr][c] = '.'
		nextr += 1
	if minedif < C-2:
		for c in xrange(minedif):
			field[nextr][2+c] = '.'
		minedif = 0
	return field

T = int(raw_input())
for case in xrange(1,T+1):
	R,C,M = map(int, raw_input().split())
	field = solve(R,C,M)
	#print R,C,M
	print 'Case #' + str(case) + ':'
	if field:
		print_field(field)
	else:
		print 'Impossible'