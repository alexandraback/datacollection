from itertools import product

def canCut(lawn, n, m):
	cells = [ (lawn[r][c], r, c) for r, c in product(range(n), range(m)) ]
	cells.sort(reverse=True)
	rh = [None]*n
	ch = [None]*m
	for h, r, c in cells:
		if rh[r] is None:
			rh[r] = h
		if ch[c] is None:
			ch[c] = h
		if min(rh[r], ch[c]) > h: return False
	return True

t = input()
for case_no in range(1, t+1):
	n, m = map(int, raw_input().split())
	lawn = []
	for i in range(n): lawn.append(map(int, raw_input().split()))
	print 'Case #%d:'  % case_no,
	print ('YES' if canCut(lawn, n, m) else 'NO')