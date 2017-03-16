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



def calc(x, y):
  r = ""
  if x > 0:
    r = "E"
    for i in range(1, x):
      r = r + "WE"
  elif x < 0:
    r = "W"
    for i in range(1, -x):
      r = r + "EW"

  if y > 0:
    for i in range(y):
      r = r + "SN"
  elif y < 0:
    for i in range(-y):
      r = r + "NS"

  return r


pre = Pre()
with open(sys.argv[1]) as f:
  for T in range(1,int(f.readline())+1):
    (x, y) = [int(x) for x in f.readline().split()]
    print("Case #{0}: {1}".format(T, calc(x, y)))

