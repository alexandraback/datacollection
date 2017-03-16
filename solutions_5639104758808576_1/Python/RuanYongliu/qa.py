if __name__ == "__main__":
    caseno = input()
    for caseidx in xrange(1, caseno + 1):
        smax, s = raw_input().split()
        smax = int(smax)
        p = 0
        a = 0
        for i in xrange(0, smax + 1):
            si = int(s[i])
            if si == 0:
                continue
            if p < i:
                a += i - p
                p = i
            p += si

        print "Case #%d: %d" % (caseidx, a)
