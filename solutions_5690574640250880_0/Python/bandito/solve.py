from board import Board

SEEDS = [(0,0), (0,1), (1,1)]
def is_edge(row, col, mines):
  if (row * col) - mines != 1:
    return None
  a = []
  for r in xrange(row):
    for c in xrange(col):
      if r == c == 0:
        a.append('c')
      else:
        a.append('*')
    a.append('\n')
  return ''.join(a)

def click(board, position, bank):
  #print position, bank, board.cost(position)
  #print board
  bank -= board.cost(position)
  if (bank < 0):
    return False
  board.click(position)
  if bank == 0:
    return board
  frontier = [i for i in board.frontier()]
  for position in frontier:
    if board.hasclicked(position):
      continue
    result = click(board, position, bank)
    if not result:
      continue
    return board
  board.undo()

def solve(row, col, mines):
  # OK, this is an ugly hack. But there's a terrible edge
  # case of a 1 x 2 board with one mine. 
  res = is_edge(row, col, mines)
  if res:
    return res
  board = Board(row, col)
  bank = row * col - mines
  for r in xrange(row):
    for c in xrange(col):
      if board.hasclicked((r,c)):
        continue
      result = click(board, (r, c), bank)
      if not result:
        continue
      return result

def test():
  for r in xrange(1, 50):
    for c in xrange(1, 50):
      m = random.randrange(0, r * c)
      print '\n\n'
      print r, c, m
      result = solve(r, c, m)
      if result:
        print str(result).strip()
      else:
        print 'Impossible'

if __name__ == '__main__':
  import sys
  sys.setrecursionlimit(10000)
  with open(sys.argv[1]) as f:
    num_cases = int(f.readline())
    for case in xrange(num_cases):
      row, col, mines = map(int, f.readline().split())
      print 'Case #%d:' %(case + 1)#, row, col, mines
      result = solve(row, col, mines)
      if result:
        print str(result).strip()
      else:
        print 'Impossible'
