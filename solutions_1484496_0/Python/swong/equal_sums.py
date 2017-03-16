def solve( N, S ):
   results = dict()
   for i in range( 1048576 ):
      
      # Build subset
      subset = []
      for j in range(20):
         if (1 << j) & i:
            subset.append( S[j] )

      sumSubset = sum(subset)
      if sumSubset in results:
         return '\n' + ' '.join( str(s) for s in subset ) + '\n' + ' '.join( str(s) for s in results[sumSubset] )
      else:
         results[sumSubset] = subset

   return 'Impossible'

from sys import stdin
T = int( stdin.readline() )
for t in range(T):
   tokens = [ int(i) for i in stdin.readline().split() ]
   N = tokens[0]
   S = tokens[1:1+N]
   print "Case #{}: {}".format( t+1, solve( N, S ) )
