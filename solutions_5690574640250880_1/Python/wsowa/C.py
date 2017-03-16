#!/usr/bin/env python

import sys

def get_one_line_field(r,c,m):
  if r*c <= m: return None
  elif r==1: return [[ '.' for i in xrange(c-m)] + ['*' for i in xrange(m) ]]
  elif c==1: return [ ['.'] for i in xrange(r-m)] + [ ['*'] for i in xrange(m) ]
  else: return None
  
def get_mine_field(r,c,m):
  w = c-2 if c>2 else 0
  h = r-2 if r>2 else 0
  field = [] 
    
  if w*h > m:
    for j in xrange(r-m/w-1): field.append(['.' for i in xrange(c)])
    field.append(['.' for i in xrange(c-m%w)] + ['*' for i in xrange(m%w)])
    for j in xrange(m/w): field.append(['.' for i in xrange(c-w)] + ['*' for i in xrange(w)])
    return field
  
  for i in xrange(r-h): field.append(['.' for i in xrange(c)])
  for i in xrange(h): field.append(['.' for i in xrange(c-w)]  + ['*' for i in xrange(w)] )

  left = m-w*h
  to_ommit=2
  
  if left %2 == 1 and r > 2 and c > 2:
    left+=1
    field[2][2]='.'
    to_ommit=3
    
  for i in xrange(r-1,to_ommit-1, -1):
    if left == 0: break
    field[i][0:2]=['*']*2
    left -=2
  
  for i in xrange(c-1,to_ommit-1, -1):
    if left == 0: break
    field[0][i]='*'
    field[1][i]='*'
    left -=2
    
  if left+1 == to_ommit**2:
    for i in xrange(to_ommit):
      for j in xrange(to_ommit):
	field[i][j]='*'
    field[0][0] = '.'
    return field
  
  if left != 0: return None
  return field

def make_string(array):
  if array is None: return "Impossible"
  else:
    array[0][0]='c'
    return "\n".join(map(lambda row: "".join(row), array))

def solve(r,c,m):
  if r==1 or c==1: return get_one_line_field(r,c,m)
  else: return get_mine_field(r,c,m)

def __main__():
  cases_no = int(sys.stdin.readline())
  for case_no in xrange(cases_no):
      [R,C,M] = map(int,sys.stdin.readline().split())
    
      print "Case #%d:" % (case_no+1)
      print make_string(solve(R,C,M))

__main__()
