def solve():
    N, M, K = map(int, raw_input().strip().split())
    least = 10000000
    Know = K + 4
    plus = -1
    while least == 10000000 and Know >= 0:
        for i in xrange(2, N + 1):
            mod = Know % i
            j = Know / i
            if mod:
                j += 1
            if j > M:
                continue
            now = (i + j - 4) * 2
            if mod:
                now -= 1
            # print i, j, now
            if now < least:
                least = now
        Know -= 1
        plus += 1
    if least > 1000000:
        return K
    else:
        return min(K, least + plus)


def main():
    T = input()
    for i in xrange(1, T + 1):
        num = solve()
        print 'Case #%d:' % i,
        print num


if __name__ == '__main__':
    main()
