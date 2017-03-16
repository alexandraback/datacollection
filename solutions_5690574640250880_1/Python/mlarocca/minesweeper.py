'''
Created on 12/apr/2014

@author: mlarocca
'''
from sys import argv
from math import sqrt
from copy import  deepcopy

CLICK_MARK = "c"

def read_input(f):
  lines = open(f, 'r')
  n = int(lines.readline().strip())
  for i in xrange(n):
    r, c, m = map(int, lines.readline().strip().split(" "))
    
    yield i+1, r, c, m

def check_solution(r, c, m, M):
  assert(len(M) == r)
  for i in xrange(r):
    assert (len(M[i]) == c)
  
  m_count = 0
  c_count = 0
  dist = [[0] * c for _ in xrange(r)]
  visited = [[0] * c for _ in xrange(r)]

  for i in xrange(r):
    for j in xrange(c):
      if M[i][j] == '*':
        m_count += 1
        continue
      if M[i][j] == CLICK_MARK:
        c_count += 1
        c_pos = (i,j)
      
      neighbours = filter(lambda (x,y) : 0 <= x < r and 0 <= y < c, [(i-1, k) for k in [j-1, j, j+1]] + [(i, k) for k in [j-1, j+1]] + [(i+1, k) for k in [j-1, j, j+1]])
      tmp = 0
      for (x,y) in neighbours:
        if M[x][y] == '*':
          tmp += 1
      dist[i][j] = tmp

  def visit((i,j), visited):
    if visited[i][j] or M[i][j] == "*":
      return
    visited[i][j] = 1
    if dist[i][j] == 0:
      neighbours = filter(lambda (x,y) : 0 <= x < r and 0 <= y < c, [(i-1, k) for k in [j-1, j, j+1]] + [(i, k) for k in [j-1, j+1]] + [(i+1, k) for k in [j-1, j, j+1]])
      for (x,y) in neighbours:
        visit((x, y), visited)
  
  assert (c_count == 1)
  assert (m_count == m)
  
  visit(c_pos, visited)
  print "\n".join([" ".join(map(str, visited[i])) for i in xrange(r)])
  print "\n".join([" ".join(map(str, dist[i])) for i in xrange(r)])
  
  assert (sum([sum(row) for row in visited]) == r * c - m)
    


def simulate(r, c, m):
  n = r * c
  free_cells = n - m
  sqrt_fc = int(sqrt(free_cells))
  if m == n - 1:
    res = ["*" * c for _ in xrange(r-1)]
    res.append("*" * (c-1) + CLICK_MARK)
    return res
  if r == 1:
    return [ ("*" * m + '.' * (free_cells - 1)) + CLICK_MARK]
  elif c == 1:
    return (["*"] * m) + (['.'] * (free_cells - 1)) + [CLICK_MARK]
  #elif sqrt_fc < 2:
  #  return None
  else:
    if c < r:
      reverse = c
      c = r
      r = reverse
    else:
      reverse = 0
        
    size = c
    for i in xrange(c, max(1, sqrt_fc - 1), -1):
      n_rows = free_cells / i
      left = free_cells - n_rows * i      
      if left != 1 and n_rows > 1:
        size = i 
        break
    
    n_rows = free_cells / size
    left = free_cells - n_rows * size
    #print r, c, size, n_rows, left, free_cells
    while left == 1 and size > 0:
      size -= 1
      n_rows = free_cells / size
      left = free_cells - n_rows * size
    #print r, c , n_rows, sqrt_fc ,size, left, free_cells
    if size == 0 or n_rows > r or n_rows <= 1:
      
      if m <= n / 2:
        
        size = c
        for i in xrange(c, max(1, sqrt_fc - 1), -1):
          n_rows = m / i
          left = m - n_rows * i      
          if size != c-1 and left != c-1 and n_rows < c - 1:
            size = i 
            break    
        n_rows = m / size
        left = m - n_rows * size
        #print r, c, size, n_rows, left, free_cells
        while (left == c-1 or size == c-1) and size > 0:
          size -= 1
          if size == 0:
            break
          n_rows = m / size
          left = m - n_rows * size
        #print size, n_rows
        if size == 0 or size == c-1 or (n_rows + (1 if left != 0 else 0)) >= r - 1 or n_rows < 1:
          return None
        if left == 0:
          res = ["." * (c - size) + "*" * size for _ in xrange(n_rows)]
        else:
          res = ["." * (c - size) + "*" * size for _ in xrange(n_rows)]
          res.insert(0, '.' * (c - left) + ("*" * left))
          
        while len(res) < r - 1:
          res.insert(0, "." * c)
        res.insert(0, CLICK_MARK + "." * (c-1))        
        if reverse > 0:
          return [''.join([res[j][i] for j in xrange(r)]) for i in xrange(c)]
        else: 
          return res
      else:
        return None                     
    if left == 0:
      res = ["." * size + "*" * (c - size) for _ in xrange(n_rows-1)]
      res.insert(0, CLICK_MARK + ("." * (size-1))  + ("*" * (c - size)))
    else:
      res = ["." * size + "*" * (c - size) for _ in xrange(n_rows - 1)]
      res.insert(0, CLICK_MARK + "." * (size-1) + "*" * (c - size))
      res.append('.' * left + ("*" * (c - left)))
    while len(res) < r:
      res.append("*" * c)  
    
    if reverse > 0:
      return [''.join([res[j][i] for j in xrange(r)]) for i in xrange(c)]
    else: 
      return res       
   
def simulate_and_check_all(r, c, m):
  n = r * c
  free_cells = n - m

  if c < r:
    reverse = c
    c = r
    r = reverse
  else:
    reverse = 0

  for size in xrange(c, 1, -1):
    n_rows = free_cells / size
    left = free_cells - n_rows * size
    #print r, c , n_rows, sqrt_fc ,size, left, free_cells
    if size > 0 and 0 <= n_rows <= r:

      if left == 0:
        res = ["." * size + "*" * (c - size) for _ in xrange(n_rows-1)]
        res.insert(0, CLICK_MARK + ("." * (size-1))  + ("*" * (c - size)))
      else:
        res = ["." * size + "*" * (c - size) for _ in xrange(n_rows - 1)]
        res.insert(0, CLICK_MARK + "." * (size-1) + "*" * (c - size))
        res.append('.' * left + ("*" * (c - left)))
      while len(res) < r:
        res.append("*" * c)  
  
      if reverse > 0:
        return [''.join([res[j][i] for j in xrange(r)]) for i in xrange(c)]
      print "\n".join(res)
      try:
        check_solution(r, c, m, res)
        raise Exception
      except AssertionError:
        print "checked"
        pass
      
  
if __name__ == '__main__':

  for test_case, r, c , m in read_input(argv[1]):
    print "Case #%d:" % test_case
    res = simulate(r, c, m)
    if res is None:
      #simulate_and_check_all(r, c, m)
      print "Impossible"
    else:
      '''try:
        check_solution(r, c, m, res)
      except AssertionError as e:
        print r,c,m
        print "\n".join(res)
        check_solution(r, c, m, res)'''
      print "\n".join(res)

