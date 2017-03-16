import sys
def solve(ks):
  counts = [0,0,0,0,0,0]
  for k in ks:
    lc = [0,0,0,0,0,0]
    lt = 0
    while k%5 == 0:
      lc[5] += 1
      k /= 5
      lt += 1
    while k%3 == 0:
      lc[3] += 1
      k /= 3
      lt += 1
    if lt == 2:
      lc[k] += 1
      k = 1
    while k > pow(2, 3-lt):
      lc[4] += 1
      k /= 4
      lt += 1
    for i in range(2,6):
      counts[i] = max(counts[i], lc[i])
  out = ""
  for i in range(2,6):
    for j in range(0, counts[i]):
      out += str(i)
  while len(out) < 3:
    out += "2"
  print out
      

print "Case #1:"
a = sys.stdin.readlines()
(R, N, M, K) = map(int, a[1].split(" "))
for s in a[2:]:
  ks = map(int, s.split(" "))
  solve(ks)
