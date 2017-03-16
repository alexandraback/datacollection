'''
Created on Apr 11, 2014

@author: dbaron
'''
def main():
   f = open('C-small-attempt5.in', 'r')
   g = open('MineSweeperResults.txt', 'w')
   done = False
   T = int(readLine(f))
   for testCase in range(1, T+1):
      input = readIntArray( f )
      try:
#          if testCase != 11:
#             continue
         result = handleNN( input[0], input[1], input[2] )
         done = True
         printGrid(g, testCase, result)
         done = False
      except Exception:
         if done:
            raise
         g.write( "Case #%d:\nImpossible\n" % (testCase))
         print "Case #%d:\nImpossible" % (testCase)
      
def printGrid(g, testCase, grid):
   try:
      g.write( "Case #%d:\n" % (testCase))
      print "Case #%d:" % (testCase)
      for line in grid:
         print ''.join(line)
         g.write(''.join(line) + '\n')
   except Exception:
      raise
      
def handleNN( R, C, M ):
   grid = [ [ '.' for i in range(C)]  for i in range(R) ]
   grid[R-1][C-1] = 'c'

   if R == 1:
      return handle1N(grid, M)
   elif C == 1:
      return flipGrid(handle1N(flipGrid(grid), M ))
   if R == 2:
      return handle2N(grid, M)
   elif C == 2:
      return flipGrid(handle2N(flipGrid(grid), M ))
   if R == 3:
      return handle3N(grid, M)
   elif C == 3:
      return flipGrid(handle3N(flipGrid(grid), M ))
   
   i = 0
   j = 0
   while i < R - 3 and ( M > 1 or j == C - 1 or j == 0 ):
      grid[i][j] = '*'
      M -= 1
      j += 1
      if j == C:
         j = 0
         i += 1
         
   if i >= R - 3:
      grid[i:] = handle3N( grid[i:], M )
   elif M == 1:
      grid[i+1][0] = '*'
      
   return grid
    
def handle1N( grid, M ):
   """Any 1xN grid can be solved by just clicking the bottom
   """
   r = len(grid)
   c = len(grid[0])
   if M >= c:
      # print M
      # print grid
      raise Exception() # Impossible
   else:
      for i in range(M):
         grid[0][i] = '*'
      return grid

def handle2N( grid, M ):
   """A 2xN grid has a few cases:
   - If we can fill every square except c with mines, we're okay
   - Otherwise, we need an even amount of mines
   """
   r = len(grid)
   c = len(grid[0])
   if M > c*r-4 and M != c*r-1: # Too many mines
      # print M
      # print grid
      raise Exception()
   if M%2 == 1 and M <= c*r-2: # Odd amount of mines
      # print M
      # print grid
      raise Exception()
   else:
      for i in range(M):
         grid[i%2][int(i/2)] = '*'
         
   return grid
         
def handle3N( grid, M ):
   """A 3xN grid is complex:
   Here we will fill as many cols to the left as possible.
   Our two exit states are as follows:
   - Only two cols left. Now we run handle2N
   - 0 mines left. We are okay.
   - <3 mines left. We run handle3NHard
   No failure states here. We offload that to other fns.
   """
   r = len(grid)
   c = len(grid[0])
   i = 0
   while i < c - 2 and M >= 3:
      grid[0][i] = '*'
      grid[1][i] = '*'
      grid[2][i] = '*'
      i += 1
      M -= 3
      
   if M == 0:
      return grid
   elif i >= c - 2: # 2N now
      grid = flipGrid(grid)
      grid[i:] = handle2N(grid[i:], M )
      grid = flipGrid(grid)
      return grid
   else:
      grid = flipGrid(grid)
      grid[i:] = flipGrid(handle3NHard( flipGrid(grid[i:]), M ))
      grid = flipGrid(grid)
      return grid
      
def handle3NHard( grid, M ):
   if M == 1:
      grid[0][0] = '*'
      return grid
   elif M == 2 and len(grid[0]) > 3:
      grid[0][0] = '*'
      grid[0][1] = '*'
      return grid
   else:
      # print M
      # print grid
      raise Exception() # Impossible
    
def flipGrid( grid ):
   x = len(grid)
   y = len(grid[0])
   newgrid = [ [ '.' for i in range(x)]  for i in range(y) ]
   for i in range(x):
      for j in range(y):
         newgrid[j][i] = grid[i][j]
   return newgrid
      
def operate( C, F, X ):
   rate = 2
   time = 0
   oldTime = ( X / rate ) + time
   while True:
      time += ( C / rate )
      rate += F
      newTime = ( X / rate ) + time
      if oldTime <= newTime:
         return oldTime
      else:
         oldTime = newTime

def readIntArray( f ):
   return map( int, readLine(f).split() )

def readFloatArray( f ):
   return map( float, readLine(f).split() )

def readLine( f ):
   return f.readline().rstrip('\n')

if __name__ == '__main__':
    main()