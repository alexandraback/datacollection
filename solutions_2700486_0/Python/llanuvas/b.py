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
  with bm('process'):
    t = get_next_int(in_file)
    
    results = []
    for step in xrange(int(t)):
      n, x, y = get_nexts_int(in_file)
      answer = solve(n, 0,0,0, x, y,1.0)
      results.append("%0.7f" % answer)
    print_out(results, out_file,debug)


def check(left,center,right,  x, y):
  positions = {}
  for i in xrange(center):
    positions[(-1,i*2)] = 1
    positions[(1,i*2)] = 1
    positions[(0,i*2)] = 1
    positions[(0,i*2+1)] = 1
  x_index = 1
  y_index = 0
  for i in xrange(left):
    positions[(-1 + x_index*-2 +y_index,y_index)] = 1
    positions[(x_index*-2+y_index,y_index)] = 1
    positions[(x_index*-2+y_index,y_index+1)] = 1
    y_index += 1
    if y_index >= x_index * 2:
      y_index = 0
      x_index += 1
  x_index = 1
  y_index = 0
  for i in xrange(right):
    positions[(-1 + x_index*2-y_index,y_index)] = 1
    positions[(x_index*2-y_index,y_index)] = 1
    positions[(x_index*2-y_index,y_index+1)] = 1
    y_index += 1
    if y_index >= x_index * 2:
      y_index = 0
      x_index += 1
  return ( x, y ) in positions

    

def solve(n, left,center,right,  x, y,probably):
  if n == 0:
    if check(left,center,right,  x, y):
      return probably
    return 0.0
  leftable = left < (center * (center+1))
  rightable = right < (center * (center+1))
  if not leftable and not rightable:
    return solve(n-1,left,center+1,right,x,y,probably)
  if leftable and not rightable:
    return solve(n-1,left+1,center,right,x,y,probably)
  if not leftable and rightable:
    return solve(n-1,left,center,right+1,x,y,probably)  
  answer = 0
  answer += solve(n-1,left+1,center,right,x,y,probably*0.5)
  answer += solve(n-1,left,center,right+1,x,y,probably*0.5)
  return answer
  
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
    print >>out_file, "Case #%d: %s" % (num, result )
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
