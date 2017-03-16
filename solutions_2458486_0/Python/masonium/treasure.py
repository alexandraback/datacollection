import sys

TRIED_CASES = {}
MAX_KEY = 200

def read_int_list():
    x = [int(x) for x in sys.stdin.readline().strip().split()]
    return x

def docase():
    K, N = read_int_list()
    starting_key_list = read_int_list()

    starting_keys = [0] * (201)
    
    for key in starting_key_list:
        starting_keys[key] += 1

    starting_keys_copy = list(starting_keys)
        
    chests = dict()
    MAX_KEY = N+2
    for x in range(N):
        r = read_int_list()
        chests[x+1] = ( r[0], r[2:], len(r[2:]))
        if len(r[2:]) > 0:
            MAX_KEY = max(MAX_KEY, max(r[2:]))

    TRIED_CASES = dict()
    all_chests = dict(chests)
    solution = solve_treasure(starting_keys, chests)

    if solution is None:
        return solution
    
    keys = starting_keys_copy
    #solution = range(1, 10)
    # for chest in solution:
    #     print "Keys: " + str(keys[:MAX_KEY+1])
    #     print "Using key %d to open chest %d" % (all_chests[chest][0], chest)
    #     print "Collecting keys: " + str(all_chests[chest][1])
    #     keys[all_chests[chest][0]] -= 1
    #     for c in all_chests[chest][1]:
    #         keys[c] += 1
        
    return solution

def solve_treasure_aux(keys, chests):
    case_hash = tuple(keys[:MAX_KEY+2] + sorted(chests.keys()))
    
    if case_hash not in TRIED_CASES:
        TRIED_CASES[case_hash] = solve_treasure(keys, chests)

    return TRIED_CASES[case_hash]

def solve_treasure(keys, chests):
    if len(chests) == 0:
        return []
    
    solution = []

    # key check
    # If there aren't enough keys in the remaining chests, return None
    if sum(c[2] for c in chests.itervalues()) + sum(keys) < len(chests):
        return None
    
    possibles = []
    for name, (req, c, _) in chests.iteritems():
        if keys[req] > 0:
            possibles.append(name)

    possibles.sort()
    
    if len(possibles) == 0:
        return None

    for p in possibles:
        # try this solution
        chest = chests[p]
        req, c, _ = chest
        del chests[p]
        keys[req] -= 1
        
        for key in c:
            keys[key] += 1
            
        s = solve_treasure_aux(keys, chests)
        if s is not None:
            return [p] + s
        
        # undo
        for key in c:
            keys[key] -= 1
        keys[req] += 1
        chests[p] = chest
    
    return None

def main():
    N = read_int_list()[0]
    for i in range(1, N+1):
        solution = docase()
        if solution is not None:
            print "Case #%d: %s" %(i,  " ".join(str(x) for x in solution))
        else:
            print "Case #%d: IMPOSSIBLE" % i

if __name__ == "__main__":
    main()
