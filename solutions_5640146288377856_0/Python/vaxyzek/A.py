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
  C,W = int(C), int (W)

  A = C
  if W == 2:
    A = int(math.ceil(C / 2.)) +1
  elif W == 3:
    A = int(math.ceil(C / 3.)) + 2
  elif W == 4:
    A = int(math.ceil(C / 4.)) + 3
  elif W == 5:
    A = int(math.ceil(C / 5.)) + 4
  elif W == 6:
    A = int(math.ceil(C / 6.)) + 5
  elif W == 7:
    A = int(math.ceil(C / 7.)) + 6
  elif W == 8:
    A = int(math.ceil(C / 8.)) + 7
  elif W == 9:
    A = C
  elif W == 10:
    A = C

  A = min(A,C)

  ans = "Case #" + str(t+1) + ": " + str(A)
  print ans
  ofile.write(ans + "\n")
