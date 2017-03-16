
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


def draw(f, n, grid, row, col, inversed):
  if grid[0][0] == ".":
    grid[0][0] = "c"

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
  return
  for i in range(row):
    for j in range(col):
      print grid[i][j],
    print ""

  print ""

def col1(f, n, row, inversed, blanks):
  # all works

  grid = []

  for i in range(row):
    tmp = []
    if blanks > 0:
      tmp.append(".")
      blanks = blanks - 1
    else:
      tmp.append("*")

    grid.append(tmp)

  draw(f, n, grid, row, 1, inversed)


def col2(f, n, row, inversed, blanks):
  if blanks == 2 or blanks == 3:
    impossible(f, n)
    return

  if blanks % 2 == 1:
    impossible(f, n)
    return

  # now we are all good
  grid = []
  for i in range(row):
    tmp = []
    if blanks >= 2:
      tmp.append(".")
      tmp.append(".")
      blanks = blanks - 2
    else:
      tmp.append("*")
      tmp.append("*")

    grid.append(tmp)

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

  grid[row_][col_] = "."

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

def right(grid, row, col, blanks, row_, col_):
  new_grid = copy(grid, row, col)

  

  if col_ == (col - 1):
    row_ = row_ + 1
    col_ = 0
  else:
    col_ = col_ + 1

  if row_ >= row or col_ >= col:
    return None

  count = mark_and_count(new_grid, row, col, row_, col_)
  
  # print "right"
  # print blanks, row_, col_
  # print "count:", count

  if count < blanks:
    return coln_(new_grid, row, col, blanks - count, row_, col_)
  elif count == blanks:
    return new_grid
  else:
    return None

def down(grid, row, col, blanks, row_, col_):
  new_grid = copy(grid, row, col)

  row_ = row_ + 1

  if row_ >= row or col_ >= col:
    return None

  count = mark_and_count(new_grid, row, col, row_, col_)

  # print "down"
  # print blanks, row_, col_
  # print "count:", count

  if count < blanks:
    return coln_(new_grid, row, col, blanks - count, row_, col_)
  elif count == blanks:
    return new_grid
  else:
    return None

def diag(grid, row, col, blanks, row_, col_):
  new_grid = copy(grid, row, col)
  
  row_ = row_ + 1
  col_ = col_ + 1

  if row_ >= row or col_ >= col:
    return None

  count = mark_and_count(new_grid, row, col, row_, col_)

  # print "diag"
  # print blanks, row_, col_
  # print "count:", count

  if count < blanks:
    return coln_(new_grid, row, col, blanks - count, row_, col_)
  elif count == blanks:
    return new_grid
  else:
    return None

def coln_(grid, row, col, blanks, row_, col_):
  if blanks == 0:
    return grid

  p(grid, row, col)

  # right
  tmp_grid = right(grid, row, col, blanks, row_, col_)
  if tmp_grid is not None:
    return tmp_grid

  # down
  tmp_grid = down(grid, row, col, blanks, row_, col_)
  if tmp_grid is not None:
    return tmp_grid

  # diagonal
  tmp_grid = diag(grid, row, col, blanks, row_, col_)
  if tmp_grid is not None:
    return tmp_grid

  return None

def coln(f, n, row, col, inversed, blanks):
  grid = []

  if blanks == (row * col):
    for i in range(row):
      tmp = []
      for j in range(col):
        tmp.append(".")
      grid.append(tmp)

    draw(f, n, grid, row, col, inversed)
    return

  # make grid full of mines
  for i in range(row):
    tmp = []
    for j in range(col):
      tmp.append("*")
    grid.append(tmp)

  if blanks == 0:
    draw(f, n, grid, row, col, inversed)
    return
  elif blanks == 1:
    grid[0][0] = "."
  else:
    grid[0][0] = "."
    grid[0][1] = "."
    grid[1][0] = "."
    grid[1][1] = "."
    
    grid = coln_(grid, row, col, blanks - 4, 0, 0)

  if grid is None:
    impossible(f, n)
  else:
    draw(f, n, grid, row, col, inversed)

#---------- START -------------
fin = open("C-small-attempt2.in", "r")
fout = open("C-small-attempt2-old.out", "w")

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



