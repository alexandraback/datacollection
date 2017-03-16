import sys 
import string
from collections import *
import itertools

def intersect(a, b):
	return list(set(a) & set(b))

def countchars(a):
 d = {}
 for i in xrange(0, len(a)):
  if a[i] in d:
   d[a[i]] += 1
  else:
   d[a[i]] = 1
 return d

def makestrings(d):
 strings = []
 for x in d.keys():
  strings.append(x * d[x])
 return strings

f = open(sys.argv[1])

T = int(f.readline())
for c in xrange(1, T+1): 
 N = int(f.readline())
 cars = f.readline().strip().split()
 #print N
 cars = list(map("".join, itertools.permutations(cars)))
 dic = countchars(cars[0])
 #print dic
 #print cars
 rps = makestrings(dic)
 n = 0
 for strg in cars:
  good = True
  for rpt in rps: 
   if not rpt in strg:
    good = False
    break;
  if good:
   n += 1

 print 'Case #' + str(c) + ': ' + str(n)
	
#you get cookies continuously so 0.1s after start you have 0.2 cookies. you have production * time cookies. 

#while the amount of time taken to buy a farm and then get to C cookies is faster than the time taken to just get to C cookies, buy anohter farm 




