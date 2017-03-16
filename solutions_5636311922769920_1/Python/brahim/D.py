import sys
def f(n, k, c):
  if c==1 :
    return n
  if c > k :
    return f(n, k, k)
  elif n == k-1:
    return n*(k**(c-1)) + f(n, k, c-1)
  else:
    return n*(k**(c-1)) + f(n+1, k, c-1)
t = int(sys.stdin.readline())
for test in range(t):
  line = sys.stdin.readline().split()
  k,c,s = int(line[0]), int(line[1]), int(line[2])
  if s*c < k:
    print "Case #{}: IMPOSSIBLE".format(test+1)
    continue
  res = f(0, k, c)
  sys.stdout.write("Case #{}: {}".format(test+1, str(1+res)));
  i = 1
  while i*c < k:
    sys.stdout.write(" " + str(1+f(i*c,k,c)))
    i = i+1
  print
