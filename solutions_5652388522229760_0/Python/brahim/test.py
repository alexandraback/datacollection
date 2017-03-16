import sys
t = int(sys.stdin.readline())
for i in range(t):
  n = int(sys.stdin.readline())
  if n == 0:
    print "Case #{}: INSOMNIA".format(1+i)
    continue
  tab = [0 for j in range(10)]
  res = 1
  k=1
  while 1 != 0:
    x = k*n
    res = x
    while x != 0:
      tab[x%10] = 1
      x = x / 10
    found = 0
    for j in range(len(tab)):
      if tab[j] == 0:
        found = 1
        break;
    if found == 0:
      break;
    k += 1
  print "Case #{}: {}".format(1+i, res)
