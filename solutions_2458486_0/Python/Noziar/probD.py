import sys
import collections

def checkForward(start,keybuf,chestOrder,tuplemap,classToIdx,numclass,classmap):
  i = start
  while i < len(chestOrder):
    c = chestOrder[i]
    if keybuf[classToIdx[classmap[c]]] == 0:
      pbIdx = i
      targetIdx = classToIdx[classmap[c]]
      found = False
      while i >= 0:
        for j in xrange(pbIdx,len(chestOrder)):
          if tuplemap[chestOrder[j]][targetIdx] > 0 and keybuf[classToIdx[classmap[chestOrder[j]]]] > 0:
            backupChest = chestOrder[i]
            targetChest = chestOrder[j]
            chestOrder.insert(pbIdx,backupChest)
            del chestOrder[i]
            if i == pbIdx:
              chestOrder.insert(pbIdx,targetChest)
            else:
              chestOrder.insert(pbIdx-1,targetChest)
            del chestOrder[j+1]
            found = True
            break
        if found:
          break
        i -= 1
        c = chestOrder[i]
        keybuf[classToIdx[classmap[c]]] += 1
        keybuf = [a - b for a,b in zip(keybuf,tuplemap[c])]
      if not found:
        return False
    else:
      keybuf[classToIdx[classmap[c]]] -= 1
      keybuf = [a + b for a,b in zip(keybuf,tuplemap[c])]
      i += 1
  return True

def test(f,case):
  inf = f.next().split()
  K = int(inf[0])
  N = int(inf[1])
  keys = map(int,f.next().split())
  classes = keys[:]
  keymap = collections.OrderedDict()
  classmap = collections.OrderedDict()
  tuplemap = collections.OrderedDict()
  classToIdx = {}
  idxToClass = {}
  numclass = 0
  chestOrder = range(1,N+1)
  for k in chestOrder:
    info = map(int,f.next().split())
    classmap[k] = info[0]
    keymap[k] = map(int,info[2:])
    classes += [info[0]] + info[2:]
  for c in classes:
    if not c in classToIdx:
      classToIdx[c] = numclass
      idxToClass[numclass] = c
      numclass += 1
  init = [0]*numclass
  for key in keys:
    init[classToIdx[key]] += 1
  for k in chestOrder:
    l = [0]*numclass
    #l[classToIdx[classmap[k]]] = -1
    for key in keymap[k]:
      l[classToIdx[key]] += 1
    tuplemap[k] = tuple(l)
  if checkForward(0,init,chestOrder,tuplemap,classToIdx,numclass,classmap):
    print "Case #" + str(case+1) + ": " + " ".join(map(str,chestOrder))
  else:
    print "Case #" + str(case+1) + ": " + "IMPOSSIBLE"

with open(sys.argv[1],"r") as f:
  T = int(f.next())
  for k in xrange(T):
    test(f,k)