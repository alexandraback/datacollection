def ri():
  return int(raw_input())

def rd():
  return float(raw_input())

def rs():
  return raw_input()

def ril():
  return map(int, raw_input().split())

def rid():
  return map(float, raw_input().split())

def rsl():
  return map(str, raw_input().split())

grid = []

X = 50
Y = 50

def inbounds(x, y):
  if x < 0 or x >= X:
    return False
  if y < 0 or y >= Y:
    return False
  return True


tiles = set()

class Tile:
  def __init__(self, x, y):
    self.x = x
    self.y = y
    self.mine = True
    self.mine_neighbors = list()
    self.tile_neighbors = list()
    self.old_mine_neighbors = list()
    self.click = False

  def hsh(self):
    return (str(self.x) + ':' + str(self.y))

  def __hash__(self):
    return hash(self.hsh())

  def set_tile(self):
    self.mine = False
    tiles.add(self)
    return self

  def set_mine(self):
    self.mine = True
    tiles.remove(self)
    return self

  def expand(self):
    self.old_mine_neighbors = []
    for m in self.mine_neighbors:
      self.old_mine_neighbors.append(m)
      m.set_tile()

    for m in self.mine_neighbors:
      m.calc_mine_neighbors()
      m.calc_tile_neighbors()

    self.calc_tile_neighbors()
    self.calc_mine_neighbors()

    return self

  def unexpand(self):
    for t in self.old_mine_neighbors:
      t.set_mine()

    for t in self.old_mine_neighbors:
      t.calc_mine_neighbors()
      t.calc_tile_neighbors()

    self.calc_mine_neighbors()
    self.calc_tile_neighbors()
    return self

  def __str__(self):
    if self.click:
      return 'c'
    if self.mine:
      return '*'
    else:
      return '.'

  def calc_tile_neighbors(self):
    self.tile_neighbors = []
    for x in range(-1, 2):
      for y in range(-1, 2):
        if (x != 0 or y != 0) and inbounds(self.x+x, self.y+y) and not grid[self.x+x][self.y+y].mine:
          self.tile_neighbors.append(grid[self.x+x][self.y+y])
          grid[self.x+x][self.y+y].calc_mine_neighbors()
    return self

  def calc_mine_neighbors(self):
    self.mine_neighbors = []
    for x in range(-1, 2):
      for y in range(-1, 2):
        if (x != 0 or y != 0) and inbounds(self.x+x, self.y+y) and grid[self.x+x][self.y+y].mine:
          self.mine_neighbors.append(grid[self.x+x][self.y+y])
    return self

  def __unicode__(self):
    return hash(self)

def pr():
  for y in range(Y):
    line = ''
    for x in range(X):
      line += str(grid[x][y])
    print line

def create_grid(x, y):
  global X, Y, grid, tiles
  grid = []
  tiles = set()
  X = x
  Y = y

  for x in range(X):
    grid.append([])
    for y in range(Y):
      grid[x].append(Tile(x, y))

  grid[0][0].click = True
  grid[0][0].set_tile().calc_mine_neighbors().calc_tile_neighbors()

def fill(num_tiles):
#  print 'find:', num_tiles
  if num_tiles ==  0:
    return True

  for t in tiles:
    l = len(t.mine_neighbors)
    if l <= num_tiles and l > 0:
      #print str(t.x) + ", " + str(t.y)
      t.expand()
      if fill(num_tiles-l):
        return True
      t.unexpand()
  return False


N = ri()
for _ in range(N):
  print 'Case #%s:'%(_+1)
  foo = ril()
  _y = foo[0]
  _x = foo[1]
  _m = foo[2]
  _t = _x*_y - _m - 1

  if _m >= _x*_y or _x*_y == 0:
    print "Impossible"

  else:
    create_grid(_x, _y)
    ret = fill(_t)
    if ret:
      pr()
    else:
      print "Impossible"

