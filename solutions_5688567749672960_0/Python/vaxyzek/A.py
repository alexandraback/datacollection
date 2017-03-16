import os,sys

def reverse(i):
    return int(str(i)[::-1])

DOWNLOADS = "C:\\Users\\vasiliy.strelnikov\\Downloads"

sel_files = []
for fname in os.listdir(DOWNLOADS):
	if fname[:2] == "A-" and fname[-3:] == ".in":
		print len(sel_files), ":", fname
		sel_files.append(fname)
len(sel_files) == 0 and sys.exit(0)

ix = int(sys.stdin.readline())

infile  = sel_files[ix]
outfile = infile[:-3] + ".out"

ifile = open(DOWNLOADS + "\\" + infile)
ofile = open(DOWNLOADS + "\\" + outfile, "w")

T = int(ifile.readline().strip())
for t in range(T):
    N = int(ifile.readline().strip())
    M = [N + 1] * (N + 1)
    M[1] = 1
    for n in range(1, N):
        #print n, M
        M[n + 1] = min(M[n + 1], M[n] + 1)
        r = reverse(n)
        if r <= N:
            M[r] = min(M[r], M[n] + 1)

    #print M

    ans = "Case #" + str(t+1) + ": " + str(M[N])
    print ans
    ofile.write(ans + "\n")