#!/usr/bin/env python

import sys
import math
import Queue as q

lib = {} #mutable globals just in case
lst = []

if (len(sys.argv) != 3):
  print "You need 3 args including the file name"

linesPerTest = int(sys.argv[2])

def retOpen(tnum):
  return "Case #" + str(tnum) + ":"

def runTest(t,lines,output):
  test = lines[0]
  res = test[0]
  for a in test[1:-1]:
    if ord(a) >= ord(res[0]):
      res = a + res
    else:
      res = res + a
  ret = retOpen(t) + " " + res + "\n"
  output.write(ret)
  print ret

with open(sys.argv[1],"r") as file1, open("/home/codetaku/Downloads/output","w") as file2:
  testCase = 1
  lines = file1.readlines()
  numTests = int(lines[0])
  lineno = 1
  while (testCase <= numTests):
    if (linesPerTest > 0):
      runTest(testCase,lines[lineno:lineno + linesPerTest],file2)
      lineno += linesPerTest
    else:
      thisTestLines = int(lines[lineno].split(" ")[0]) + 1
      runTest(testCase,lines[lineno:lineno + thisTestLines],file2)
      lineno += thisTestLines
    testCase += 1






