#!/usr/bin/python2
#-*- coding: utf-8 -*-

from collections import defaultdict
from collections import deque
from heapq import *

def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

class Chest:
  def __init__(self, id, needed, contents):
    self.id = id
    self.needed = needed
    self.contents = contents
    self.sons = []
    self.parent = None

  def __str__(self):
    return '('+str(self.id)+' : '+str(self.needed)+', '+str(self.contents)+', '+str(map(lambda x: x.id, self.sons))+')'
  
  def __lt__(self, other):
    return self.id < other.id

  def force_adopt(self, chest):
    self.sons.append(chest)
    chest.parent = self

def linearize(root):
  seq = []
  left = root.sons[:]
  heapify(left)
  while len(left) > 0:
    c = heappop(left)
    seq.append(c)
    for s in c.sons:
      heappush(left, s)
  return seq

for test in range(readint()):
  print 'Case #%i:'%(test+1),
  K, N = readarray(int)

  chests = []
  root = Chest(0, 0, readarray(int))

  for i in range(N):
    line = readarray(int)
    chests.append(Chest(i+1, line[0], line[2:]))
  
  needed = defaultdict(list)
  for c in chests:
    needed[c.needed].append(c)
  
  try:
    available = deque([(root, k) for k in root.contents])
    while len(available) > 0:
      parent, key = available.pop()
      while len(needed[key]) > 0:
        c = needed[key].pop(0)
        if c.parent == None:
          chests.remove(c)
          parent.force_adopt(c)
          available.extend([(c, k) for k in c.contents])
          break
    
    seq = linearize(root)
    
    key_positions = defaultdict(list)
    for c in chests:
      for k in c.contents:
        key_positions[k].append(c)

    for c in chests:
      parent = key_positions[c.needed].pop(0)
      parent.force_adopt(c)
      c.seen = False
      c.cycle = False
    
    cycles = defaultdict(list)
    nb_cycle = 0

    for c in chests:
      c.seen = True
      tmp = [c]
      while not c.parent.seen:
        c = c.parent
        chests.remove(c)
        c.seen = True
        tmp.append(c)
      if c.parent in tmp:
        i = tmp.index(c.parent)
        nb_cycle += 1
        for t in tmp[i:]:
          t.cycle = True
          cycles[t.needed].append(t)
    
    for k in iter(cycles):
      cycles[k].sort()
    
    found = None

    while nb_cycle > 0:
      for chest in seq[::-1]:
        found = None
        for c in cycles[chest.needed]:
          if c.cycle:
            found = c
            break
        if found != None:
          parent = found.parent
          
          parent.sons.remove(found)
          chest.parent.sons.remove(chest)
          
          chest.parent.force_adopt(found)
          parent.force_adopt(chest)
          
          i = seq.index(chest)
          tail = seq[i:]
          
          seq = linearize(root)
          nb_cycle -= 1
          break
      if found == None:
        raise Exception()
    print ' '.join(map(lambda x: str(x.id), seq))
  except Exception as inst:
    print 'IMPOSSIBLE'
