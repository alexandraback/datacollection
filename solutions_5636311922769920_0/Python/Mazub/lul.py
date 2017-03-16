def case(K, C, S):
    m = []
    kc1 = K**(C - 1)
    for i in xrange(S):
        m.append(kc1 * i + 1)
    return m


if __name__ == "__main__":
    T = int(raw_input())
    for i in xrange(1, T + 1):
        K, C, S = map(int, raw_input().strip().split())
        print "Case #%d: " % i + " ".join(map(str, case(K, C, S)))
