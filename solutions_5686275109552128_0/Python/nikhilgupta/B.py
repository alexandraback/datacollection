for t in range(int(input())):

    D = int(input())

    P = list(map(int, raw_input().split()))

    ans = max(P)
    k = 2
    while k < ans:
        ans = min(ans, sum([(x - 1) // k for x in P]) + k)
        k += 1

    print('Case #%d: %s' % (t + 1, ans))
