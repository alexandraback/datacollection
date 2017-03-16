from collections import defaultdict

import itertools

t = int(raw_input())
for case in range(1, t + 1):
    max_c = 0
    n = int(raw_input())
    first_to_edges = defaultdict(list)
    second_to_edges = defaultdict(list)
    all_edges = []
    for _ in range(n):
        edge = raw_input().strip()
        all_edges.append(edge)
        first, second = edge.split()
        first_to_edges[first].append(edge)
        second_to_edges[second].append(edge)

    def valid(s):
        for edge in s:
            # Ensure edge could be a fake
            first, second = edge.split()
            if len(first_to_edges[first]) <= 1 or len(second_to_edges[second]) <= 1:
                return False
        return True

    # Do the dumb 2^n thing
    for s in itertools.chain.from_iterable(itertools.combinations(all_edges, r) for r in range(len(all_edges) + 1)):
        if valid(s):
            if len(s) > max_c:
                max_c = len(s)

    print "Case #%s: %s" % (case, max_c)
