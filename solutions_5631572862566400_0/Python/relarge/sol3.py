def DFS(G, P):
  N = len(G)
  loop = 0
  for i in G.iterkeys():
    loop = max(loop, DFS_i(G, i, P))
  return loop

def DFS_i(G, i, P):
  import copy
  C = copy.copy(G)
  P2 = copy.copy(P)

  if len(P) > 0:
    if len(P) > 1 and G[i] == P[0]:
      # print P + [i], G, 15
      return 1
    elif (len(P) == 1 and G[i] == P[0]) or (len(P) > 1 and G[i] == P[-1]):
      C.pop(i)
      P2.append(i)
      return 1 + DFS(C, P2)
    elif len(P) > 1 and G[i] in P[1:-1]:
      # print P, G, 22
      return 0

  P2.append(i)
  C.pop(i)
  i = G[i]
  c = 1
  while True:
    if len(P2) > 1 and G[i] == P2[0]:
      # print P2, G, 31
      return c + 1
    elif (len(P2) == 1 and G[i] == P2[0]) or (len(P2) > 1 and G[i] == P2[-1]):
      C.pop(i)
      P2.append(i)
      return c + 1 + DFS(C, P2)
    elif len(P2) > 1 and G[i] in P2[1:-1]:
      # print P, G, 38
      return 0
    else:
      P2.append(i)
      # print P2, i, C, G
      C.pop(i)
      i = G[i]
      c += 1


def sol(N, F):
  G = {}
  for i in xrange(len(F)):
    G[i + 1] = F[i]
  return DFS(G, [])

# print sol(4, [2,3,4,1])
# print sol(4, [3,3,4,1])
# print sol(4, [3,3,4,3])
# print sol(10, [7,8,10,10,9,2,9,6,3,3])
t = long(raw_input())  # read a line with a single integer

for i in xrange(1, t + 1):
    N = int(raw_input())
    F = map(lambda x: int(x), raw_input().split())
    print "Case #{}: {}".format(i, sol(N, F))
