casos = int(raw_input())

for cas in range(1, casos + 1):
  r, t = map(int, raw_input().split())
  ini = 1
  fin = t
  while ini <= fin:
    n = (ini + fin)/2
    if n*(2*r + 2*n - 1) <= t:
      ini = n + 1
    else:
      fin = n - 1
  print "Case #" + str(cas) + ":", ini - 1