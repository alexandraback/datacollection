import sys

# from  http://codereview.stackexchange.com/questions/47984/fractions-data-type-when-to-reduce
def gcd(x, y):
  while y:
    x, y = y, x % y
  return x

def reduce( x, y ):
  cancel_factor = gcd(x, y)
  return ( x / cancel_factor, y / cancel_factor )

powers = []
for i in xrange( 1, 41 ):
  powers.append( pow( 2, i ) )

#print len( powers)
x = []

for i in xrange( 0, 40 ):
   x.append( 1.0 / powers[ i ] )

#print x
numCases = input()
for case in range( 1, numCases + 1 ):
  n, d = [ int (y) for y in raw_input().split('/') ]
  f = float(n) / float(d)
  n2, d2 = reduce( n, d )
  #print "reduced "
  #print n2, d2
  gen = 0
  if d2 in powers:
    while ( f < x[ gen ] and gen < 40):
      gen += 1
    output = gen + 1
  else:
    output = "impossible"
  #print gen

  print 'Case #' + str( case ) + ': ' + str( output )
