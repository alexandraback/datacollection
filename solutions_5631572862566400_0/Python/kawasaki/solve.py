from itertools import combinations, permutations

T = int(raw_input())
for tc in xrange(T):
    N = int(raw_input())
    F = [int(x) - 1 for x in raw_input().split()]

    answer = 0
    for length in xrange(N, 0, -1):
        for lack in combinations(range(N), r=N - length):
            xs = sorted(set(range(N)) - set(lack))
            for ys in permutations(xs):
                if xs[0] != ys[0]:
                    break
                n = len(ys)
                for i, y in enumerate(ys):
                    if F[y] not in (ys[(i + 1) % n], ys[(i - 1) % n]):
                        break
                else:
                    answer = length
                    break
        if answer:
            break
    print 'Case #{}: {}'.format(tc + 1, answer)
