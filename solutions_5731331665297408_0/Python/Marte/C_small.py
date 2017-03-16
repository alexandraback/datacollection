import collections

def go(curr_zip, path):
  global min_zip
  if len(curr_zip) == N+1:
    if curr_zip < min_zip:
      min_zip = curr_zip[:]
    return
  # Proceed.
  for dest in routes[path[-1]]:
    if dest in curr_zip:
      continue
    new_zip = curr_zip[:]
    new_zip.append(dest)
    new_path = path[:]
    new_path.append(dest)
    go(new_zip, new_path)
    break
  # Or go back.
  prev_path = path[:]
  prev_path.pop()
  if len(prev_path) <= 1:
    return
  go(curr_zip[:], prev_path)

for cas in xrange(1, input()+1):
  print "Case #%d:" % cas,
  N, M = map(int, raw_input().split(' '))
  zips = ['']
  routes = collections.defaultdict(list)
  for _ in xrange(N):
    zips.append(raw_input())
    routes[''].append(zips[-1])
  for _ in xrange(M):
    x, y = map(int, raw_input().split(' '))
    routes[zips[x]].append(zips[y])
    routes[zips[y]].append(zips[x])
  for l in routes.values():
    l.sort()
  min_zip = ('_',)
  go([''], [''])
  print ''.join(min_zip)
