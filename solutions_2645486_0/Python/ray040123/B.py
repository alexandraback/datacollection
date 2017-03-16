
def search(i, e, g):
    global maxGain
    if i == N:
        if g > maxGain:
            maxGain = g
        return
    for dg in xrange(e + 1):
        if dg == 0:
            search(i + 1, min(E, e + R), g)
        else:
            search(i + 1, min(E, e - dg + R), g + V[i] * dg)

T = int(raw_input())
for t in xrange(T):
    E, R, N = map(int, raw_input().split())
    V = map(int, raw_input().split())
    maxGain = 0
    search(0, E, 0)
    print 'Case #{}: {}'.format(t + 1, maxGain)
