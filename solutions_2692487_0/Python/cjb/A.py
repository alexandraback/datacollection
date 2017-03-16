#!/usr/local/bin/python2.7
import sys

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

def attempt(Armin, motes):
  ct = 0
  for x in motes:
    if x < Armin:
      Armin += x
      ct += 1
  return (Armin, motes[ct:])

def solve(case):
  Armin, n = ints(case[0])
  motes = sorted(ints(case[1]))
  #print Armin, n, ':', attempt(Armin, motes)
  #print motes
  z = attempt(Armin, motes)
  nn = len(z[1])
  print "Reduced to:", z[0], z[1]
  if z[0] == 1:
    return len(motes)
  if nn <= 1:
    return nn
  return resolve(z[0], z[1])

def resolve(Armin, motes):
  maxbound = len(motes)
  ct = 0
  while len(motes) > 0:
    while Armin <= motes[0]:
      ct += 1
      Armin = 2*Armin-1
    Armin, motes = attempt(Armin, motes)
    nn = len(motes)
    maxbound = min(maxbound, ct+nn)
    if nn == 0:
      return maxbound

def solver(T, lines):
  ret = []
  for i in range(0, T):
    ret += [solve(lines[i*2:i*2+2])]
  return ret


if __name__ == '__main__':
  main(sys.argv)


