#!/usr/bin/python

import sys, math

def calc3(*ar):
  print(ar)

def dump(msg):
  print(msg, file=sys.stderr)
  #pass

class Pre(object):
 def __init__(self):
  pass



def calc(s, n):
  #dump((s, n))
  pi = -1
  ccnt = 0
  su = 0
  for i in range(len(s)):
    vow = ("aeiou".find(s[i]) >= 0)

    if not vow:
      ccnt = ccnt + 1
    else:
      ccnt = 0

    if ccnt >= n:
      pi = i

    if pi >= 0:
      su = su + pi - n + 2

    #dump((ccnt, pi, i, su))

  return su

pre = Pre()
with open(sys.argv[1]) as f:
  for T in range(1,int(f.readline())+1):
    dump(T)
    #ns = [int(x) for x in f.readline().split()]
    (s, n) = f.readline().split()
    print("Case #{0}: {1}".format(T, calc(s, int(n))))

