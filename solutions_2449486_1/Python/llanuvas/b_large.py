from __future__ import division
import sys
#import psyco
#psyco.full()
range = xrange

debug = False
def main():
  global infile
  global out_file
  global debug
  in_filename = sys.argv[1]
  out_filename = sys.argv[2]
  if len(sys.argv)>=4:
    debug = True
  in_file = open(in_filename, 'r')
  out_file = open(out_filename, 'w')

  t = get_next_int(in_file)

  results = []
  for step in range(int(t)):
    n, m = get_nexts_int(in_file)
    lawn = [get_nexts_int(in_file) for i in range(n)]
    answer = solve_small(lawn,n,m)
    results.append(answer)
  print_out(results, out_file,debug)
def solve_small(expected_lawn,n,m):
    actual_lawn = [["2" for c in range(m)] for r in range(n)]
    
    
    for r in range(n):
      max_height = max(expected_lawn[r])
      for c in range(m):
        if actual_lawn[r][c] > max_height:
          actual_lawn[r][c] = max_height
    
    turned_expected_lawn = turn(expected_lawn, n, m)
    
    turned_actual_lawn = turn(actual_lawn, n, m)
    
    for r in range(m):
      max_height = max(turned_expected_lawn[r])
      for c in range(n):
        if turned_actual_lawn[r][c] > max_height:
          turned_actual_lawn[r][c] = max_height
    
    if debug:
      print n,m
      print turned_expected_lawn
      print turned_actual_lawn
      print ""
    if tuple([tuple(lawn) for lawn in turned_expected_lawn]) == tuple([tuple(lawn) for lawn in turned_actual_lawn]):
      return "YES"
    return "NO"
 
def cross(board):
  right_down = "".join([board[r][r] for r in range(4)])
  right_up = "".join([board[3-r][r] for r in range(4)])
  return [right_up,right_down]
def turn(lawn, n, m):
  return [[lawn[r][c] for r in range(n)] for c in range(m)]
  

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
    out_file.write("Case #%d: %s\n" % (num, result ))


if __name__ == '__main__':
  main()
