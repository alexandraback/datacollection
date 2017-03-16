from sys import stdin
import copy

def solve(start, graph, postcodes):
  bestAns = [10000000000000000000000000000000000000000000000000000000]
  def dfs(visited, stack, ans):
    if len(visited) == len(graph) and ans < bestAns[0]:
      bestAns[0] = ans
      return
    for i in range(len(stack)):
      u = stack[i]
      for v in graph[u]:
        if v not in visited:
          dfs(visited | set([v]), stack[:i+1] + [v], ans * 100000 + postcodes[v])
  dfs(set([start]), [start], postcodes[start])
  return bestAns[0]

T = int(stdin.readline())

for no in range(1, T+1):
  N, M = map(int, stdin.readline().split())
  postcodes = {}
  graph = {i: set() for i in range(1,N+1)}
  for i in range(1, N+1):
    postcodes[i] = int(stdin.readline())
  for i in range(M):
    x, y = map(int, stdin.readline().split())
    graph[x].add(y)
    graph[y].add(x)
  bestStart = None
  bestPostcode = 10000000000
  for u in postcodes:
    if postcodes[u] < bestPostcode:
      bestPostcode = postcodes[u]
      bestStart = u
  print("Case #{}: {}".format(no, solve(bestStart, graph, postcodes)))
