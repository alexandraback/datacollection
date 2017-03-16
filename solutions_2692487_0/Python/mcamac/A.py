T = input()


def search(size, ms, ops):
    cms = ms[:]
    while len(cms) > 0 and size > cms[0]:
        size += cms[0]
        cms = cms[1:]
    
    if len(cms) == 0:
        return ops

    mops = search(size, cms[0:-1], ops + 1)
    
    if size == 1:
        return mops
    cops = ops
    while cms[0] >= size:
        size += size - 1
        cops += 1
    
    nops = search(size, cms, cops)

    return min(nops, mops)

for c in range(1, T+1):
    [A,N] = map(int, raw_input().split())
    motes = map(int, raw_input().split())
    motes.sort()

    
    ans = search(A, motes, 0)
    print "Case #%d: %d" % (c, ans)
