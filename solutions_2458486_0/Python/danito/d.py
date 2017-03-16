#!/usr/bin/python -tt



def solve(keys,chests,path=[]):
  if len(chests) == len(path): return path
  if len(keys) == 0: return None

  for number,chest in enumerate(chests):
    if number not in path:
      if chest[0] in keys:
        keys_b = list(keys)
        path_b = list(path)

        path.append(number)
        keys.remove(chest[0])
        if chest[1]:
          keys.extend(chest[2:])

        newpath = solve(keys,chests,path)
        if newpath: return newpath

        keys = keys_b
        path = path_b

  return None



def main(keys, chests):
  path = solve(keys,chests)

  if path:
    ret = ""
    for k in path:
      ret = ret + " " + str(k+1)
  else: ret = "IMPOSSIBLE"
  return ret


if __name__ == '__main__':
  import sys
  T = int(sys.stdin.readline())
  for i in xrange(T):
    K, N = map(int,sys.stdin.readline().strip().split(" "))
    keys = map(int,sys.stdin.readline().strip().split(" "))
    chests = []
    for j in xrange(N):
      chests.append(map(int,sys.stdin.readline().strip().split(" ")))
    res = main(keys, chests)
    print "Case #%d: %s" % (i + 1, res.strip())

