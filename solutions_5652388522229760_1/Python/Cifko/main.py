filename = "A-large.in"
outf = open("/storage/emulated/0/Download/A.out", "wt")
f = open("/storage/emulated/0/Download/" + filename, "rt")

def solve(n):
  if n == 0:
    return "INSOMNIA"
  V = [1]*10
  nv = 10
  m = 0
  while nv:
    m += n
    x = m
    while x:
      d = x % 10
      if V[d]:
        V[d] = 0
        nv -= 1
      x /= 10
  return `m`

def out(x):
  print x
  outf.write(x+"\n")
  
T = int(f.readline())
for t in range(1, T+1):
    out("Case #%d: %s" %(t,solve(int(f.readline()))))