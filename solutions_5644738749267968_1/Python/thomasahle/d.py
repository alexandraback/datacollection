import sys

def war(ns, ks):
    wins = 0
    i, j = 0, 0
    while j != len(ks):
        # Ken cuts his losses and assigns j to a big i
        if ns[i] > ks[j]:
            wins += 1
            j += 1
            continue
        # Ken wins this round
        if ns[i] < ks[j]:
            i += 1
            j += 1
            continue
    return wins

def dwar(ns, ks):
    wins = 0
    i, j = 0, 0
    while i != len(ns):
        # Can't win on this one, take out kens greatest
        if ns[i] < ks[j]:
            i += 1
            continue
        # Pretend it's super big, so Ken just throws in his worst
        if ns[i] > ks[j]:
            wins += 1
            i += 1
            j += 1
    return wins

if __name__ == "__main__":
    read = lambda typ: list(map(typ,sys.stdin.readline().split()))
    T, = read(int)
    for t in range(T):
        N, = read(int)
        ns = sorted(read(float))
        ks = sorted(read(float))
        dw = N-war(ks, ns)
        w = war(ns, ks)
        print("Case #{}: {} {}".format(t+1, dw, w))
