import sys
from copy import copy

def dfs_hunt(keys, chests):

    if not keys and chests:
        return None
    elif not chests:
        return []

    #keys is a list of keys
    #chests is a list of tuples: (chest_num, key_type, has_keys), where has_keys is a list of key_nums
    for c in chests:
        if c[1] in keys: # He have (at least) on of the required key!
            unopened_chests = copy(chests)
            del unopened_chests[unopened_chests.index(c)]
            new_keys = copy(keys)
            del new_keys[new_keys.index(c[1])]
            new_keys.extend(c[2])
            successful_chest_order = dfs_hunt(new_keys, unopened_chests)
    
            if successful_chest_order == False:
                return False
            if successful_chest_order is not None:
                return [c] + successful_chest_order
                
    
    # We tried all combos, and didn't return success. Not possible!
    return False

if __name__ == '__main__':
    num_cases = int(sys.stdin.readline().strip())

    for case_num in xrange(num_cases):
        num_keys, num_chests = map(int, sys.stdin.readline().strip().split())
        start_keys = map(int, sys.stdin.readline().strip().split())

        chests = []
        for chest_num in xrange(num_chests):
            chest_line = map(int, sys.stdin.readline().strip().split())
            key_type = chest_line[0]
            num_keys_in_chest = chest_line[1]
            keys_in_chest = chest_line[2:]
            chests.append((chest_num+1, key_type, keys_in_chest))

        chest_order = dfs_hunt(start_keys, chests)
        if chest_order:
            outcome = ' '.join(map(lambda l: '%s' % l[0], chest_order))
        else:
            outcome = 'IMPOSSIBLE'
        print "Case #%d: %s" % (case_num+1, outcome)
