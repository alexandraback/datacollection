#!/usr/local/bin/python2.7
import sys
import math

def triangular(n):
  t = 0
  while t*(t+1)/2 <= n:
    t += 1
  return (t-1)-(t)%2


def output(T, values):
  for i in range(0, T):
    print "Case #{}: {}".format(i+1,values[i])

def main(argv):
  fname = argv[1]
  lines = open(fname).readlines()
  T = int(lines[0])
  #print T
  results = solver(T, lines[1:])
  output(T, results)


def ints(line):
  return [int(x) for x in line.split(' ')]

def solve(case):
  n, x, y = ints(case)
  t = triangular(n)
  s = abs(x) + y
  if s <= t-1: return 1.0
  if s > t-1 and n == t*(t+1)/2: return 0.0
  filled, total, height = n-t*(t+1)/2, (t+2)*(t+3)/2-t*(t+1)/2, y
  if height*2+1==total:
    print height*2+1, total
    return 0.0
  z = probs((total-1)/2, filled, height)
  idx = height - filled + (total+1)/2
  if idx < 0: idx = 0
  print z, idx, sum(z[idx:])
  print "{}/{}, {}".format(filled, total-1, height)
  return sum(z[idx:])
  

def solver(T, lines):
  ret = []
  for i in range(0, T):
    ret += [solve(lines[i])]
  return ret

def probs(n, m, h):
  p0 = []
  for i in range(0, n):
    p0.append(0)
  p0.append(1)
  for i in range(0, n):
    p0.append(0)
 
  for i in range(0, m):
    p0 = iterate(p0)
  return p0

def iterate(probs):
  p0 = []
  for i in range(0, len(probs)-1):
    p0.append((probs[i+1]+probs[i])/2.)
  p0[0] += probs[0]/2.
  p0[-1] += probs[-1]/2.
  return p0



if __name__ == '__main__':
  main(sys.argv)
  probs(2, 2, 0)
  probs(2, 3, 0)

