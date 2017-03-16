# treasure

import re
import sys
#from collections import deque

def conflicted(keys, chests, locks):
    '''Checks for immediate conflicts that make a state unsolvable.
    Currently, we only check if the only possible key for chest N is locked in chest N itself.
    '''
    for i in range(len(chests)):
        c = chests[i]
        if not (locks & (1 << i)) and c[1] in c[2] and c[1] not in keys:
            conflict = True
            for j in range(len(chests)):
                if i != j and not (locks & (1 << j)) and c[1] in chests[j][2]:
                    conflict = False
                    break
            if conflict:
                return True
    return False
    
def solve(initial_keys, chests):
    '''Find a way to open all chests, starting with initial_keys'''
    # state: (keys, locked chests)
    state = (initial_keys, long(0), list()) # given keys, all chests closed
    worklist = [state]
    l = len(chests)
    all_opened = 2**l - 1
    while len(worklist) > 0:
        keys, locks, order = worklist.pop()
        #print 'Step', keys, locks, order
        # termination
        if locks == all_opened:
            return order
        # successor states: opened chests
        for i in range(l-1, -1, -1):
            if not (locks & (1 << i)):
                if chests[i][1] in keys:
                    nkeys = list(keys)
                    nkeys[nkeys.index(chests[i][1])] = -1 # delete used key
                    nkeys.extend(chests[i][2]) # add found keys
                    norder = list(order)
                    norder.append(chests[i][0])
                    if not conflicted(nkeys, chests, locks | (1 << i)):
                        worklist.append((nkeys, locks | (1 << i), norder))
    return None

def sanity_check(keys, chests):
    '''Check whether there can be a solution at all.'''
    all_keys = list(keys)
    for c in chests:
        all_keys.extend(c[2])
    for c in chests:
        if c[1] in all_keys:
            del all_keys[all_keys.index(c[1])]
        else:
            return False
    return True
    
def treasure(filename):
    with open(filename) as f_in:
        total = int(f_in.readline())
        for i in range(total):
            keys, chestnum = map(int, f_in.readline().strip().split(' '))
            ikeys = map(int, f_in.readline().strip().split(' '))
            chests = []
            for j in range(chestnum):
                xs = map(int, f_in.readline().strip().split(' '))
                chests.append((j+1, xs[0], xs[2:]))  # (chest number, lock type, keys inside)
            if not sanity_check(ikeys, chests):
                print 'Case #{0}: IMPOSSIBLE'.format(i+1)
            else: 
                solution = solve(ikeys, chests) # sorted(chests, key=lambda x: -len(x[2])))
                print 'Case #{0}: {1}'.format(i+1, ' '.join(map(str, solution)) if solution is not None else 'IMPOSSIBLE')
            
if __name__ == "__main__":
    treasure(sys.argv[1])
