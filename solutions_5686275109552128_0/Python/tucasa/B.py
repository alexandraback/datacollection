import bisect

if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(1, T + 1):
        D = int(raw_input())
        P = map(int, raw_input().split())
        P.sort()
        tmp = P[::]
        ret = P[-1]
        count = 0
        while P[-1] > 1:
            # print P[-1], count, P
            ret = min(ret, count + P[-1])
            x = P.pop()
            P.insert(bisect.bisect_left(P, (x + 1) / 2), (x + 1) / 2)
            P.insert(bisect.bisect_left(P, x / 2), x / 2)
            count += 1
        ret = min(ret, count + P[-1])

        count = 0
        P = tmp
        while P[-1] > 1:
            # print P[-1], count, P
            ret = min(ret, count + P[-1])
            x = P.pop()
            if x == 9:
                P.insert(bisect.bisect_left(P, 3), 3)
                P.insert(bisect.bisect_left(P, 3), 3)
                P.insert(bisect.bisect_left(P, 3), 3)
                count += 2
            else:
                P.insert(bisect.bisect_left(P, (x + 1) / 2), (x + 1) / 2)
                P.insert(bisect.bisect_left(P, x / 2), x / 2)
                count += 1

        ret = min(ret, count + P[-1])

        print "Case #%d: %d" % (t, ret)