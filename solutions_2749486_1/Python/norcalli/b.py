import sys, random, math

def automain(fn):
  if __name__ == '__main__':
    sys.exit(fn(*sys.argv[1:]))

def int_line(file):
  result = [int(x) for x in file.readline().strip().split()]
  if not result:
    raise Exception("int_line found no ints")
  if len(result) == 1:
    return result[0]
  return result

def memoize(f):
  """ Memoization decorator for functions taking one or more arguments. """
  class memodict(dict):
    def __init__(self, f):
      self.f = f
    def __call__(self, *args):
      return self[args]
    def __missing__(self, key):
      ret = self[key] = self.f(*key)
      return ret
  return memodict(f)

import string

alphabet = string.ascii_lowercase
consonants = ''.join(x for x in alphabet if x not in 'aeiou')

def consonant_count(name, n):
  if len(name) < n:
    return False
  for i in range(len(name) - n+1):
    if all(name[j] in consonants for j in range(i, i+n)):
      return True
  return False

def substrings(string):
  for start in range(len(string)):
    for end in range(start, len(string)):
      yield string[start:end+1]
                            
def powerset(iterable):
  "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
  s = list(iterable)
  return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))


def distance(x, y, nx, ny):
  return math.sqrt((x-nx)**2 + (y-ny)**2)

# @memoize
# def Branch(n, pd, x, y, gx, gy, result):
#   if n > 500:
#     return 501, []
#   if x == gy and y == gy:
#     return n, result
#   moves = [((x-n, y), 'W'), ((x+n, y), 'E'), ((x, y-n), 'S'), ((x, y+n), 'N')]
#   for (nx, ny), dir in moves:
#     dist = distance(x, y, nx, ny)
#     if dist <= pd:
#       print(dist, pd)
#       rn, rresult = Branch(n+1, dist, nx, ny, gx, gy, result + (dir,))
#       print(rresult)
#       if rn <= 500:
#         return rresult
#   for (nx, ny), dir in moves:
#     dist = distance(x, y, nx, ny)
#     rn, rresult = Branch(n+1, dist, nx, ny, gx, gy, result + (dir,))
#     print(rresult)
#     if rn <= 500:
#       return rresult
#   raise Exception('Huh?')
  
# from astar import aStarSearch, Node

# def DoCase(file):
#   x, y = tuple(int_line(file))
#   start = Node((x, y), ((0,0), 1, ''), 0)
#   ans, goal = aStarSearch(start, None)
#   return goal.contents[2]
  
manhattan = lambda x, y, nx, ny: abs(x-nx) + abs(y-ny)

def ComputeEnd(history):
  x, y = 0, 0
  for i, d in enumerate(history, 1):
    if d == 'N':
      y += i
    elif d == 'S':
      y -= i
    elif d == 'E':
      x += i
    elif d == 'W':
      x -= i
  return x, y

def First(x, y):
  nx, ny = 0, 0
  xdir, ydir = -1 if x < 0 else 1, -1 if y < 0 else 1
  xmov, ymov = 'W' if x < 0 else 'E', 'S' if y < 0 else 'N'
  n = 1
  history = ''
  while True:
    if abs(x-nx) > n//2:
      nx += xdir*n
      history += xmov
    n += 1
    if abs(y-ny) > n//2:
      ny += ydir*n
      history += ymov
    n += 1
    if abs(y-ny) <= n//2 and abs(x-nx) <= n//2:
      break
  d = abs(nx-x)
  n += d
  if nx > x:
    history += 'EW'*d
  else:
    history += 'WE'*d
  d = abs(ny-y)
  n += d
  if ny > y:
    history += 'NS'*d
  else:
    history += 'SN'*d
  return history

def Fourth(x, y):
  nx, ny = 0, 0
  xdir, ydir = -1 if x < 0 else 1, -1 if y < 0 else 1
  xmov, ymov = 'W' if x < 0 else 'E', 'S' if y < 0 else 'N'
  n = 1
  history = ''
  while abs(x-nx) > n//2:
    nx += xdir*n
    n += 1
    history += xmov
  while abs(y-ny) > n//2:
    ny += ydir*n
    n += 1
    history += ymov
  d = abs(nx-x)
  n += d
  if nx > x:
    history += 'EW'*d
  else:
    history += 'WE'*d

  d = abs(ny-y)
  n += d
  if ny > y:
    history += 'NS'*d
  else:
    history += 'SN'*d
  return history

