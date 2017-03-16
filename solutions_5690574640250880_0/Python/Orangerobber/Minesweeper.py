import sys

T = int(sys.stdin.readline().strip())

for trial in range(1, T+1):
  print 'Case #%d:' % trial

  params = sys.stdin.readline().strip().split()
  r = int(params[0])
  c = int(params[1])
  m = int(params[2])
  M2 = m

  SWAP = False
  if(c==1):
    if(m>r-1):
        print "Impossible"
        continue
    else:
        print "c"
        for i in range(0,r-m-1):
            print "."
        for i in range(0,m):
            print "*"
        continue
   
  if(r==1):
    if(m>c-1):
        print "Impossible"
        continue
    else:
        sys.stdout.write("c")
        for i in range(0,c-m-1):
            sys.stdout.write(".")
        for i in range(0,m):
            sys.stdout.write("*")
        print ""
        continue

  spaces = r*c - m

  if(spaces==1):
    grid = [["*" for x in xrange(c)] for x in xrange(r)]
    grid[r-1][c-1] = 'c'
    for row in range(r):
        for col in range(c):
            sys.stdout.write(grid[row][col])
        print ""
    continue

  if(spaces in [2,3,5,7]):
    print "Impossible"
    continue

  if(c>r):
      t=c
      c=r
      r=t
      SWAP = True
  grid = [["." for x in xrange(c)] for x in xrange(r)]
  x = 0
  y = 0

  while(r-x > c):
      if(m>=c):
          for j in range(0,c):
              grid[x][j] = '*'
          m -= c
      else:
          for j in range(0,min(c-2,m)):
              grid[x][j] = '*'
          m -= min(c-2,m)
      x += 1

  while(x<r-2) and (y<c-2):
      width = c-y-1
      height = r-x

      if(m>=height):
          for j in range(x,r):
              grid[j][y] = '*'
          m -= height
      else:
          for j in range(x,x+min(height-2,m)):
              grid[j][y] = "*"
          m -= min(height-2,m)
      if(m>=width):
          for j in range(y+1,c):
              grid[x][j] = '*'
          m -= width
      else:
          for j in range(y+1,y+1+min(width-2,m)):
              grid[x][j] = "*"
          m -= min(width-2,m)
      x+=1
      y+=1

  if(m!=0):
      print "Impossible"
      continue

  grid[r-1][c-1] = 'c'

  if(SWAP):
      for col in range(c):
          for row in range(r):
              sys.stdout.write(grid[row][col])
          print ""
  else:
      for row in range(r):
          for col in range(c):
              sys.stdout.write(grid[row][col])
          print ""