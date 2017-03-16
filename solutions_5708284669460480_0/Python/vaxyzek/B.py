import os,sys, math
import itertools

def sub(L, W):
	s = 0
	for i in range(len(L) - len(W) + 1):
		#print L, L[i:i+len(W)]
		if W == L[i:i+len(W)]:
			s = s + 1
	
	#print L,W,s
	return s

DOWNLOADS = "/Users/vstrelnikov/Downloads"

sel_files = []
for fname in os.listdir(DOWNLOADS):
	if fname[:2] == "B-" and fname[-3:] == ".in":
		print len(sel_files), ":", fname
		sel_files.append(fname)

ix = int(sys.stdin.readline())

infile  = sel_files[ix]
outfile = infile[:-3] + ".out"

ifile = open(DOWNLOADS + "/" + infile)
ofile = open(DOWNLOADS + "/" + outfile, "w")

T = int(ifile.readline())
for t in range(T):
	K,L,S = ifile.readline().split()
	K,L,S = int(K), int(L), int(S)
	ALP = ifile.readline().strip()
	WORD = ifile.readline().strip()

	m = 0
	n = 0
	g = 0
	for c in itertools.product(ALP, repeat=S):
		s = sub(''.join(c), WORD)
		m = max(m, s)
		g = g + s
		n = n + 1
		#print ''.join(c), WORD, s,m,g,n

	if m == 0:
		a = 0
	else:
		a = float(n*m - g) / n

	ans = "Case #" + str(t+1) + ": " + str(a)
	print ans 
	ofile.write(ans + "\n")
