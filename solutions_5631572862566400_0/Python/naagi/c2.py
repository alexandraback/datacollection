import sys

tests = input ()
for test in range (tests):
  res = 0
  res2 = 0
  n = input ()
  a = map (int, sys.stdin.readline().split())
  love = [0] * n
  for i in range (n):
    a[i] -= 1;
  for i in range (n):
    u = [0] * n
    j = i
    k = 1
    oj = -1
    while u[j] == 0:
      u[j] = k
      if a[j] != oj and love[j] < k-1:
        love[j] = k-1
      k += 1
      oj = j
      j = a[j]
    if j == i:
      if res < k-1:
        res = k-1
#  print (love)
  res3 = 0
  for i in range (n):
    if a[a[i]] == i:
      res3 += 2 + love[i] + love[a[i]]
  res3 /= 2
           

  print ("Case #" + str(test + 1) + ": " + str(max(res, res3)))
