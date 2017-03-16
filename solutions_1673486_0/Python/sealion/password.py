from itertools import combinations
import sys
from operator import mul

inp = sys.stdin

T = int(inp.readline())
for case_number in range(1, T + 1):
    typed, total = map(int, inp.readline().split())
    probs = map(float, inp.readline().split())
    assert len(probs) == typed
    chars = range(typed)
    cases = [(), tuple(chars)]
    for l in range(1, typed):
        cases += combinations(chars, l)
    cs = set(chars)
    table = {}
    for wrong in cases:
        pr = reduce(mul, [1 - probs[i] for i in wrong] + [probs[i] for i in cs - set(wrong)])
        strategies = {}
        strategies['keep'] = total - typed + 1 + (total + 1 if wrong else 0)
        for times in range(1, typed + 1):
            strategies['delete %d' % times] = times + total - typed + times + 1
            if wrong and wrong[0] <= typed - times - 1: # not all wrong characters are erased
                strategies['delete %d' % times] += total + 1
        strategies['enter'] = total + 2
        for k, v in strategies.items():
            table[k] = table.get(k, 0) + pr * v
    print 'Case #%d: %.6f' % (case_number, min(table.values()))


