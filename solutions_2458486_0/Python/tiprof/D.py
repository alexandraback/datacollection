#! /usr/bin/python

import sys,copy

class Chest:
  def __init__(self, index, key, treasure):
    self.index = index
    self.key = key
    self.treasure = treasure
    self.opening_keys = None

  def __repr__(self):
    return "Chest#%d(%s,%s)"%(self.index, self.key, self.treasure)

def count_keys(chest, chests, keys):
  #print "count keys for chest %s in (%s,%s)"%(chest, chests, keys)
  rc = keys.count(chest.key)

  for i in range(len(chests)):
    if chests[i].index == chest.index:
      continue

    rc += chests[i].treasure.count(chest.key)

  chest.opening_keys = rc
  #print "found %d keys"%rc

  return rc
  

def recurse(keys, chests):
  rc = []
  if len(chests) == 0:
    return rc

  # count of needed and available keys, by key type
  needed_keys = {}
  avail_keys = {}
  for k in keys:
    if not avail_keys.has_key(k):
      avail_keys[k] = 0
    avail_keys[k] += 1

  for chest in chests:
    if not needed_keys.has_key(chest.key):
      needed_keys[chest.key] = 0
    needed_keys[chest.key] += 1

    for k in chest.treasure:
      if not avail_keys.has_key(k):
	avail_keys[k] = 0
      avail_keys[k] += 1

  for (k, count) in needed_keys.items():
    if not avail_keys.has_key(k):
      return None
    if avail_keys[k] < count:
      return None

  # critical path
  critical_chests = []
  critical_keys = []

  # fast exit loop
  for chest in chests:
    if count_keys(chest, chests, keys) == 0:
      return None

    if chest.opening_keys == 1:
      if chest.key in critical_keys:
	# 2 chests on the same single key
	return None
      critical_chests.append(chest)
      critical_keys.append(chest.key)

  # try the chest in lexicographically order...
  for i in range(len(chests)):
    chest = chests[i]
    # got a key for this one?
    if chest.key in keys:
      # dont consume a critical key
      if chest.key in critical_keys and chest not in critical_chests:
	continue

      new_keys = keys[:]
      new_keys.remove(chest.key)
      new_keys += chest.treasure
      rc = recurse(new_keys, chests[:i]+chests[i+1:])
      if rc != None:
	return [ chest.index ] + rc

  if rc == []:
    # wrong path
    return None

  return rc

def run():
  (K,N) = map(int, sys.stdin.readline().split())
  keys = map(int, sys.stdin.readline().split())

  chests = []
  for i in range(N):
    chest = map(int, sys.stdin.readline().split())
    if len(chest) > 2:
      chest = Chest(i, chest[0], chest[2:])
    else:
      chest = Chest(i, chest[0], [])

    chests.append(chest)

  # find a way back
  rc = recurse(keys, chests)

  if rc == None:
    rc = "IMPOSSIBLE"
  else:
    rc = ' '.join(map(lambda x: str(x+1), rc))

  return rc

cases = int(sys.stdin.readline())
for case in range(cases):
  print "Case #%d: %s"%(case+1, run())



