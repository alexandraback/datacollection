"""
Google Code Jam
2016 Round 1B

Problem C. 
    :author: yamaton
    :date: 2016-04-30
"""

import itertools as it
import functools
import operator
import collections
import math
import sys

def duplicates(words):
    res = collections.defaultdict(set)
    for i, w in enumerate(words):
        res[w].add(i)
    return [group for group in res.values() if len(group) > 1]


def solve(xss):
    people = list(range(len(xss)))
    list_groups = [duplicates(ys) for ys in zip(*xss)]
    pp(list_groups)

    candidates = [p for p in people if all(any(p in g for g in gs) for gs in list_groups)]
    pp('candidates', candidates)

    if len(candidates) <= 1:
        return len(candidates)

    pss = [{p: next(i for (i, g) in enumerate(gs) if p in g) for p in candidates}
           for gs in list_groups]

    pp('pss', pss)

    n = min(map(len, pss))
    while n > 1:
        for subset in it.combinations(candidates, n):
            pos = [[d[p] for p in subset] for d in pss]
            if all(len(set(s)) == len(s) for s in pos):
                pp('ppl', subset)
                return n
        n -= 1
    return n



def pp(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def main():
    for _tc in range(1, int(input())+1):
        pp('\n--------- case #%d -------' % _tc)
        print("Case #%d: " % _tc, end='')
        n = int(input())
        xss = [input().strip().split() for _ in range(n)]
        result = solve(xss)
        pp()
        pp('input =', xss)
        pp('result =', result)
        print(result)




if __name__ == '__main__':
    main()
