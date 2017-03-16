for t in range(int(input())):

    D = int(input())

    pA = list(map(int, input().split()))

    ans = max(pA)

    cl = 2
    while cl < ans:
        ans = min(ans, sum([(x - 1) // cl for x in pA]) + cl)
        cl += 1

    print('Case #%d: %s' % (t + 1, ans))


