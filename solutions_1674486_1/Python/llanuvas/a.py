from __future__ import division
import sys
import psyco
psyco.full()
from benchmarker import Benchmarker
from copy import deepcopy

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
  with bm('process'):
    t = get_next_int(in_file)

    results = []
    for step in xrange(int(t)):
      n = get_next_int(in_file)
      inherits = {}
      for i in xrange(n):
        line = get_nexts_int(in_file)
        if line[0] > 0:
            m , inherit = line[0], line[1:]
            inherits[i+1] = inherit
        else:
            inherits[i+1] = []
      answer = "No"
      dp = {}
      for i in xrange(n):
        if not i+1 in dp:
          b, all = is_diamond_inherits(i+1,inherits,dp)
          if b:
              answer = "Yes"
      results.append(answer)
    print_out_int(results, out_file,debug)
def is_diamond_inherits(num,inherits,dp):
    
    all = {}
    search = []
    for s in inherits[num]:
        search.append(s)
        all[s] = True
    while search:
        v = search.pop(0)
        v_inherits = inherits[v]
        for v_inherit in v_inherits:
            if v_inherit in all:
                return True, None
            else:
                search.append(v_inherit)
                all[v_inherit] = True
    for v in all:
        dp[v] = True
    return False,all.keys()
    
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
