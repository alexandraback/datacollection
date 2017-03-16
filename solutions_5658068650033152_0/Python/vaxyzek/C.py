import os,sys, itertools


def travel(N, edges, zips, path, z):
	#print path, z
	
	#if len(path) == 1 and len(z) == N:
	if len(path) == N:
		#print "!!!Finish", z
		return z

	allowed = []
	for p in path:
		for i in range(1, N + 1):
			if edges[p][i] == 1 and not i in path:
				allowed = allowed + [i]

	#print path, allowed

	mz = z + "99999"
	for a in allowed:
		mz = min(mz, travel(N, edges, zips, path + [a], z + zips[a - 1]))

	return mz

DOWNLOADS = "C:\\Users\\vasiliy.strelnikov\\Downloads"

#sys.setrecursionlimit(2000)

sel_files = []
for fname in os.listdir(DOWNLOADS):
	if fname[:2] == "C-" and fname[-3:] == ".in":
		print len(sel_files), ":", fname
		sel_files.append(fname)

ix = int(sys.stdin.readline())

infile  = sel_files[ix]
outfile = infile[:-3] + ".out"

ifile = open(DOWNLOADS + "\\" + infile)
ofile = open(DOWNLOADS + "\\" + outfile, "a")

T = int(ifile.readline().strip())
for t in range(T):
	(N, M, K) = ifile.readline().strip().split()
	N = int(N)
	M = int(M)
	K = int(K)

	if N == 1 or M == 1:
		S = K
		ans = "Case #" + str(t+1) + ": " + str(S)
		print ans
		ofile.write(ans + "\n")
		continue

	d = [[[0] * (N + 1) for w2 in range(M + 1)] for w1 in range(M + 1)]
	
	for w1 in range(1, M + 1):
		for w2 in range(w1 - 2, w1 + 3):
			if w2 >= 1 and w2 <= M:
				d[w1][w2][2] = w1 + w2
				#print w1, w2, 2, w1+w2

	#print "---"
	for h in range(3, N + 1):
		for w1 in range(1, M + 1):
			for w2 in range(1, M + 1):
				if d[w1][w2][h - 1] != 0:
					for w3 in range(w2 - 2, w2 + 3):
						if w3 >= 1 and w3 <= M :
							d[w1][w3][h] = max(d[w1][w3][h], d[w1][w2][h - 1] + w3)
							#print w1, w3, h, d[w1][w3][h]
	
	#print "==="
	#print ''.join([str(r) for r in d])
	S = N * M
	for w1 in range(1, M + 1):
		for w2 in range(1, M + 1):
			for h in range(2, N + 1):
				if d[w1][w2][h] >= K:
					#print w1, w2, h, d[w1][w2][h], S
					S = min(S, w1 + w2 + 2 * (h - 2))

	#print N,M,K,S
	ans = "Case #" + str(t+1) + ": " + str(S)
	print ans
	ofile.write(ans + "\n")

ofile.close()