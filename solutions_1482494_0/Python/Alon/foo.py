#!/usr/bin/python
import sys

def ccc(x,y):
  if x[0] != y[0]:
    return x[0] - y[0]
  return y[2] - x[2]

def calc(l):
  first = []
  second = []
  done = [False] * len(l)
  for i,p in enumerate(l):
    first.append([p[0],i, p[1]])
    second.append([p[1],i])
  first.sort(cmp=ccc)
  second.sort(key=lambda x: x[0])
  #print first
  #print second

  levels = 0
  score = 0
  fi = 0
  si = 0
  while True:
    if si > len(second)-1:
      break
    if score >= second[si][0]:
      levels += 1
      #print "s%d" % second[si][1]
      if done[second[si][1]]:
        score += 1
      else:
        score += 2
        done[second[si][1]] = True
      si += 1
      continue
    if fi >= len(first) -1:
      return "Too Bad"
    if score >= first[fi][0]:
      levels += 1
      #print "f%d" % first[si][1] 
      if not done[first[si][1]]:
        score += 1
        done[first[si][1]] = True
      fi += 1
      continue
    return "Too Bad"
  return levels

def main():
  d = file(sys.argv[1]).readlines()
  n = int(d[0])
  currline = 1
  for j in xrange(1, n+1):
    l = []
    N = int(d[currline])
    currline +=1
    for p in xrange(N):
      l.append([int(x) for x in d[currline].split(' ')])
      currline += 1
    print "Case #%d: %s" % (j, calc(l))
main()
