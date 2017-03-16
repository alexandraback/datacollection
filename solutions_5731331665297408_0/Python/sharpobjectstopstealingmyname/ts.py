from sys import stdin
import itertools

Q = int(stdin.readline())
for qq in xrange(Q):
  nc,ne = map(int,stdin.readline().split())
  carr = []
  for x in xrange(nc):
    carr.append(stdin.readline().strip())
  edge = [[0]*nc for x in xrange(nc)]
  for x in xrange(ne):
    a,b = map(int,stdin.readline().split())
    a-=1
    b-=1
    edge[a][b] = 1
    edge[b][a] = 1
  res = "z"
  for p in itertools.permutations(range(nc)):
    trip_repr = reduce(lambda a,b:a+b,[carr[i] for i in p],"")
    if trip_repr < res:
      try:
        loc = p[0]
        stack = []
        for idx in xrange(1,nc):
          while not edge[loc][p[idx]]:
            loc = stack.pop()
          stack.append(loc)
          loc = p[idx]
        res = trip_repr
      except:
        pass
  print "Case #"+str(qq+1)+": "+str(res)