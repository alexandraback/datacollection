import sys


def compute(E, R, v):
    total = 0
    N = len(v)
    current = E
    i = 0
    while i < N:
        next_higher = N
        for j in xrange(i + 1, N):
            if v[j] > v[i]:
                next_higher = j
                break
        if next_higher == N:
            total += current * v[i]
            i += 1
            current = R
        else:
            delta = next_higher - i
            if current + delta * R <= E:
                current = current + R
                i += 1
            else:
                use = current + delta * R - E
                if use > current:
                    use = current
                total += use * v[i]
                current = current - use + R
                i += 1
    return total


def parse():
    E, R, N = map(int, sys.stdin.readline().strip().split())
    v = map(int, sys.stdin.readline().strip().split())
    return E, R, v


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    count = 1
    part = 0
    if len(sys.argv) == 3:
        part = int(sys.argv[1])
        count = int(sys.argv[2])
    for i in xrange(T):
        data = parse()
        if i * count >= part * T and i * count < (part + 1) * T:
            result = compute(*data)
            print "Case #%d: %s" % (i + 1, result)
