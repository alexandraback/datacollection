import sys

numCases = input()
for case in range( 1, numCases + 1 ):
  n, m, k = [ int (y) for y in raw_input().split() ]
  area = n * m

  if k <= 4 or n <= 2 or m <= 2:
    output = k
  elif k >= ( area - 4 ):
    #print k, area
    blanks = area - k
    corners = 4 - blanks
    sides = ( n - 2 ) * 2
    tops  = ( m - 2 ) * 2
    output = sides + tops +  corners
  else:
    width = 3
    height = 3
    enclosed = 5
    stones = 4
    output = ""
    while( True ):
      if ( enclosed + 4 ) < k:
        break
      elif width > n - 2 or height > m - 2:
        break
      else:
        width += 2
        height += 2
        stones += 4
        enclosed += stones

    while ( output == "" ):
      if enclosed >= k:
        output = stones 
      elif enclosed == k - 2 and ( width < n or height < m ):
        output = stones + 1
      elif enclosed == k - 1:
        output = stones + 1
      elif width <= height:
        if width < n:
          #print "w1"
          width += 1
          stones += 2
          enclosed += height
        else:
          #print "h1"
          height += 1
          stones += 2
          enclosed += width
      else:
        if height < m:
          #print "h2"
          height += 1
          stones += 2
          enclosed += width
        else:
          #print "w2"
          width += 1
          stones += 2
          enclosed += height

  print 'Case #' + str( case ) + ': ' + str( output )
