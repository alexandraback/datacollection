def fromBase(ds, base):
    tot = 0
    p = 1
    while ds:
        dig = ds.pop()
        tot += dig * p
        p *= base
    return tot


T = int(raw_input())
for i in xrange(T):
    K, C, S = map(int, raw_input().split())
    base = K
    digits = C
    tests = S

    if (tests*digits) < base or digits < 1:
        result = 'IMPOSSIBLE'
    else:
        testPositions = []
        digitsToFind = range(base)[::-1]
        while digitsToFind:
            ds = digitsToFind[:digits]
            digitsToFind = digitsToFind[digits:]
            testPositions.append(1 + fromBase(ds, base))
        result = ' '.join(map(str, testPositions))
    print('Case #{}: {}'.format(i+1, result))
