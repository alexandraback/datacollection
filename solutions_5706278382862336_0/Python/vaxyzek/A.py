import fractions
import os,sys

DOWNLOADS = "C:\\Users\\vasiliy.strelnikov\\Downloads"

sel_files = []
for fname in os.listdir(DOWNLOADS):
	if fname[:2] == "A-" and fname[-3:] == ".in":
		print len(sel_files), ":", fname
		sel_files.append(fname)

ix = int(sys.stdin.readline())

infile  = sel_files[ix]
outfile = infile[:-3] + ".out"

ifile = open(DOWNLOADS + "\\" + infile)
ofile = open(DOWNLOADS + "\\" + outfile, "w")

T = int(ifile.readline().strip())
for t in range(T):
	frac = ifile.readline().strip()
	P, Q = frac.split('/')
	P = int(P)
	Q = int(Q)
	F = fractions.Fraction(P, Q)

	m = 12
	possible = False
	for i in range(1, 11):
		f = fractions.Fraction(1, 1 << i)
		if Q == 1 << i:
			possible = True
		if F >= f:
			#print i, f, F
			m = min(m, i)

	if m < 12 and possible:
		s = str(m)
	else:
		s = "Impossible"
	ans = "Case #" + str(t+1) + ": " + s
	print ans
	ofile.write(ans + "\n")