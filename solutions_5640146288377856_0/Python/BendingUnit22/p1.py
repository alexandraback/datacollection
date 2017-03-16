# BendingUnit22; usage: prog_name.py <input.in >output.out

def find_min(R, C, W):
	free_rows = R - 1
	hits = (R -1) * (C/W)
	if C == W:
		return hits + W
	hits += (C-W-1) / W
	return hits + W + 1

cases = int(raw_input())
for case in range(cases):
	print "Case #%s:" % (case+1),
	R, C, W = map(int, raw_input().split())
	print find_min(R, C, W)
