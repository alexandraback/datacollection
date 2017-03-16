if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(T):
        S, shyness = raw_input().split()
        S, shyness = int(S), map(int, shyness)
        ret = 0
        standing = 0
        for k, s in enumerate(shyness):
            if k > standing:
                ret += k - standing
                standing = k
            standing += s
        print "Case #%d: %d" % (t + 1, ret)