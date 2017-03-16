

NEW = 0
CLICKED = 1
FRONTIER = 2

class Board(object):
  def __init__(self, rows, cols):
    self.rows = rows
    self.cols = cols
    self.clicks = []
    self.initboard()
    self.neighb = [[None for c in xrange(self.cols)] for r in xrange(self.rows)]
    self._undo = [[[] for c in xrange(self.cols)] for r in xrange(self.rows)]
    self.clicked = [[False for c in xrange(self.cols)] for r in xrange(self.rows)]

  def initboard(self):
    self.board = [[NEW for c in xrange(self.cols)] for r in xrange(self.rows)]

  def undo(self):
    if len(self.clicks) <= 0:
      return
    urow, ucol = self.clicks.pop()
    self.board[urow][ucol] = NEW
    for row, col, state in self._undo[urow][ucol]:
      self.board[row][col] = state
    self._undo[urow][ucol] = []

  def hasclicked(self, position):
    row, col = position
    return self.clicked[row][col]


  def click(self, position):
    crow, ccol = position
    if self.clicked[crow][ccol]:
      return False
    self.clicked[crow][ccol] = True
    self._undo[crow][ccol].append((crow, ccol, self.board[crow][ccol]))
    self.board[crow][ccol] = CLICKED
    self.clicks.append(position)
    for neighbor in self.neighbors(position):
      row, col = neighbor
      if self.board[row][col] != CLICKED:
        self._undo[crow][ccol].append((row, col, self.board[row][col]))
        self.board[row][col] = FRONTIER
    return True

  def neighbors(self, position):
    if (not self.contains(position)):
      return []
    row, col = position
    if not self.neighb[row][col]:
      self.neighb[row][col] = []
      for r in [-1, 0, 1]:
        for c in [-1, 0, 1]:
          if r == 0 and c == 0:
            continue
          R = row + r
          C = col + c
          if (not self.contains((R, C))):
            continue
          self.neighb[row][col].append((R,C))
    return self.neighb[row][col]

  def cost(self, position):
    c = 0
    for row, col in self.neighbors(position):
      if self.board[row][col] == NEW:
        c += 1
    row, col = position
    if self.board[row][col] == NEW:
      c += 1
    return c
  def frontier(self):
    for r in xrange(self.rows):
      for c in xrange(self.cols):
        if self.board[r][c] == FRONTIER:
          yield r, c

  def contains(self, position):
    row, col = position
    if row >= 0 and row < self.rows:
      if col >= 0 and col < self.cols:
        return True
    return False

  def __repr__(self):
    a = []
    if len(self.clicks) > 0:
      frow, fcol = self.clicks[0]
    else:
      frow, fcol = -1, -1
    for r in xrange(self.rows):
      for c in xrange(self.cols):
        if r == frow and c == fcol:
          a.append('c')
          continue
        element = self.board[r][c]
        if element == NEW:
          a.append('*')
        elif element == CLICKED:
          a.append('.')
        else:
          a.append('.')
      a.append('\n')
    return ''.join(a)

if __name__ == '__main__':
  import sys
  board = Board(5,3)
  if (len(sys.argv) >= 3):
    position = (int(sys.argv[1]), int(sys.argv[2]))
  else:
    position = (0, 0)
  
  print board
  board.click(position)
  print board
  board.undo()
  print board
