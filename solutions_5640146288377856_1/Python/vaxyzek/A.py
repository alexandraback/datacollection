import os,sys, math

DOWNLOADS = "/Users/vstrelnikov/Downloads"

sel_files = []
for fname in os.listdir(DOWNLOADS):
  if fname[:2] == "A-" and fname[-3:] == ".in":
    print len(sel_files), ":", fname
    sel_files.append(fname)

ix = int(sys.stdin.readline())

infile  = sel_files[ix]
outfile = infile[:-3] + ".out"

ifile = open(DOWNLOADS + "/" + infile)
ofile = open(DOWNLOADS + "/" + outfile, "w")

T = int(ifile.readline())
for t in range(T):
  R,C,W = ifile.readline().split()
  R, C,W = int(R), int(C), int (W)

  A = 0
  if R > 1:
    A = (R - 1) * (C / W)

  A = A + min(C, int(math.ceil(float(C) / W)) + W - 1)

  ans = "Case #" + str(t+1) + ": " + str(A)
  print ans
  ofile.write(ans + "\n")
