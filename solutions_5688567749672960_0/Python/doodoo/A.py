def digits(num):
    ret = []
    while num > 0:
        ret.insert(0, str(num % 10))
        num /= 10

    return ret

def reverse(N):
    digs = digits(N)
    digs.reverse()
    return int(''.join(digs))

def solve(N):
    cache = [2*N] * (N + 1)
    cache[1] = 1

    for j in xrange(1, N):
        cache[j + 1] = min(cache[j] + 1, cache[j + 1])

        jr = reverse(j)
        if jr < N + 1:
            cache[jr] = min(cache[j] + 1, cache[jr])

    return cache[N]


T = int(raw_input())

for i in xrange(T):
    N = int(raw_input())

    print 'Case #%d: %d' % (i + 1, solve(N))
