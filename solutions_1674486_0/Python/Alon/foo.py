#!/usr/bin/python
import sys

def visit(curr, l, visited):
  for j in l[curr]:
    if visited[j]:
      return True
    visited[j] = True
    if visit(j,l,visited):
      return True
  return False

def calc(l):
  for i in xrange(len(l)):
    visited = [False]*len(l)
    visited[i] = True
    if visit(i, l, visited): 
      return "Yes"
  return "No"

def main():
  d = file(sys.argv[1]).readlines()
  T = int(d[0])
  curr_line = 1
  for j in xrange(1, T+1):
    n = int(d[curr_line])
    curr_line += 1
    l = []
    for k in xrange(n):
      l.append([int(x)-1 for x in d[curr_line].split(' ')][1:])
      curr_line += 1
    print "Case #%d: %s" % (j, calc(l))
main()