def Fifth(x, y):
  nx, ny = 0, 0
  xdir, ydir = -1 if x < 0 else 1, -1 if y < 0 else 1
  xmov, ymov = 'W' if x < 0 else 'E', 'S' if y < 0 else 'N'
  n = 1
  history = ''
  while abs(y-ny) > n//2:
    ny += ydir*n
    n += 1
    history += ymov
  while abs(x-nx) > n//2:
    nx += xdir*n
    n += 1
    history += xmov
  d = abs(nx-x)
  n += d
  if nx > x:
    history += 'EW'*d
  else:
    history += 'WE'*d

  d = abs(ny-y)
  n += d
  if ny > y:
    history += 'NS'*d
  else:
    history += 'SN'*d
  return history

def Third(x, y):
  nx, ny = 0, 0
  xdir, ydir = -1 if x < 0 else 1, -1 if y < 0 else 1
  xmov, ymov = 'W' if x < 0 else 'E', 'S' if y < 0 else 'N'
  n = 1
  history = ''
  while abs(y-ny) > n//2:
    ny += ydir*n
    n += 1
    history += ymov

  d = abs(ny-y)
  n += d
  if ny > y:
    history += 'NS'*d
  else:
    history += 'SN'*d
  while abs(x-nx) > n//2:
    nx += xdir*n
    n += 1
    history += xmov
  d = abs(nx-x)
  n += d
  if nx > x:
    history += 'EW'*d
  else:
    history += 'WE'*d
  return history

def Second(x, y):
  nx, ny = 0, 0
  xdir, ydir = -1 if x < 0 else 1, -1 if y < 0 else 1
  xmov, ymov = 'W' if x < 0 else 'E', 'S' if y < 0 else 'N'
  n = 1
  history = ''
  while abs(x-nx) > n//2:
    nx += xdir*n
    n += 1
    history += xmov
  d = abs(nx-x)
  n += d
  if nx > x:
    history += 'EW'*d
  else:
    history += 'WE'*d
  while abs(y-ny) > n//2:
    ny += ydir*n
    n += 1
    history += ymov

  d = abs(ny-y)
  n += d
  if ny > y:
    history += 'NS'*d
  else:
    history += 'SN'*d
  return history
  

def DoCase(file):
  x, y = tuple(int_line(file))
  return min([(len(x), x) for x in (First(x,y), Second(x,y), Third(x,y), Fourth(x,y), Fifth(x,y))], key=lambda x: x[0])[1]
  
  nx, ny = 0, 0
  xdir, ydir = -1 if x < 0 else 1, -1 if y < 0 else 1
  xmov, ymov = 'W' if x < 0 else 'E', 'S' if y < 0 else 'N'
  n = 1
  history = ''
  while True:
    if abs(x-nx) > n//2:
      nx += xdir*n
      history += xmov
    n += 1
    if abs(y-ny) > n//2:
      ny += ydir*n
      history += ymov
    n += 1
    if abs(y-ny) <= n//2 and abs(x-nx) <= n//2:
      break
  # while abs(x-nx) > n//2:
  #   nx += xdir*n
  #   n += 1
  #   history += xmov
  d = abs(nx-x)
  n += d
  if nx > x:
    history += 'EW'*d
  else:
    history += 'WE'*d
  # while abs(y-ny) > n//2:
  #   ny += ydir*n
  #   n += 1
  #   history += ymov

  d = abs(ny-y)
  n += d
  if ny > y:
    history += 'NS'*d
  else:
    history += 'SN'*d
  # assert ComputeEnd(history) == (x,y)
  return history
  # start = Node((x, y), ((0,0), 1, ''), 0)
  # ans, goal = aStarSearch(start, None)
  # return goal.contents[2]


@automain
def main(filename = None):
  if filename is None:
    print("SPECIFY FILE NAME!\n"*5)
    return 1
    # file = sys.stdin

  with open(filename) as file:
    case_count = int_line(file)
    for case in range(case_count):
      print('Case #{}: {}'.format(case+1, DoCase(file)))
