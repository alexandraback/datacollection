__author__ = 'siavash'

T = input()
for t in range(T):

    D = input()

    P = list(map(int, raw_input().split(" ")))
    ans = max(P)
    Z = 2
    while Z < ans:
        ans = min(ans, sum([(x - 1) // Z for x in P]) + Z)
        Z += 1

    print 'Case #{0}: {1}'.format(t + 1, ans)