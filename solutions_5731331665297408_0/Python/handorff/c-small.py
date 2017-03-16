from copy import deepcopy

def is_path(v, c, adj_list):
  visited = set()
  queue = [v]
  while queue != []:
    vertex = queue.pop(0)
    if vertex not in visited:
      visited.add(vertex)
      queue.extend(set(adj_list[vertex]) - visited)
      if c in visited:
        return True
  return False

def is_orphaned(c, visited, adj_list):
  if c in visited:
    return False
  for v in visited:
    if is_path(v, c, adj_list):
      return False
  return True

t = int(raw_input())

city_lists = []
edge_lists = []

for i in xrange(t):
  [n, m] = map(int, raw_input().split(' '))

  city_list = []
  for j in xrange(n):
    city_list.append(int(raw_input()))
  city_lists.append(city_list)

  edge_list = []
  for j in xrange(m):
    edge_list.append(map(int, raw_input().split(' ')))
  edge_lists.append(edge_list)

outputs = []
for i in xrange(t):
  city_list = city_lists[i]
  edge_list = edge_lists[i]

  adj_list = {}
  for [u, v] in edge_list:
    u = city_list[u - 1]
    v = city_list[v - 1]
    if u in adj_list:
      adj_list[u].append(v)
    else:
      adj_list[u] = [v]
    if v in adj_list:
      adj_list[v].append(u)
    else:
      adj_list[v] = [u]

  # Start at min
  current_city = min(city_list)
  visited = [current_city]

  if len(visited) == len(city_list):
    out = ''.join(map(str, visited))
    outputs.append("Case #%d: %s" % (i + 1, out))
  else:
    next_cities = deepcopy(adj_list[current_city])
    while len(visited) < len(city_list):

      if len(visited) == 1:
        orphaned_cities = []
      else:
        tmp_visited = deepcopy(visited)
        tmp_visited.remove(current_city)
        orphaned_cities = [c for c in city_list if is_orphaned(c, tmp_visited, adj_list) and c != current_city]

      if len(orphaned_cities) != 0:
        possible_next_cities = set(orphaned_cities).intersection(set(adj_list[current_city]))
        possible_next_cities = possible_next_cities.union(set(adj_list[current_city]))
        possible_next_cities = possible_next_cities - set(visited)
        current_city = min(possible_next_cities)
      else:
        current_city = min(next_cities)
      visited.append(current_city)
      next_cities.remove(current_city)
      for nbr in adj_list[current_city]:
        if nbr not in visited and nbr not in next_cities:
          next_cities.append(nbr)

      # Only one outbound flight to each city
      for u in adj_list:
        if current_city in adj_list[u]:
          adj_list[u].remove(current_city)



    out = ''.join(map(str, visited))
    outputs.append("Case #%d: %s" % (i + 1, out))

print '\n'.join(outputs)
