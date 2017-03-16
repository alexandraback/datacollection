T = int(input())

for t in xrange(1, T+1):
    out = "Case #%d: "
    K, C, S = map(int, raw_input().split())
    if K == S:
        print out%t + " ".join(map(str, xrange(1, K+1)))
    elif C > 1 and K == S+1:
        print out%t + " ".join(map(str, xrange(2, K+1)))
    else:
        print out%t + "IMPOSSIBLE"
