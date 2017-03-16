from itertools import groupby, permutations

T = int(raw_input())

def shrink(s):
    return ''.join(k for k, g in groupby(s))

for case in range(T):
    N = int(raw_input())
    strings = raw_input().split()
    strings = [shrink(s) for s in strings]

    total = 0
    for p in permutations(strings):
        full = ''.join(p)
        letters = [k for k, g in groupby(full)]
        total += len(letters) == len(set(letters))

    print "Case #{}: {}".format(case + 1, total)