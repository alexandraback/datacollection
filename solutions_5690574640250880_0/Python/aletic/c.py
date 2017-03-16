n = int(raw_input())

import sys
import Queue
#only goes up and left
def ff(squares, mat, x, y):
  q = Queue.Queue()
  o_squares = squares
  q.put( (x,y) )
  while squares > 0:
    x,y = q.get()
    if squares == 0: break
    if x < 0 or y < 0: continue
    if mat[y][x] == ' ':
      mat[y][x] = '*'
      squares -= 1 #what we filled
      q.put( (x-1, y) )
      q.put( (x, y-1) )
      #squares = ff(squares, mat, x - 1, y)
      #squares = ff(squares, mat, x, y -1)

  #smooth the output  edge/corner
  r = len(mat)
  c = len(mat[0])
  if r * c / 2 < o_squares:
    x = 0
    try:
      while mat[0][x] != '*': x += 1  #find first mine in row 0
      y = 0
      while mat[y][0] != '*': y += 1  # find first mine in col 0
      mat[y-1][1] = ' '
      mat[0][x-1] = '*'
    except:
      pass
    
  return squares

def try_fill(x,y, mat, r, c):
  # only goes down and right
  if mat[y][x] == '*': return 0
  if mat[y][x] == '.': return 0
  mat[y][x] = '.'
  count = 1
  check = [(-1,0), (1,0), (0,-1), (0, 1), (-1, -1), (1,1), (-1, 1), (1, -1)]
  for dx, dy in check:
    nx = x+dx
    ny = y+dy
    if nx >= 0 and nx < c and ny >= 0 and ny < r:
      if mat[ny][nx] == '*': return count #don't fill if it is adjacent to a mine
  

  if y < r - 1 :
    count += try_fill(x, y + 1, mat, r, c)
  if x < c - 1:
    count += try_fill(x + 1, y, mat, r, c)
  if y < r -1 and x < c - 1:
    count += try_fill(x + 1, y + 1, mat, r, c)
  return count


for test in xrange(1,n+1):
  r, c, m = map(int, raw_input().split())
  mat = [[' '] * c for i in xrange(r)]
  
  squares = r * c
  ff(m, mat, c-1, r-1)
  #print '----'
  #for row in mat:
  #  print ''.join(row)
  
  
  count =  try_fill(0, 0, mat, r, c)
  
  mat[0][0] = 'c'

  print 'Case #{}:'.format(test)
  if m + count == squares:
    for row in mat:
      print ''.join(row)
  else:
    print 'Impossible'