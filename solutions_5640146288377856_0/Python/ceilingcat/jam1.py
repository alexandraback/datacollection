import sys
import math

lines = sys.stdin.read().split( '\n' )

for k in range(0,int(lines[0])):
  sys.stdout.write( 'Case #' + str(k+1) + ': ' )

  vec1 = map( int, lines[k+1].split(' ') )
  R = vec1[0]
  C = vec1[1]
  W = vec1[2]

  if W == 1:
    print( R*C )
  else:
    #print( (R-1)*(C/W ) + C/W + W-1 + C%W )
    print( (R-1)*(C/W ) + int(math.ceil(float(C)/W) ) + W-1 )
