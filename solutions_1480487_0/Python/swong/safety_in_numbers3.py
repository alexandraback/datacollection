def solve( N, S ):
   maxS  = max(S)
   sumS  = sum(S)

   sumS2 = sum(S)
   N2 = N
   for s in S:
      sumLessS = sumS - s
      num = float( sumLessS + sumS ) / (N-1) - s
      if num < 0:
         sumS2 -= s
         N2 -= 1

   #print sumS2, N2
   P = str()
   for s in S:
      sumLessS = sumS2 - s
      num = float( sumLessS + sumS ) / (N2-1) - s
      if num < 0: num = 0.0
      den = float( sumS * N2 ) / (N2-1)
      P += " " + str( num/den*100 )
      
   return P

from sys import stdin

T = int( stdin.readline() )
for t in range(T):
   tokens = [ int(i) for i in stdin.readline().split() ]
   N = tokens[0] 
   S = tokens[1:1+N]
   print "Case #{}:{}".format( t+1, solve( N, S ) )
