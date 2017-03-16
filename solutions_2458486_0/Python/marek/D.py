import sys
import itertools
from collections import Counter

mem = None

def solve(start_keys, notopened):
    if notopened in mem: return None
    if not notopened:
        return []

    for chest in sorted(notopened):
        if start_keys[opens[chest]] > 0:
            r = solve(start_keys + chest_to_keys[chest],
                      notopened - set((chest,)))
            if r is not None:
                return [chest] + r
    mem[notopened] = True
    return None


for case_no in xrange(0, input()):
    print >> sys.stderr, "Case #%s:" % (case_no + 1,)
    print "Case #%s:" % (case_no + 1,),

    _, N = map(int, raw_input().split())
    start_keys = Counter(map(int, raw_input().split()))

    chest_to_keys = [None] * N
    opens = [None] * N
    end_keys = start_keys.copy()
    for chest_no in xrange(N):
        l = map(int, raw_input().split())
        chest_to_keys[ chest_no ] = Counter(l[2:])
        chest_to_keys[ chest_no ][l[0]] -= 1
        opens[ chest_no ] = l[0]
        end_keys += Counter(l[2:])
        end_keys[l[0]] -= 1

    if sum(1 for k, v in end_keys.items() if v < 0):
        print 'IMPOSSIBLE'
        continue

    mem = {}
    path = solve(start_keys, frozenset(range(N)))
    if path is None:
        print 'IMPOSSIBLE'
    else:
        print ' '.join(str(chest_no+1) for chest_no in path)
