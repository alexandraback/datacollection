
saved = {}

def solve(energy, task):
    if task >= N:
        return 0;

    if (energy, task) in saved:
        return saved[(energy, task)]

    if energy > E:
        energy = E

    tmp = 0
    for e in range(energy+1):
        tmp = max(tmp, e * v[task] + solve(energy - e + R, task + 1))

    saved[(energy, task)] = tmp
    return tmp


T = int(raw_input())
for t in xrange(T):
    E, R, N = map(long,raw_input().split())
    v = map(long, raw_input().split())
    
    saved.clear()
    res = solve(E, 0)

    print "Case #{:d}: {:d}".format(t+1, res)
