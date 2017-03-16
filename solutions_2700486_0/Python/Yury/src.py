#!/usr/bin/python

import sys, math

def calc3(*ar):
  print(ar)

def dump(msg):
  print(msg, file=sys.stderr)
  #pass



def gen_pascal_sum():
  res = [[1], [1, 1]]

  pre = res[1]

  for n in range(30):
    r2 = [1] + [pre[i] + pre[i-1] for i in range(1, len(pre))] + [1]
    res.append(r2)
    pre = r2


  for line in res:
    s = 0
    for i,x in enumerate(line):
      s = s + x
      line[i] = s


  return res



pascal_sum = gen_pascal_sum()

for l in pascal_sum:
  dump(l)







def calc(N, X, Y):
  dump("%s %s %s" % (N, X, Y))
  k = math.floor((math.sqrt(1+8*N)+1)/4)

  X = abs(X)

  if (X + Y) % 2 == 1:
    return 0.0

  if (X + Y) < 2 * k:
    return 1.0

  if (X + Y) > 2 * k:
    return 0.0

  ks = 2*k*k - k

  D = N - ks

  if D == 0:
    return 0.0

  if Y < 0: return 0.0

  if D <= Y:
    return 0.0

  dump(D)
  dump(Y)

  if D > 2*k:
    Y = Y - D + 2*k
    if Y < 0:
      return 1.0

    D = 4*k - D

    dump('new Y: %s' % Y)
    dump('new D: %s' % D)



  return 1.0 - pascal_sum[D][Y] / pascal_sum[D][D]
    



with open(sys.argv[1]) as f:
  for T in range(1,int(f.readline())+1):
    (N, X, Y) = [int(x) for x in f.readline().split()]
    print("Case #%s: %s" % (T, calc(N, X, Y)))

