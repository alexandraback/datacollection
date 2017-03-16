import bisect


def solveWar(N, K):
    N.sort()
    K.sort()

    result = 0
    for n in N:
        i = bisect.bisect(K, n)
        if i == len(K):
            i = 0
        if n > K[i]:
            result += 1
        K = K[:i] + K[i+1:]
    return result


def solveDeceitfulWar(N, K):
    N.sort()
    K.sort()

    i = 0
    result = 0
    for n in N:
        if n > K[i]:
            result += 1
            i += 1
    return result


def solve():
    n = int(input())
    N = [float(x) for x in input().split()]
    K = [float(x) for x in input().split()]

    return solveDeceitfulWar(N[:], K[:]), solveWar(N[:], K[:])


def main():
    t = int(input())
    for x in range(1, t+1):
        y, z = solve()
        print("Case #%d: %d %d" % (x, y, z))


if __name__ == '__main__':
    main()