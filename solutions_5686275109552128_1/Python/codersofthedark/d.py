__author__ = 'Ut'
for t in range(int(raw_input())):
    D = int(raw_input())
    P = list(map(int, raw_input().split()))
    ans = max(P)
    Z = 2
    while Z < ans:
        ans = min(ans, sum([(x - 1) // Z for x in P]) + Z)
        Z += 1
    print('Case #%d: %s' % (t + 1, ans))
