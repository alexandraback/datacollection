import os,sys, itertools


def travel(N, edges, zips, path, z, l):
	#print l, path, z, indexes
	
	#if len(path) == 1 and len(z) == N:
	if len(z) == N:
		#print "!!!Finish", z
		return int("".join([str(i) for i in z]))


	p = path[-1]
	back = None
	if len(path) > 1:
		back = path[-2]
	
	mn = int("".join([str(i) for i in range(N, 0, -1)]))
	for i in range(1, N + 1):
		#if len(path) == 1:
		#	print "!",i
		if edges[p][i] == 1 :
			if i != back and indexes[i - 1] not in z:
				mn = min(mn, travel(N, edges, zips, path + [i], z + [indexes[i - 1]], l + 1))
	
	#print path, z
	if back is not None:
		mn = min(mn, travel(N, edges, zips, path[:-1], z[:], l + 1))

	return mn

DOWNLOADS = "C:\\Users\\vasiliy.strelnikov\\Downloads"

#sys.setrecursionlimit(2000)

#sel_files = []
#for fname in os.listdir(DOWNLOADS):
#	if fname[:2] == "C-" and fname[-3:] == ".in":
#		print len(sel_files), ":", fname
#		sel_files.append(fname)

#ix = int(sys.stdin.readline())

infile  = "C-small-attempt1.in"
outfile = infile[:-3] + ".out"

ifile = open(DOWNLOADS + "\\" + infile)
ofile = open(DOWNLOADS + "\\" + outfile, "a")


X = int(sys.argv[1])

T = int(ifile.readline().strip())
for t in range(T):
	if t not in range(X * 10, (X + 1) * 10) : 
		continue
	(N, M) = ifile.readline().strip().split()
	N = int(N)
	M = int(M)
	zips = []
	for n in range(N):
		zips.append(int(ifile.readline().strip()))

	szips = sorted(zips)
	#print szips
	indexes = [szips.index(z) + 1 for z in zips]
	#print "Indexes =", indexes

	edges = [[0] * (N + 1) for n in range(N + 1)]
	for m in range(M):
		(i, j) = ifile.readline().strip().split()
		edges[int(i)][int(j)] = 1
		edges[int(j)][int(i)] = 1

	mn = int("".join([str(i) for i in range(N, 0, -1)]))
	#print "STart with", mn
	for n in range(1, N + 1):
		print n
		mn = min(mn, travel(N, edges, indexes, [n], [indexes[n - 1]], 0))

	#print "mn=",mn
	zz = [int(i) for i in str(mn)]
	zzz = [zips[indexes.index(i)] for i in zz]
	#print zzz
	#zzzz = [zips[i - 1] for i in zzz]
	#print zzzz
	
	ans = "Case #" + str(t+1) + ": " + "".join([str(i) for i in zzz])
	print ans
	ofile.write(ans + "\n")

ofile.close()