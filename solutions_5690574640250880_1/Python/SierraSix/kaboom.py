import sys
import re

def readcases():
  f = open(sys.argv[1], 'r')
  t = int(f.readline())

  cases = [];
  r = re.compile('[ \n]+')
  for i in xrange(t):
    data = map(int, r.split(f.readline())[:-1])
    cases.append({'r': data[0], 'c': data[1], 'm': data[2]})
  f.close()
  return cases
def mine(board, r, c, x, y):
  board[c*y + x]['m'] = 9
  if (x > 0):
    board[c*y + x - 1]['m'] += 1
    if (y > 0):
      board[c*(y-1) + x - 1]['m'] += 1
    if (y < r - 1):
      board[c*(y+1) + x - 1]['m'] += 1
  if (x < c - 1):
    board[c*y + x + 1]['m'] += 1
    if (y > 0):
      board[c*(y-1) + x + 1]['m'] += 1
    if (y < r - 1):
      board[c*(y+1) + x + 1]['m'] += 1
  if (y > 0):
    board[c*(y-1) + x]['m'] += 1
  if (y < r - 1):
    board[c*(y+1) + x]['m'] += 1
def solve(board, r, c, m, rf = False): # rf to determine if function is called recursively (recursion flag)
  if m <= 0:
    return True
  if (r*c - m == 1):
    for y in xrange(r):
      for x in xrange(c):
        if (x == c - 1 and y == r - 1):
          continue
        mine(board, r, c, x, y)
    return True
  if r >= c:
    if (c <= 2):
      if (c == 1):
        for y in xrange(m):
          mine(board, r, c, 0, y)
        return True
      if (m % 2 or c*r - m < 4):
        return False
      else:
        for y in xrange(m / 2):
          for x in xrange(c):
            mine(board, r, c, x, y)
        return True
    elif (c - m >= 2 or c == m):
      for i in xrange(m):
        mine(board, r, c, i, 0)
      return True
    elif (c - m > 0):
      for i in xrange(c - 2):
        mine(board, r, c, i, 0)
      if (r <= 3):
        return False
      mine(board, r, c, 0, 1)
      return True
    else:
      for i in xrange(c):
        mine(board, r, c, i, 0)
      return solve(board[c:], r - 1, c, m - c, True)
  else:
    rotate = []
    for x in xrange(c):
      # yr = range(0, r)
      # yr.reverse()
      for y in xrange(r):
        rotate.append(board[c*y + x])
    # print 'Rotated: \n', getboard(rotate, c, r)
    return solve(rotate, c, r, m, rf)
def getboard(board, r, c):
  out = ''
  for y in xrange(r):
    for x in xrange(c):
      if board[c*y + x]['m'] > 8:
        out += '*'
      elif (x == c - 1 and y == r - 1):
        out += 'c'
      else:
        out += '.' # str(board[c*y + x]['m'])
    out += '\n'
  return out
def self_destruct():
  cases = readcases()
  o = open('out.txt', 'w')
  for i in xrange(len(cases)):
    out = 'Case #' + str(i+1) + ':\n'
    board = [{'m': 0} for j in xrange(cases[i]['r'] * cases[i]['c'])]
    solved = solve(board, cases[i]['r'], cases[i]['c'], cases[i]['m'])
    if (solved):
      out += getboard(board, cases[i]['r'], cases[i]['c'])
    else:
      out += 'Impossible\n'
    print out
    o.write(out);
  o.close();

def main():
  if len(sys.argv) != 2:
    print 'Usage: python kaboom.py <input>'
  else:
    self_destruct()
if __name__ == '__main__':
  main()
