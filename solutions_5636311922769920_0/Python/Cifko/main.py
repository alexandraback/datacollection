filename = "D-small-attempt0.in"
outf = open("/storage/emulated/0/Download/D.out", "wt")
f = open("/storage/emulated/0/Download/" + filename, "rt")

def solve(s):
  k,c,s = map(int, s.split(' '))
  if c==1:
    if s<k:
      return "IMPOSSIBLE"
    return " ".join(map(str,range(1,k+1)))
  if s<k-1:
    return "IMPOSSIBLE"
  if k==1:
    return "1"
  return " ".join(map(str,range(2,k+1)))

def out(x):
  print x
  outf.write(x+"\n")
  
T = int(f.readline())
for t in range(1, T+1):
    out("Case #%d: %s" %(t,solve(f.readline())))