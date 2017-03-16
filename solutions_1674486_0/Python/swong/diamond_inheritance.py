def solve(N,C):
   for i in range(1,N+1):
      visited = set()

      toVisit = [i]
      while len(toVisit) > 0:
         visit = toVisit.pop()
         #print "Visited {}".format(visit)
         if visit in visited:
            return "Yes"
         else:
            visited.add( visit )
            toVisit += C[visit]
   return "No"


from sys import stdin

T = int( stdin.readline() )
for t in range(T):
   N = int( stdin.readline() )
   C = dict()
   for n in range(N):
      tokens = [ int(i) for i in stdin.readline().split() ]
      M = tokens[0]
      C[n+1] = []
      for m in range(M):
         C[n+1].append( tokens[m+1] )

   #print C
   print "Case #{}: {}".format( t+1, solve(N,C) )
