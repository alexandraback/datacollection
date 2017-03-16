
s = open("A-small-attempt0.in").read().split("\n")
out = open("out.txt", "w")

v = set(['a', 'e', 'i', 'o', 'u'])

T = int(s[0])
for t in range(1,T+1):
  res = 0
  j = 0
  k = 0
  w, n = s[t].split()
  n = int(n)
  for i, a in enumerate(w):
    if a not in v:
      k += 1
    else:
      k = 0
    if k == n:
      res += (i-n+1-j+1)*(len(w)-i)
      j = i-n+2
      k -= 1
  print "Case #"+str(t)+": "+str(res)