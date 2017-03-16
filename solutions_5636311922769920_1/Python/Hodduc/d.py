T = input()
for i in range(1, T+1):
    K, C, S = map(int ,raw_input().split())

    if K == S:
        print "Case #%d:" % i, " ".join(map(str, range(1, K+1)))
    else:
        print "Case #%d:" % i, "IMPOSSIBLE"
