import sys

fin = open(sys.argv[1], "r")
fout = open("D.out", "w")

T = int(fin.readline())
for m in xrange(T):
	X, R, C = map(int,fin.readline().split())
	out = 'GABRIEL'
	if R*C % X !=0:
		out = 'RICHARD'
	elif min(R,C)==1 and X > 2:
		out = 'RICHARD'
	elif X > 2*min(R,C)+1:
		out = 'RICHARD'
	elif X > 7:
		out = 'RICHARD'
	elif X > 3 and min(R,C) == 2:
		out = 'RICHARD'
	elif X == 5 and	R*C == 15:
		out = 'RICHARD'
	elif X == 6 and min(R,C) < 5:
		out = 'RICHARD'						

	fout.write("Case #" + str(m+1) + ": " + out + "\n")