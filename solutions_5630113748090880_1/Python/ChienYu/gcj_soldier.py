from sys import stdin

def each_case(N):
    allheights = set()
    for n in xrange(2*N-1):
        heights = map(int, stdin.readline().split())
        for h in heights:
            if h in allheights:
                allheights.remove(h)
            else:
                allheights.add(h)

    assert len(allheights) == N
    return ' '.join(map(str, sorted(allheights)))

T = int(stdin.readline())
for t in xrange(1,T+1):
    N = int(stdin.readline())
    print 'Case #{}: {}'.format(t, each_case(N))
