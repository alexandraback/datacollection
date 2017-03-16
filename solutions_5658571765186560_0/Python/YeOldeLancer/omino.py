# Google Code Jam 2015, Qualification Round
# Problem D. Ominous Omino
# Lance C. Simons

def can_always_fill_region(X,R,C):
	# Cannot tile region with even number of X-ominoes
	if R*C % X:
		return False

	# Pieces can be selected with holes
	if X >= 7:
		return False

	# (r+1)x(r+1) piece can be made
	if (X+1)/2 > min(R,C):
		return False

	# Just pick a straight one!
	if X > max(R,C):
		return False

	# Stupid S-piece Can split the field!
	# 0 X X 0
	# X X 0 0
	if (R*C/X) == 2:
		return X < 4

	return True

def go(infilename, outfilename):
	inf = open(infilename, "r")
	outf = open(outfilename, "w")
	runs = int(inf.next().strip())
	for i in range(runs):
		X,R,C = map(int, inf.next().strip().split())
		outf.write("Case #%d: %s\n" % (i+1, {True:"GABRIEL", False:"RICHARD"}[can_always_fill_region(X,R,C)]))


if __name__ == "__main__":
	import sys
	go(sys.argv[1], sys.argv[1].replace(".in", ".out"))
