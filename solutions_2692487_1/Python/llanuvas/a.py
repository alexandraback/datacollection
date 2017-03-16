#coding:utf8
from __future__ import division
import sys
import psyco
psyco.full()
from benchmarker import Benchmarker

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
  global dp
  with bm('process'):
    T = get_next_int(in_file)
    
    results = []
    for step in xrange(int(T)):
      a, n = get_nexts_int(in_file)
      motes = get_nexts_int(in_file)
      dp = {}
      answer = solve(a, tuple(sorted(motes)))
      results.append(answer)
    print_out_int(results, out_file,debug)

def check(a,motes):
  my_mote = a
  for mote in motes:
    if mote < my_mote:
      my_mote += mote
    else:
      return False
  return True
dp = {}
def solve(a, motes):
  if (a,motes) in dp:
    return dp[(a,motes)]
  if a <= 1:
    dp[(a,motes)] = len(motes)
    return len(motes)
  my_mote = a
  for i, mote in enumerate(motes):
    if mote < my_mote:
      my_mote += mote
    else:
      dp[(a,motes)] = min(solve(a, motes[:i] + tuple([my_mote-1]) + motes[i:])+1,len(motes[i:]))
      return dp[(a,motes)]
  dp[(a,motes)] = 0
  return 0


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
