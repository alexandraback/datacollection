
fname = "C-small-attempt5.in.txt"
# fname = "C-large.in.txt"
# fname = "test.in"

def solve(l, N):

  # shift to zero
  cnts = []
  l = [x-1 for x in l]
  # print l
  paths = []
  specials = set()
  for i in range(N):
    # count path length
    visited = [i]
    nxt = l[i]
    while nxt not in visited:
      visited.append(nxt)
      nxt = l[nxt]
    visited.append(nxt)
    if nxt == visited[0] or nxt == visited[-3]:
      paths.append(visited)
    if len(visited) == 3:
      specials.add(tuple(set(visited)))
  # print paths
  # print specials

  if len(specials) == 0:
    return max(map(len, paths))-1

  for path in paths:
    # if cycle (and bigger than 2)
    if path[0] == path[-1] and len(path) != 3:
      cnts.append(len(path)-1)

  maxes = []
  for special in specials:
    max_left = 0
    max_right = 0
    # print special
    # total_matches = 0
    for path in paths:
      if len(set(special) & set(path)) > 0:
        # print "made it:", path
        # total_matches += 1
        if path[-2:] == list(special) and len(path) > max_left:
          max_left = len(path)
        elif path[-2:] == list(special)[::-1] and len(path) > max_right:
          max_right = len(path)
        # print path
    # special_arms.append((max_left, max_right))
    maxes.append(max_left)
    maxes.append(max_right)
    # print len(specials)
  # print "maxes:", maxes
  cnts.append(sum(sorted(maxes)[-2:]) - 4 + (len(specials)-1)*2)

  # print "cnts:", cnts

  # print special_arms

  
  # sums = [a + b - 4 + (len(specials)-1)*2 for (a,b) in special_arms]
  # max_left = 
  # cnts.append(max_left + max_right - 4 + (len(specials)-1)*2)

  # print cnts
  # print cheap
  return max(cnts)

def main():
  with open(fname) as f:
    for i in xrange(int(f.readline())):
      N = int(f.readline())
      l = map(int, f.readline().split())
      # if i == 23 or i == 31:
      print 'Case #%s: %s' % (i + 1, solve(l, N))

main()