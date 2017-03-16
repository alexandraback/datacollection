T = input()


for case in range(1, T + 1):
    ans = 0
    A, B, K = map(int, raw_input().split())
    # print A, B, K

    for i in range(A):
        for j in range(B):
            if i & j < K:
                ans += 1

    print "Case #%d:" % case, ans