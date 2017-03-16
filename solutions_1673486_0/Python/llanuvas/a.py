from __future__ import division
import sys
import psyco
#psyco.full()

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

  t = get_next_int(in_file)

  results = []
  for step in xrange(int(t)):
    a, b = get_nexts_int(in_file)
    probablies = get_nexts_float(in_file)
    
    answer = solve(a,b,probablies)
    results.append(answer)
  print_out_int(results, out_file,debug)
def solve(a,b,probablies):
    min_excepted = b + 2
    total_probably = 1
    for p in probablies:
        total_probably *= p
    if total_probably == 1:
        return b - a + 1
    
    total_probably = 1
    for i, p in enumerate(probablies):
        total_probably *= p
        min_stroke = (b - a + 1 + (a-i-1)*2)
        retry_stroke = b+1
        if_all_ok = total_probably * min_stroke
        if_mistake_already = (1-total_probably) * (min_stroke + retry_stroke)
        combination = 2 ** (a+i)
        excepted = if_all_ok + if_mistake_already
        print a,b,i,excepted
        min_excepted = min(min_excepted,excepted)
    print min_excepted
    return min_excepted






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
