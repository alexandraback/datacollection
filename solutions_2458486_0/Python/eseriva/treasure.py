#!/usr/bin/pypy

from collections import defaultdict
import pdb

import sys

def read_int(f):
    return int(f.readline())

def read_ints(f, sep=" "):
    return map(int, f.readline().rstrip().split(sep))

def read_lines(f, no_lines, type=str):
    retval = []
    for i in xrange(no_lines):
        retval.append(type(f.readline().rstrip()))
    return retval

class Chest(object):
    def __init__(self, idx, lock, keys=None, opened=False):
        self.idx = idx
        self.lock = lock
        if keys is None:
            keys = []
        self.keys = keys
        self.opened = opened

    def copy(self):
        return Chest(self.idx, self.lock, self.keys, self.opened)
            
    def can_open(self, key):
        if key == self.lock and not self.opened:
            return True
        else:
            return False
            
    def open(self, key):
        if self.can_open(key):
            self.opened = True
            return True
        else:
            return False

    def close(self):
        self.opened = False

    def __repr__(self):
        if self.keys:
            return "<%d l=%d k=%s%s>" % (self.idx, self.lock, " ".join(map(str,self.keys)), " op" if self.opened else "")
        else:
            return "<%d l=%d%s>" % (self.idx, self.lock, " op" if self.opened else "")
        

gcnt = 0

def solve(keys, chests, used=None, cnt=0):
    global gcnt
    if gcnt>1000:
        return False
    gcnt += 1
        
    if used is None:
        used = []
    
    print cnt, "--"
    print cnt, "gcnt", gcnt
    print cnt, "keys", keys
    print cnt, "chests", chests
    print cnt, "used", used
    
    if len(chests) == 0:
        print cnt, "ret", used
        return True
        
#    for chest in chests:
#        if not chest.opened:
#            break
#    else:
#        return used

    print cnt,"len(keys)", len(keys)
    if len(keys) == 0:
        print cnt,"used.pop"
        used.pop(-1)
        return False

    for key in keys:
        for chest in chests:
#            print cnt,"trying", key, chest
            if chest.can_open(key):
                print cnt,"opening", chest
                chests_cp = [c for c in chests if c!=chest]
                keys_cp = keys[:]
                keys_cp.remove(key)
                keys_cp.extend(chest.keys)
                keys_cp.sort()
                used.append(chest)
                retval = solve(keys_cp, chests_cp, used, cnt+1)
                if retval:
                    return retval
                
    print cnt,"no available chests"
    return False

                

if __name__ == "__main__":
    infile = open(sys.argv[1])
    no_cases = int(infile.readline())
        
    
    for cidx in xrange(no_cases):
        no_keys, no_chests = read_ints(infile)
        keys = read_ints(infile)

        chests = []
        for i in xrange(no_chests):
            items = read_ints(infile)
            lock = items.pop(0)
            tmp = items.pop(0)
            chest = Chest(i+1, lock, items)
            chests.append(chest)
#        print chests
        keys.sort()
        print "call", keys, chests
        used = []
        gcnt = 0
        status = solve(keys, chests, used)
        if not status:
            print "Case #%d: IMPOSSIBLE" % (cidx+1)
        else:
            print "Case #%d: %s" % (cidx+1, " ".join([str(c.idx) for c in used]))

 #       print "Case #%d: %d" % (cidx+1, sol)
