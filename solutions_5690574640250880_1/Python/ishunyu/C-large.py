import sys
sys.setrecursionlimit(10000)

def make(row, col, c):
  grid = []
  for i in range(row):
    tmp = []
    for j in range(col):
      tmp.append(c)
    grid.append(tmp)

  return grid

def impossible(f, n):
  f.write("Case #" + str(n) + ":\n")
  f.write("Impossible\n")


def flip(grid, row, col):
  new_grid = []

  for j in range(col):
    tmp = []
    for i in range(row):
      tmp.append(grid[i][j])
    new_grid.append(tmp)

  return new_grid

def replace_zeros(grid, row, col):
  seen_zero = False

  for i in range(row):
    for j in range(col):
      if grid[i][j] == "0":
        if seen_zero:
          grid[i][j] = "."
        else:
          grid[i][j] = "c"
          seen_zero = True

def draw(f, n, grid, row, col, inversed):
  if inversed == True:
    grid = flip(grid, row, col)

    tmp = row
    row = col
    col = tmp

  f.write("Case #" + str(n) + ":\n")

  for i in range(row):
    for j in range(col):
      f.write(grid[i][j])
    f.write("\n")

def p(grid, row, col):
  for i in range(row):
    for j in range(col):
      print grid[i][j],
    print ""

  print ""

def col1(f, n, row, inversed, blanks):
  grid = make(row, 1, "*")

  for i in range(blanks):
    grid[i][0] = "."

  grid[0][0] = "c"

  draw(f, n, grid, row, 1, inversed)


def col2(f, n, row, inversed, blanks):
  if blanks == 2 or blanks == 3:
    impossible(f, n)
    return

  if blanks % 2 == 1:
    impossible(f, n)
    return

  # now we are all good
  grid = make(row, 2, "*")
  for i in range(blanks/2):
    grid[i][0] = "."
    grid[i][1] = "."

  grid[0][0] = "c"

  draw(f, n, grid, row, 2, inversed)

def copy(grid, row, col):
  new_grid = []
  for i in range(row):
    tmp = []
    for j in range(col):
      tmp.append(grid[i][j])
    new_grid.append(tmp)

  return new_grid

def mark_and_count(grid, row, col, row_, col_):
  count = 0

  if grid[row_][col_] == "*":
    count = count + 1
  grid[row_][col_] = "0"

  # explore around the cell (row_, col_)
  # and count how many more blanks we get by doing so
  for i in range(-1, 2):
    row_t = row_ + i
    if row_t < 0 or row_t >= row:
      continue

    for j in range(-1, 2):
      col_t = col_ + j
      if col_t < 0 or col_t >= col:
        continue

      if grid[row_t][col_t] == "*":
        grid[row_t][col_t] = "."
        count = count + 1

  return count

def step(grid, row, col, blanks, row_, col_, dir):
  new_grid = copy(grid, row, col)

  if dir == 0:
    row_ = row_ - 1
    col_ = col_ - 1
  elif dir == 1:
    row_ = row_ - 1
  elif dir == 2:
    row_ = row_ - 1
    col_ = col_ + 1
  elif dir == 3:
    col_ = col_ + 1
  elif dir == 4:
    row_ = row_ + 1
    col_ = col_ + 1
  elif dir == 5:
    row_ = row_ + 1
  elif dir == 6:
    row_ = row_ + 1
    col_ = col_ - 1
  elif dir == 7:
    col_ = col_ - 1
  else:
    print "Cannot get here!"

  return explore(new_grid, row, col, blanks, row_, col_)


def explore(grid, row, col, blanks, row_, col_):
  if blanks == 0:
    return grid

  if row_ < 0 or row_ >= row or col_ < 0 or col_ >= col:
    return None

  if grid[row_][col_] == "0":
    return None

  new_grid = copy(grid, row, col)

  count = mark_and_count(new_grid, row, col, row_, col_)
  # p(new_grid, row, col)

  if count < blanks:
    for i in range(8):
      tmp_grid = step(new_grid, row, col, blanks - count, row_, col_, i)
      if tmp_grid is not None:
        return tmp_grid

  elif count == blanks:
    return new_grid

  return None

def coln(f, n, row, col, inversed, blanks):
  grid = make(row, col, "*")

  # multiple starting points
  # other points are just reflections
  for i in range(row / 2):
    for j in range(col / 2):
      result = explore(grid, row, col, blanks, i, j)

      if result is not None:
        replace_zeros(result, row, col)
        draw(f, n, result, row, col, inversed)
        return

  impossible(f, n)


#---------- START -------------
fin = open("C-large.in", "r")
fout = open("C-large-new.out", "w")

num = int(fin.readline())

for n in range(num):
  line = fin.readline().split(" ")
  row = int(line[0])
  col = int(line[1])
  mines = int(line[2])
  inversed = False

  # number of non-mine cells
  blanks = row * col - mines

  if blanks == 0:
    impossible(fout, n + 1)
    continue

  if blanks == 1:
    grid = make(row, col, "*")
    grid[0][0] = "c"
    draw(fout, n + 1, grid, row, col, False)
    continue

  if blanks == (row * col):
    grid = make(row, col, ".")
    grid[0][0] = "c"
    draw(fout, n + 1, grid, row, col, False)
    continue

  # normalize the grid so that col is always smaller or equal to row
  if col > row:
    tmp = row
    row = col
    col = tmp
    inversed = True

  if col == 1:
    col1(fout, n + 1, row, inversed, blanks)
    continue

  if col == 2:
    col2(fout, n + 1, row, inversed, blanks)
    continue

  if blanks == 2 or blanks == 3:
    impossible(fout, n + 1)
    continue

  coln(fout, n + 1, row, col, inversed, blanks)



