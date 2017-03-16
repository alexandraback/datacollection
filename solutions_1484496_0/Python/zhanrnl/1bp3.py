import itertools

def powerset(iterable):
    """powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"""
    s = list(iterable)
    return itertools.chain.from_iterable(itertools.combinations(s, r) for r in range(len(s)+1))

nt = int(raw_input())
for i in range(nt):
    nums = map(int, list(raw_input().strip().split())[1:])
    pset = list(powerset(nums))
    pset = map(lambda s: (sum(s), s), pset)
    printed = False
    for s in pset:
        ssum = s[0]
        for s2 in pset:
            s2sum = s2[0]
            if ssum == s2sum and s != s2:
                print "Case #" + str(i + 1) + ":"
                for n in s[1]: print n,
                print
                for n in s2[1]: print n,
                print
                printed = True
                break
        if printed:
            break
