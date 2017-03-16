'''
Created on 12/apr/2014

@author: mlarocca
'''
from sys import argv
from copy import  deepcopy
from json import dumps

CLICK_MARK = "c"

def check_minefield(r, c, m, M):
  
  m_count = 0
  dist = [[0] * c for _ in xrange(r)]
  
  for i in xrange(r):
    for j in xrange(c):
      if M[i][j] == '*':
        m_count += 1
        continue
      
      neighbours = filter(lambda (x,y) : 0 <= x < r and 0 <= y < c, [(i-1, k) for k in [j-1, j, j+1]] + [(i, k) for k in [j-1, j+1]] + [(i+1, k) for k in [j-1, j, j+1]])
      tmp = 0
      for (x,y) in neighbours:
        if M[x][y] == '*':
          tmp += 1
      dist[i][j] = tmp

  assert(m_count == m)

  def visit((i,j), visited):
    if visited[i][j] or M[i][j] == "*":
      return
    visited[i][j] = 1
    if dist[i][j] == 0:
      neighbours = filter(lambda (x,y) : 0 <= x < r and 0 <= y < c, [(i-1, k) for k in [j-1, j, j+1]] + [(i, k) for k in [j-1, j+1]] + [(i+1, k) for k in [j-1, j, j+1]])
      for (x,y) in neighbours:
        visit((x, y), visited)

  for i in xrange(r):
    for j in xrange(c):
      if M[i][j] != '*':
        visited = [[0] * c for _ in xrange(r)]
        visit((i,j), visited)
    
        if sum([sum(row) for row in visited]) == r * c - m:
          return (i,j), True
  else:
    return None, False
  
def list_to_string_field(M, cx, cy):
  M = map(lambda row: ''.join(row), M)
  M[cx] = M[cx][:cy] + CLICK_MARK + M[cx][cy+1:]
  return M

def trasposed_string_field(r, c, M):
  return [''.join([M[j][i] for j in xrange(r)]) for i in xrange(c)]
  

def make_key(r, c, m):
  return "%d %d %d" % (r, c, m)

def generate_all_valid_inputs(max_side):
  def generate_fields(valids, M, r, c, m, i, j):
    if i >= r:
      return
    
    #print r, c, m, i, j

    j1 = j + 1
    if j1 == c:
      i1 = i + 1
      j1 = 0
    else:
      i1 = i

    generate_fields(valids, deepcopy(M), r, c, m, i1, j1)
            
    M[i][j] = '*'
    m += 1
    
    key = make_key(r, c, m)
    if not key in valids: 
      c_pos, v = check_minefield(r, c, m, M)
      if v:
        valids[key] = list_to_string_field(M, *c_pos)
        if r != c:
          rev_key = make_key(c, r, m)
          valids[rev_key] = trasposed_string_field(r, c, valids[key])
  
    generate_fields(valids, deepcopy(M), r, c, m, i1, j1)


    
    
  valids = {}
  for r in xrange(1, max_side+1):
    for c in xrange(r+1 ,max_side+1):
      #print r, c
      M = [['.'] * c for _ in xrange(r)]
      key = make_key(r, c, 0)
      valids_key = list_to_string_field(M, 0, 0)
      valids[make_key(c, r, 0)] = trasposed_string_field(r, c, valids_key)
      #generate_fields(valids, M, r, c, 0, 0, 0)
      
  return dumps(valids)
  
if __name__ == '__main__':
  print generate_all_valid_inputs(int(argv[1]))
