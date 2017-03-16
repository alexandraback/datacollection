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
    a, b = get_nexts_int(in_file)
    answer = solve(a,b)
    results.append(str(answer))
  print_out(results, out_file,debug)

def is_palindrome(number):
    s = str(number)
    return s == "".join(reversed(s))

def check(number):
  if is_palindrome(number):
    if is_palindrome(number**2):
      return True
  return False

def solve(a,b):
  count = 0
  for i in xrange(b+1):
    if (i ** 2) > b:
      break
    if a <= (i ** 2):
      if check(i):
        count += 1
  return count
 
def cross(board):
  right_down = "".join([board[r][r] for r in range(4)])
  right_up = "".join([board[3-r][r] for r in range(4)])
  return [right_up,right_down]
def turn(board):
  return ["".join([board[r][c] for r in range(4)]) for c in range(4)]
  

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
