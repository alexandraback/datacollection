#coding:utf8
#from __future__ import division
import sys
import psyco
psyco.full()
from benchmarker import Benchmarker
from math import sqrt

def main():
  global infile
  global out_file
  debug = False
  in_filename = sys.argv[1]
  out_filename = sys.argv[2]
  if len(sys.argv)>=4:
    debug = True
  in_file = open(in_filename, 'r')
  out_file = open(out_filename, 'w')
  bm = Benchmarker()
  #if 1:
  with bm('process'):
    T = get_next_int(in_file)
    
    results = []
    for step in xrange(int(T)):
      r, t = get_nexts_int(in_file)
      answer = solve(r, t)
      results.append(answer)
    print_out_int(results, out_file,debug)

def solve(r, t):
  remains = t
  answer= 0
  first = (r+1) ** 2 - r ** 2
  
  size = t
  current = int(size / 2)

  #print first, size, current
  i = 0
  n ,m = divmod(size,2)
  size = n + m
  l,current , h  = 0,t/2,t
  #print l, current , h,(h-l)
  while (h - l) > 1:
    
    score = calc(first,current)
    #print i, l,current,h,score,score < t
    if score <= t:
      n, m = divmod(current+h,2)
      l,current,h = current,n,h
    else:
      n, m = divmod(l+current,2)
      l,current,h = l,n,current
      
    #print i, l,current,h
    
    i += 1
  
  return current
def calc(first , current):
  return (first * 2 + (current-1) * 4) * (current) / 2
  
def get_first(num):
    return (num+1) **2 - num ** 2 
def get_next(f):
  line = f.readline()
  return line.rstrip('\n')
def get_nexts(f):
  line = f.readline()
  return line.rstrip('\n').split(" ")

def get_next_int(f):
    return int(get_next(f))

def get_nexts_int(f):
    return map(int, get_nexts(f))
def get_nexts_float(f):
    return map(float, get_nexts(f))
    
def get_nexts_digit(f):
    return map(int, list(get_next(f)))

def print_out(results, out_file, debug=False):
  for i, result in enumerate(results):
    num = i + 1
    print >>out_file, "Case #%d:\n%s" % (num, result )
    if debug:
        print "Case #%d:\n%s" % (num, result )
def print_out_int(results, out_file,debug=False):
  for i, result in enumerate(results):
    num = i + 1
    print >>out_file, "Case #%d: %s" % (num, result )
    if debug:
        print "Case #%d: %s" % (num, result )
    #print  "Case #%d: %s" % (num, result)

if __name__ == '__main__':
  main()
