#!/usr/bin/python3
import sys
import math
import fractions
from array import array

def rl(convert=''):
  line = sys.stdin.readline().split()
  for i,c in enumerate(convert):
    if c=='i':
      line[i]=int(line[i])
    elif c=='s':
      pass
    elif c=='f':
      line[i]=float(line[i])
  if len(line)==1:
    return line[0]
  return line

def gcd(*args):  
  if len(args)==0:
    return 0
  g = args[0]
  for i in range(1,len(args)):
    g = fractions.gcd(g,args[i])    
  return g

def lcm(*args):
  if len(args)==0:
    return 0
  g = args[0]
  for i in range(1,len(args)):
    g *= args[i]  
  return g/gcd(*args)


#--------------------------------------------------------------------#

def getCnt(interval, start, end):
  s = (interval[0]-start+1)*(end-interval[1]+1)
  return s

def mergeIntervals(intervals):
  newintervals = list()
  for i in range(len(intervals)-1):
    newintervals.append((intervals[i][0], intervals[i+1][1]))
  return newintervals

def cntIntervals(intervals, length):
  s = 0
  start = 0
  for i in intervals:
    s+=getCnt(i,start,length)
    start = i[0]+1
  return s

samohlasky = set("aeiou")

tt = rl('i')

for t in range(1,tt+1):
  s,n = rl('si')
  # l = list()
  # ls = list()
  intervals = list()
  p = 0
  start = -1
  for i in range(len(s)):
    if s[i] in samohlasky:
      p = 0      
      start = i
    else:
      p+=1
    # l.append(p)
    # ls.append(start)
    if p>=n:
      intervals.append((start+1+p-n,start+1+p))
  # print l
  # print ls
  # print intervals

  sm = 0
  # z = -1
  # while len(intervals)>0:
    # z*=-1
  sm+=cntIntervals(intervals,len(s))    
  # intervals = mergeIntervals(intervals)
  # sm-=cntIntervals(intervals,len(s))

  print "Case #%(t)d: %(r)d" % {"t":t, "r":sm}
  


  
