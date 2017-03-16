#!/usr/bin/env python

import sys, os, re

#---------------------------------------------------
# Function 
#---------------------------------------------------
def max_energy(E, R, N, event):
    assert len(event) == N
    # default energy map
    energy = [ E+R*i  for i in range(N)]
    value_map = {}
    for i in range(N):
        v = event[i]
        if v not in value_map:
            value_map[v] = []
        value_map[v].append(i)

    # energy range  
    cost = 0
    value_rank = value_map.keys()
    value_rank.reverse()
    for v in value_rank:
        for idx in value_map[v]:
            might = min(energy[idx:N])
            if might > E:
                spend = E
            else:
                spend = might 
            cost += (v*spend)
            for i in range(idx,N):
                energy[i] -= spend
    # check
    #for i in range(N):
    #    if energy[i] < 0 or energy[i] > E:
    #        print i, energy[i]
    return cost

def load_file(filename):
    with open(filename, 'rU') as f:
        N = int(f.readline())
        for i in range(N):
            E, R, N = [int(v) for v in f.readline().split()][0:3]
            list = [int(v) for v in f.readline().split()]
            event = list[0:N]
            result = max_energy(E, R, N, event)
            print 'Case #%d: %s' % (i+1, result)
    return

#---------------------------------------------------
# Entry Point 
#---------------------------------------------------
def main():
    #if len(sys.argv) < 3:
    #    print 'Usage:'
    #    print '  %s arg1 arg2' % os.path.basename(sys.argv[0])
    #    sys.exit(1)

    load_file (sys.argv[1])

    return

#---------------------------------------------------
# Unit Test Entry 
#---------------------------------------------------
if __name__ == '__main__':
    main()


