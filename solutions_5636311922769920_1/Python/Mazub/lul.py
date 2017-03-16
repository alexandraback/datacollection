def case(K, C, S):
    if K == S:
        kc1 = K**(C - 1)
        m = [kc1 * i + 1 for i in xrange(S)]
        return " ".join(map(str, m))
    else:
        return "IMPOSSIBLE"


if __name__ == "__main__":
    T = int(raw_input())
    for i in xrange(1, T + 1):
        K, C, S = map(int, raw_input().strip().split())
        print "Case #%d: %s" % (i, case(K, C, S))
