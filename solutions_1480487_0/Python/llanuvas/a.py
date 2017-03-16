from __future__ import division
import sys
import psyco
#psyco.full()
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
  with bm('process'):
    t = get_next_int(in_file)

    results = []
    for step in xrange(int(t)):
      input = get_nexts_int(in_file)
      n, numbers = input[0], input[1:]
      total = sum(numbers)
      ave = (total * 2) / n
      base = n
      subtotal = (total * 2)
      ave = (subtotal ) / base
      new_base = n
      new_subtotal = subtotal
      for i, number in enumerate(numbers):
        if number > ave:
            new_base -= 1
            new_subtotal -= number
      if base <= new_base:
          pass
      else:
          base = new_base
          subtotal = new_subtotal
          print base
      print step,n, base,ave
      ave = subtotal / base
      answer = []
      needs = []
      for i, number in enumerate(numbers):
        
        need = ( ave - number ) * 100
        if need >= 0:
            answer.append( "%.6f" % (need/total) )
        else:
            answer.append( "%.6f" % 0.0 )
      results.append(" ".join(answer))
    print_out_int(results, out_file,debug)
    
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
