def single(func):
    return func(raw_input())

def row(func):
    return map(func, raw_input().strip().split())

def printcase(case, out, pattern='Case #%d: %s'):
    print pattern % (case, out)

def repeat(func, times):
    return [func() for _ in xrange(times)]


T = single(int)
for t in xrange(1, T + 1):
    B, M = map(int, raw_input().strip().split())
    maxM = 2 ** (B - 2)
    if M > maxM:
        printcase(t, 'IMPOSSIBLE')
    else:
        printcase(t, 'POSSIBLE')
        if M == maxM:
            n = '0' + '1'*(B-1)
        else:
            n = '0' + bin(M)[2:].zfill(B-2) + '0'
        print n
        for row in xrange(2, B + 1):
            print '0'*row + '1'*(B-row)
