best = 0

def go(i, max_energy, E, R, N, v, e):
    if len(e) == N:
        global best
        energy = E
        for i in range(N):
            if e[i] > energy:
                raise Exception("%s %s %s" % (e, E, R))
            energy = energy - e[i] + R
        gain = sum(e[i] * v[i] for i in range(N))
        best = max(best, gain)
        print gain, e
    else:
        for spend in range(max(1, min(R, max_energy) - 2), max_energy + 1):
            new_e = e + [spend]
            go(i + 1, min(max_energy - spend + R, E), E, R, N, v, new_e)


def solve_back(E, R, N, v):
    global best
    best = 0
    R = min(R, E)
    go(0, E, E, R, N, v, [])
    return best

def solve(E, R, N, v):
    maxv = 0
    max_pos = -1
    for i in range(N):
        if v[i] > maxv:
            maxv = v[i]
            max_pos = i
    R = min(E, R)
    e = [R for i in range(N)]
    e[max_pos] = E
    return sum(v[i] * e[i] for i in range(N))


f = open("in.txt", "r")
T = int(f.readline())
out = open("out.txt", "w")
for test in range(1, T+1):
    E, R, N = (int(x) for x in f.readline().strip().split())
    v = [int(x) for x in f.readline().strip().split()]
    result = solve_back(E, R, N, v)
    out.write("Case #%s: %s\n" % (test, result))
out.close()
