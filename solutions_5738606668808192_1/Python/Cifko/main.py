filename = "D-large.in"
outf = open("/storage/emulated/0/Download/D.out", "wt")
f = open("/storage/emulated/0/Download/" + filename, "rt")

def firstD(n):
  for p in P:
    if n%p==0:
      return p
  return 0

def solve(n, J):
  global P
  N = 1000
  B = [1]*N
  P = []
  p = 2
  while p < N:
    if B[p]:
      P += [p]
      x = 2*p
      while x < N:
        B[x] = 0
        x += p
    p += 1
  
  X = []
  for i in xrange(2**(n-2)):
    j= 2**(n-1)+1+i*2
    s = "{0:b}".format(j)
    D = []
    good = True
    for b in range(2,11):
      d = firstD(int(s,b))
      if not d:
        good = False
        break
      D += [d]
    if good:
      out(s + " " + " ".join(map(str,D)))
      J -= 1
      if not J:
        return
  print 'Pridaj'

def out(x):
  print x
  outf.write(x+"\n")
  
T = 1
for t in range(1, T+1):
    out("Case #%d:" %t)
    solve(32,500)