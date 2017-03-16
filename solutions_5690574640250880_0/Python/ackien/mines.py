import sys
from itertools import combinations,product

def main():
  filename = sys.argv[1]
  fileIn = open(filename, 'r')
  fileOut = open("out.txt", 'w')
  T = int(fileIn.readline())
  for case in range(T):
    R,C,M = map(int,fileIn.readline().split(' '))
    answer = solveCase(R,C,M)
    fileOut.write("Case #{:d}:\n{:s}\n".format(case+1,answer))
  fileOut.close()
  fileIn.close()

def solveCase(R,C,M):
  # Special case: only one non-mine cell
  # Needs to be treated specially because it's the only situation where you
  # don't need a zeroCell to win
  if M == 0:
    answer = [['.' for j in range(C)] for i in range(R)]
    answer[0][0] = 'c'
    return '\n'.join(map(''.join,answer))
  if M == R*C-1:
    answer = [['*' for j in range(C)] for i in range(R)]
    answer[0][0] = 'c'
    return '\n'.join(map(''.join,answer))
  configs = combinations(range(R*C),M)
  for config in configs:
    grid = [[False for j in range(C)] for i in range(R)]
    mineCells = []
    for minePos in config:
      row = minePos/C
      col = minePos%C
      grid[row][col] = True
      mineCells.append((row,col))
    gridCells = list(product(range(R),range(C)))
    zeroCells = findZeroCells(grid,gridCells)
    if len(zeroCells) == 0:
      continue
    zeroCell_0 = zeroCells[0]
    if checkGrid(grid,gridCells,mineCells,zeroCells) is False:
      continue
    answer = [['.' for j in range(C)] for i in range(R)]
    for i in range(R):
      for j in range(C):
        if grid[i][j] is True:
          answer[i][j] = '*'
    answer[zeroCell_0[0]][zeroCell_0[1]] = 'c'
    return '\n'.join(map(''.join,answer))
  return "Impossible"

def findZeroCells(grid,gridCells):
  zeroCells = []
  for i in range(len(grid)):
    for j in range(len(grid[0])):
      if grid[i][j] is False:
        if checkZeroCell(grid,gridCells,i,j) is True:
          zeroCells.append((i,j))
  return zeroCells

def checkZeroCell(grid,gridCells,i,j):
  for row,col in [(i+iii,j+jjj) for iii in (-1,0,1) for jjj in (-1,0,1) if iii!=0 or jjj!=0]:
    if (row,col) in gridCells:
      if grid[row][col] is True:
        return False
  return True

def checkGrid(grid,gridCells,mineCells,zeroCells):
  fillGrid = [[False for j in range(len(grid[0]))] for i in range(len(grid))]
  for (i,j) in mineCells:
    fillGrid[i][j] = True
  zeroCell_0 = zeroCells[0]
  fillGrid[zeroCell_0[0]][zeroCell_0[1]] = True
  toSearch = [zeroCell_0]
  while len(toSearch) > 0:
    i,j = toSearch.pop()
    for row,col in [(i+iii,j+jjj) for iii in (-1,0,1) for jjj in (-1,0,1) if iii != 0 or jjj != 0]:
      if (row,col) in gridCells:
        if fillGrid[row][col] is False:
          fillGrid[row][col] = True
          if (row,col) in zeroCells and (row,col) not in toSearch:
            toSearch.append((row,col))
  for cellRow in fillGrid:
    for cell in cellRow:
      if cell is False:
        return False
  return True
  
main()
