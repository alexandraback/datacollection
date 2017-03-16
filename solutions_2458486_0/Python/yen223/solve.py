import argparse
from collections import defaultdict, Counter
from copy import copy

def traverse(current_chest, chests, edges, keys, path):
    path.append(current_chest)
    if len(path) == len(chests):
        return path
    new_keys = Counter()
    for k in chests[current_chest]:
        new_keys[k] += 1
    new_keys.update(keys)
    
    for key, val in new_keys.iteritems():
        if val < 1: continue
        nextchests = [c for c in edges[key] if c not in path]
        nextchests.sort()
        if not nextchests:
            return None
        for chest in nextchests:
            temp_keys = copy(new_keys)
            temp_keys[key] -= 1
            new_path = traverse(chest, chests, edges, temp_keys, path)
            if new_path:
                return new_path
        else:
            return None

def solve(chests, edges, keys):
    '''
    Returns the solution 
    '''
    for k in keys:
        next_chests = edges[k]
        for chest in next_chests:
            temp_keys = Counter(keys) 
            temp_keys[k] -= 1
            path = traverse(chest, chests, edges, temp_keys, [])
            if path:
                return ' '.join([str(x+1) for x in path])
    else:
        return "IMPOSSIBLE"

    
        
if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--input", help="Name of the input file")
    parser.add_argument("-o", "--output", help="Name of the output file")
    args = parser.parse_args()
    INPUT = args.input
    OUTPUT = args.output
    print "Input file:", INPUT
    print "Output file:", OUTPUT
    solutions = []
    with open(INPUT, "r") as inp:
        T = int(inp.readline())
        for idx in range(1, T+1):
            chests = {}
            edges = defaultdict(list)
            K, N = [int(x) for x in inp.readline().split()]
            starting_keys = [int(x) for x in inp.readline().split()]
            for c in range(N):
                line = [int(x) for x in inp.readline().split()]
                key_to_open = line[0]
                keys = Counter(line[2:])
                edges[key_to_open].append(c)
                chests[c] = keys
            s = solve(chests, edges, starting_keys)
            sol = "Case #{}: {}".format(idx, s)
            print sol
            solutions.append(sol)
    if OUTPUT:
        with open(OUTPUT, "w") as out:
            out.write('\n'.join(solutions))
