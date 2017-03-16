#!/usr/bin/python

import collections
import copy
import pdb
import sys
from collections import deque,defaultdict,OrderedDict

def main():
   infile = file(sys.argv[1])

   ncases = int(infile.readline().strip())


   for case in xrange(ncases):
    allchests = []
    dq = deque()
    seen = set()

    nkeys, nchests = [int(x) for x in infile.readline().strip().split()]
    inventory = defaultdict(lambda: 0)
    for key in [int(x) for x in infile.readline().strip().split()]:
        inventory[key] += 1
        

    for chest in xrange(nchests):
        keydata = [int(x) for x in infile.readline().strip().split(" ")]

        allchests.append({'open' : keydata[0],
                     'isopen' : False,
                     'inside' : keydata[2:]})

        opened = []
        nopened = 0
    dq.append((inventory, 0,0,[]))
    impossible = False
    chests = []

    while nopened < nchests:
        try: inventory, chests,nopened,order = dq.popleft()
        except IndexError:
            impossible = True
            print "Case #%d: IMPOSSIBLE" % case
            break
            
        for i, chest in enumerate(allchests):
            key = chest['open']
            count = inventory[key]
            if not chests & (1 << i) and count > 0:
                newchests = chests | (1 << i)
                if newchests in seen:
                    continue
                newinv = inventory.copy()
                newinv[key] = count-1
                for newkey in chest['inside']:
                    newinv[newkey] += 1
                seen.add(newchests)
                dq.append((newinv, newchests, nopened+1,order + [(i+1)]))
    if not impossible:
        print "Case #%d: %s" % (case, " ".join(map(str, order)))


                            
                            
            

    




main() 
