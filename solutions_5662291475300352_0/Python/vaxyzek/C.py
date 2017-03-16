import os,sys, math, itertools, math

DOWNLOADS = "C:\\Users\\vasiliy.strelnikov\\Downloads"

sel_files = []
for fname in os.listdir(DOWNLOADS):
	if fname[:2] == "C-" and fname[-3:] == ".in":
		print len(sel_files), ":", fname
		sel_files.append(fname)

ix = int(sys.stdin.readline())

infile  = sel_files[ix]
outfile = infile[:-3] + ".out"

ifile = open(DOWNLOADS + "\\" + infile)
ofile = open(DOWNLOADS + "\\" + outfile, "w")

T = int(ifile.readline().strip())
for t in range(T):
    N = int(ifile.readline().strip())    
    hikers = []
    for i in range(N):
        D, H, M = ifile.readline().strip().split()
        D, H, M = int(D), int(H), int(M)
        for j in range(H):
            hikers.append({"d" : D, "m" : M + j})

    if hikers[0]["m"] < hikers[1]["m"]:
        fast, slow = hikers[0], hikers[1]
    else:
        slow, fast = hikers[0], hikers[1]

    ms = slow["m"]
    mf = fast["m"]
    ds = slow["d"]
    df = fast["d"]
    vf = 360.0 / mf
    vs = 360.0 / ms

    #print ms, mf, ds, df
    a = 0
    if ms != mf:
        stm = ms * float(360 - ds) / 360
        fd = df + stm * 360 / mf

        if fd < 720:
            a = 0
        else:
            a = 1

    ans = "Case #" + str(t+1) + ": " + str(a)
    print ans
    ofile.write(ans + "\n")
