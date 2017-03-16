import os,sys, math
import itertools

def fit(DEN, V):
	B = [0] * V
	for i in range(1, len(DEN) + 1):
		for ss in itertools.combinations(DEN, i):
			S = sum(ss)
			#print ss, S
			if S <= V:
				B[S - 1] = 1
	return sum(B) == V

DOWNLOADS = "/Users/vstrelnikov/Downloads"

sel_files = []
for fname in os.listdir(DOWNLOADS):
	if fname[:2] == "C-" and fname[-3:] == ".in":
		print len(sel_files), ":", fname
		sel_files.append(fname)

ix = int(sys.stdin.readline())

infile  = sel_files[ix]
outfile = infile[:-3] + ".out"

ifile = open(DOWNLOADS + "/" + infile)
ofile = open(DOWNLOADS + "/" + outfile, "w")

T = int(ifile.readline())
for t in range(T):
	C,D,V = ifile.readline().split()
	C,D,V = int(C), int(D), int(V)
	DEN = ifile.readline().strip().split()
	DEN = [int(d) for d in DEN]

	#sd = sum(DEN)

	#print DEN, V
	a = 0
	if not fit(DEN, V):
		solved = False
		for i in range(1, 7):
			PD = []
			for d in range(1, V + 1):
				if not d in DEN:
					PD.append(d)
			#print "Candidates", PD
			for nd in itertools.combinations(PD, i):
				#if sum(nd)
				#print "Check", list(DEN) + list(nd)	
				if fit(list(DEN) + list(nd), V):
					a = i
					solved = True
					print '!', DEN, '+', nd, V
					break;
			if solved:
				break

	ans = "Case #" + str(t+1) + ": " + str(a)
	print ans
	ofile.write(ans + "\n")
