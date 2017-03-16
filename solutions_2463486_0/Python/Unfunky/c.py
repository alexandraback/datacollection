#!/usr/bin/python -u

import sys,re

if len(sys.argv) != 2:
  print "usage: " + sys.argv[0] + " infile"
  sys.exit()
infile = open(sys.argv[1], 'r')

debugprint = 10

def debug(str, lvl=5):
  if debugprint > lvl: print "[DEBUG]", str

def handleonecase(a,b):
  t = all_fair_and_squares_below_100000000000000()
  return len([i for i in t if (i >= a and i <= b)])

maxcases = 0
casenum = 0

#line = infile.readline().strip()
#maxcases = int(line)
#while line:
#  casenum = casenum + 1
#  if casenum > maxcases: break
#  line1 = infile.readline().strip().split()
#  a = int(line1[0])
#  b = int(line1[1])
#  result = handleonecase(a,b)
#  print "Case #" + str(casenum) + ": " + str(result)

def mk_p(i,odd_even):
  s = str(i)
  if odd_even == 'odd':
    sp = int(s + s[-2::-1])
    return sp
  return int(s + s[::-1])

def is_p(i):
  s = str(i)
  for i in range(len(s)):
    if s[i] != s[-1-i]: return False
  return True

def generate_fair_and_squares(upper_limit):
  good = []
  i = 0
  while True:
    i = i + 1
    p = mk_p(i,'odd')
    square = pow(p,2)
    if square > upper_limit: break
    if is_p(square): good.append(square)
  i = 0
  while True:
    i = i + 1
    p = mk_p(i,'even')
    square = pow(p,2)
    if square > upper_limit: break
    if is_p(square): good.append(square)
  good.sort()
  return good

def all_fair_and_squares_below_100000000000000():
  return [1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004]

line = infile.readline().strip()
maxcases = int(line)
while line:
  casenum = casenum + 1
  if casenum > maxcases: break
  line1 = infile.readline().strip().split()
  a = int(line1[0])
  b = int(line1[1])
  result = handleonecase(a,b)
  print "Case #" + str(casenum) + ": " + str(result)
  




