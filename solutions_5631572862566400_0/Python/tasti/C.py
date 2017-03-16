class Node:
  def __init__(self, key, out=None, inn=None):
    self.key = key
    self.out = out
    self.inn = inn

def longest_path(node):
  visited = list()
  current = node
  current_longest = 0
  while current.out != None:
    if current.key in visited:
      break

    visited.append(current.key)
    current = current.out
    current_longest += 1

  return visited

def shorten(path, graph):
  circle = [path[-1]] + path + [path[0]]
  # print path
  for i in xrange(1, len(path)+1):
    left = circle[i-1]
    right = circle[i+1]
    bff = graph[circle[i]].out.key
    if left != bff and right != bff:
      circle[i] = None
  # print circle
  circle = circle[1:]
  circle.pop()
  # print circle
  circle = filter(lambda x: x != None, circle)
  print circle
  return circle

def extend(path, graph):
  while True:
    if len(path) == 0:
      return []
    node = graph[path[-1]]
    if node == None or node.inn == None:
      break
    # print path
    # print node.key
    if node.inn.key not in path:
      path.append(node.inn.key)
    else:
      break

  return path

def bffs(N, F):
  F = map(lambda x: x-1, F)
  print 'F: ', F
  graph = [Node(i) for i in xrange(N)]
  for i, kid in enumerate(F):
    graph[i].out = graph[kid]
    graph[kid].inn = graph[i]
    # print i, kid

  longest = 0
  for node in graph:
    visited = longest_path(node)
    
    extended = extend(visited, graph)
    short = shorten(extended, graph)
    longest = max(longest, len(short))

  return longest

filename = 'C-small-attempt0'
f = open(filename + '.in', 'r')
o = open(filename + '.out', 'w')

T = int(f.readline())

for t in range(T):
  N = int(f.readline())
  F = map(int, f.readline().split())
  o.write('Case #%d: %s\n' % (t + 1, bffs(N, F)))
