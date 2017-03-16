import sys
import functools

def read_case(lines):
    K, N = [int(i) for i in lines.next().strip().split()]
    start_keys = [int(i) for i in lines.next().strip().split()]
    assert len(start_keys) == K
    
    chests = []
    for _ in xrange(N):
        nums = [int(i) for i in lines.next().strip().split()]
        key_type = nums[0]
        keys = nums[2:]
        assert len(keys) == nums[1]
        keys.sort()
        chests.append((key_type, keys))
        
    return start_keys, chests


def read_input(path):
    cases = []
    with file(path) as f:
        lines = iter(f)
        n = int(lines.next())

        for i in range(1, 1 + n):
            cases.append((i, read_case(lines)))

    return cases

def subtract(keys, key_type):
    newkeys = keys[:]
    newkeys[key_type] -=1
    return newkeys

def add(keys, key_types):
    newkeys = keys[:]
    for i in key_types:
        newkeys[i] +=1
    return newkeys

#def solve(case):
#    start_keys, chests = case
#    d = [None] * len(chests)
#    
#    chests_by_key = {}
#    for i, (key_type, _) in enumerate(chests):
#        nodes = chests_by_key.setdefault(key_type, [])
#        nodes.append(i)
#        d[i] = (1, subtract(start_keys, key_type))
#        
#    for _ in xrange(len(chests)):
#        for i, curr in enumerate(d):
#            if curr is None:
#                continue
#            
#            max_nodes, keys = curr
#            possible = []
#            for k, val in enumerate(keys):
#                if val == 0:
#                    continue
#                possible.extend(chests_by_key[k])
#                
#            possible.sort()
#            curr_max = max_nodes + 1
#            for node in possible:
#                curr_keys = add(keys, chests[node][1])
#                if d[node] is None:
#                    d[node] = (curr_max, subtract(curr_keys, chests[node][0]))

def update(keys, to_remove, to_add):
    newkeys = keys[:]
    newkeys[to_remove] -= 1
    for i in to_add:
        newkeys[i] += 1
    return newkeys

def possible(keys, chests, chests_by_key):
    d = dict([(i,v) for (i,v) in enumerate(keys) if v > 0])
    reachable = set()

    keys_to_visit = set(d.iterkeys()) 
    visited = set()   
    while keys_to_visit:
        k = keys_to_visit.pop()
        visited.add(k)
        for i in chests_by_key.get(k, []):
            if i in chests:
                reachable.add(i)
                for newkey in chests[i][1]:
                    d.setdefault(newkey, 0)
                    d[newkey] += 1
                    if newkey not in visited:
                        keys_to_visit.add(newkey)
     
    if len(reachable) != len(chests):
        return False
    
    for k, v in d.iteritems():
        if v < len([i for i in chests_by_key.get(k, []) if i in chests]):
            return False
        
    return True

def recurse(keys, chests, chests_by_key):
    if not chests:
        return []
    
    if not possible(keys, chests, chests_by_key):
        return None

    candidates = []
    for k, v in enumerate(keys):
        if v > 0:
            candidates.extend(chests_by_key.get(k, []))
        
    if not candidates:
        return None
    
    candidates.sort()
    for c in candidates:
        if c not in chests:
            continue
        
        key_type, c_keys = chests.pop(c)
        result = recurse(update(keys, key_type, c_keys), chests, chests_by_key)
        chests[c] = key_type, c_keys
        
        if result is not None:
            return [c] + result
        
    return None
        
def solve(case):
    start_keys, chests = case
    chests = dict(enumerate([None] + chests))
    chests.pop(0)
    chests_by_key = {}
    for i, (key_type, _) in sorted(chests.iteritems()):
        nodes = chests_by_key.setdefault(key_type, [])
        nodes.append(i)
    
    keys = [0] * 201
    for i in start_keys:
        keys[i] += 1
    
    result =  recurse(keys, chests, chests_by_key)
    return ' '.join([str(i) for i in result]) if result is not None else 'IMPOSSIBLE'
    
    
if __name__ == '__main__':
    cases = read_input(sys.argv[1])
    for i, case in cases:
        print 'Case #%d: %s' % (i, solve(case))
