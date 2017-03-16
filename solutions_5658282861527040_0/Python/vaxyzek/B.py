import os,sys, itertools

DOWNLOADS = "C:\\Users\\vasiliy.strelnikov\\Downloads"

#sys.setrecursionlimit(2000)

sel_files = []
for fname in os.listdir(DOWNLOADS):
	if fname[:2] == "B-" and fname[-3:] == ".in":
		print len(sel_files), ":", fname
		sel_files.append(fname)

ix = int(sys.stdin.readline())

infile  = sel_files[ix]
outfile = infile[:-3] + ".out"

ifile = open(DOWNLOADS + "\\" + infile)
ofile = open(DOWNLOADS + "\\" + outfile, "w")

T = int(ifile.readline().strip())
for t in range(T):
	(A, B, K) = ifile.readline().strip().split()
	A = int(A)
	B = int(B)
	K = int(K)

	w = 0
	for a in range(A):
		for b in range(B):
			if a & b < K:
				w = w + 1

	ans = "Case #" + str(t+1) + ": " + str(w)
	print ans
	ofile.write(ans + "\n")