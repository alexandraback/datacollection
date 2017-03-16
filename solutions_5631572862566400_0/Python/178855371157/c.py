import sys
import collections

T = int(sys.stdin.readline())

def max_rev_path(rb, curr, seen):
    ret = 1
    for next in rb[curr]:
        if not seen[next]:
            seen[next] = True
            ret = max(ret, 1 + max_rev_path(rb, next, seen))
            seen[next] = False
    return ret    


for n in range(1, T+1):
    N = int(sys.stdin.readline())
    b = [0] + [int(x) for x in sys.stdin.readline().strip().split()]

    rb = collections.defaultdict(list)
    for i in range(1, N+1):
        rb[b[i]].append(i)

    # Find cycles.
    cycles = set()
    for i in range(1, N):
        p = [i, b[i]]
        seen = set([i, b[i]])
        while True:
            if b[p[-1]] in seen:
                if b[p[-1]] == p[0]:
                    cycles.add(frozenset(p))
                break
            seen.add(b[p[-1]])
            p.append(b[p[-1]])

    min_in_cycle = {}
    for c in cycles:
        m = min(c)
        for k in c:
            min_in_cycle[k] = m

    cycles_by_min = {min(c): c for c in cycles}

    answer_max_cycle = max([len(c) for c in cycles])

    answer_max_pairs = sum([2 for c in cycles if len(c) == 2])

    # Find the longest paths converging on length-2 cycles.
    pairs = [c for c in cycles if len(c) == 2]
    paths_to_pairs = []
    for pair in pairs:
        [k1, k2] = pair
        seen = collections.defaultdict(bool)
        seen[k1] = True
        seen[k2] = True
        paths_to_pairs.append((max_rev_path(rb, k1, seen), max_rev_path(rb, k2, seen)))

    answer_two_joined_paths = 0
    if paths_to_pairs:
        answer_two_joined_paths = max([sum(ptp) for ptp in paths_to_pairs])
        answer_two_joined_paths += 2*(len(pairs) - 1)
    
    answer_two_disjoint_paths = 0
    disjoints = [max(ptp)+1 for ptp in paths_to_pairs]
    disjoints.sort()
    if len(disjoints) > 1:
        answer_two_disjoint_paths = disjoints[-1] + disjoints[-2]
        answer_two_disjoint_paths += 2*(len(pairs) - 2)

    answer = max(
        answer_max_cycle,
        answer_max_pairs,
        answer_two_joined_paths,
        answer_two_disjoint_paths,
        sum([sum(ptp) for ptp in paths_to_pairs])
    )
        
    print "Case #{}: {}".format(n, answer)
