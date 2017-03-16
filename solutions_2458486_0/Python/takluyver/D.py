# -*- coding: utf-8 -*-
fname = "D-small-attempt0"
fin = open(fname+".in","r")
fout = open(fname+".out","w")
def gcj_read():
  linestr = fin.readline().strip()
  return [int(numb) for numb in linestr.split()]

from collections import Counter
from copy import copy

class CantOpen(Exception): pass

def try_to_open(chests, gotkeys):
    if len(chests) <= 0:
        return []
    
    neededkeys = Counter(need for chestno,need,contents in chests)
    tried = set()
    
    for i, (chestno,needkey,contents) in enumerate(chests):
        if gotkeys[needkey] <= 0:
            continue
        
        if (gotkeys[needkey] >= neededkeys[needkey]) or (needkey in contents):
            print("Going for chest", chestno)
            gotkeys[needkey] -= 1
            gotkeys.update(contents)
            newchests = copy(chests)
            del newchests[i]
            return [chestno] + try_to_open(newchests, gotkeys)
            
        
        else:
            #print("Should we open chest", chestno)
            type = (needkey, tuple(k for k in contents if neededkeys[k] > 0))
            if type in tried:
                # We've already tried opening an equivalent chest, and it
                # didn't work.
                continue
            
            test_gotkeys = gotkeys.copy()
            test_gotkeys[needkey] -= 1
            test_gotkeys.update(contents)
            test_chests = copy(chests)
            del test_chests[i]
            try:
                return [chestno] + try_to_open(test_chests, test_gotkeys)
            except CantOpen:
                #print("No!")
                tried.add(type)
                continue
    
    # Can't open any more
    raise CantOpen

numcases = gcj_read()[0]

for caseno in range(numcases):
    K, N = gcj_read()
    gotkeys = Counter(gcj_read())
    
    chests = []
    for chestno in range(N):
        Ti, _, *Ki = gcj_read()
        chests.append((chestno+1, Ti, Ki))
    
    all_keys = gotkeys.copy()
    for chestno,needs,contents in chests:
        all_keys.update(contents)
    
    neededkeys = Counter(need for chestno,need,contents in chests)
    if (neededkeys | all_keys) == all_keys:
    
        try:
            seq = try_to_open(chests, gotkeys)
            outstr = ' '.join(str(n) for n in seq)
        except CantOpen:
            outstr = 'IMPOSSIBLE'
    
    else:
        outstr = 'IMPOSSIBLE'
        
    print("Case #"+str(caseno+1)+": "+ outstr)
    fout.write("Case #"+str(caseno+1)+": "+ outstr +"\n")

fin.close()
fout.close()
