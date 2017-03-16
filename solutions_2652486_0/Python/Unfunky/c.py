#!/usr/bin/python -u

import sys,re

if len(sys.argv) != 2:
  print "usage: " + sys.argv[0] + " infile"
  sys.exit()
infile = open(sys.argv[1], 'r')

debugprint = 0

def debug(str, lvl=5):
  if debugprint > lvl: print "[DEBUG]", str

def prime_factorization(n):
  rsp = { 2 : 0, 3 : 0, 5 : 0, 7 : 0 }
  while n != 1:
    if float(n)/2 == int(n)/2:
      rsp[2] = rsp[2] + 1
      n = n/2
    if float(n)/3 == int(n)/3:
      rsp[3] = rsp[3] + 1
      n = n/3
    if float(n)/5 == int(n)/5:
      rsp[5] = rsp[5] + 1
      n = n/5
    if float(n)/7 == int(n)/7:
      rsp[7] = rsp[7] + 1
      n = n/7
  return rsp


def handleonesubcase(N,M,K):
  rsp = ''
  num_2s = 0
  num_3s = 0
  num_5s = 0
  num_7s = 0
  for k in K:
    f = prime_factorization(k)
    num_2s = max(num_2s, f[2])
    num_3s = max(num_3s, f[3])
    num_5s = max(num_5s, f[5])
    num_7s = max(num_7s, f[7])
  if(num_3s == 3): return '333'
  if(num_5s == 3): return '555'
  if(num_2s == 6): return '444'
  if(num_3s == 2 and num_2s == 2): return '334'
  if(num_5s == 2 and num_2s == 2): return '554'
  if(num_5s == 1 and num_2s == 4): return '445'
  if(num_3s == 1 and num_2s == 4): return '344'
  if(num_3s == 1 and num_2s == 3): return '234'
  if(num_5s == 1 and num_2s == 3): return '245'
  if(num_3s == 2 and num_2s == 1): return '233'
  if(num_3s == 1 and num_2s == 2): return '223'
  if(num_5s == 2 and num_2s == 1): return '255'
  if(num_5s == 1 and num_2s == 2): return '225'
  if(num_5s == 2 and num_3s == 1): return '355'
  if(num_5s == 1 and num_3s == 2): return '335'
  if(num_5s == 1 and num_3s == 1 and num_2s == 1): return '235'
  if(num_2s == 2 and num_3s == 1 and num_5s == 1):
    return '345'
  if(num_2s == 1 and num_3s == 1 and num_5s == 1):
    return '235'
  if(num_2s == 2 and num_3s == 1):
    return '223'
  if(num_2s == 2 and num_5s == 1):
    return '225'
  if(num_2s == 1 and num_3s == 1):
    return '223'
  if(num_2s == 1 and num_5s == 1):
    return '225'
  if(num_3s == 1 and num_5s == 1):
    return '335'
  if(num_3s == 1):
    return '333'
  if(num_5s == 1):
    return '555'
  debug(num_2s)
  debug(num_3s)
  debug(num_5s)
  debug(num_7s)
  return '222'

def handleonecase(line1):
  R = long(line1[0])
  N = long(line1[1])
  M = long(line1[2])
  K = long(line1[3])
  for i in range(R):
    line2 = infile.readline().strip().split()
    K = []
    for i in line2:
      K.append(long(i))
    print handleonesubcase(N,M,K)
  return

maxcases = 0
casenum = 0

line = infile.readline().strip()
maxcases = int(line)
print "Case #1:"
while line:
  casenum = casenum + 1
  if casenum > maxcases: break
  line1 = infile.readline().strip().split()
#  line2 = infile.readline().strip().split()
  result = handleonecase(line1)
#  print "Case #" + str(casenum) + ": " + str(result)




