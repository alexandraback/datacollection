if __name__ == '__main__':
    for caseno in xrange(int(raw_input())):
        A, B = [int(s) for s in raw_input().split()]
        ps = [float(s) for s in raw_input().split()]

        candidates = []
        p = 1.0
        for i in xrange(A + 1):
            candidates += [(A - i) + (B - i) + 1 + (1 - p) * (1 + B)]
            if i < len(ps):
                p *= ps[i]

        candidates += [2 + B]

        res = min(candidates)
        print 'Case #%d: %.6f' % (caseno + 1, res)

