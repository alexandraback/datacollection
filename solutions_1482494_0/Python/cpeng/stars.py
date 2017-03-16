import sys


def rounds(starreq):
    star = 0
    a, b = [], []
    for k, val in starreq.iteritems():
        a.append((val[0], k))
        b.append((val[1], k))
    a.sort()
    b.sort()

    res = 0
    while starreq:
        if len(b) > 0 and star >= b[0][0]:
            res += 1
            level = b[0][1]
            del b[0]
            if len(starreq[level]) == 2:
                star += 2
            else:
                star += 1
            del starreq[level]
        elif len(a) > 0 and star >= a[0][0]:
            m = 0
            mindex = 0
            for (ind, (req, level)) in enumerate(a):
                if req > star:
                    break
                if level in starreq and starreq[level][1] > m:
                    m = starreq[level][1]
                    mindex = ind

            level = a[mindex][1]
            del a[mindex]
            if level not in starreq:
                continue
            res += 1
            star += 1
            starreq[level] = (starreq[level][1],)
        else:
            return -1
    return res


# a = {0:(0, 5), 1:(6, 6), 2:(6, 11),
# a = {0: (1, 11),
#      1: (5, 17),
#      2: (5, 13),
#      3: (1, 1),
#      4: (4, 14),
#      5: (1, 9),
#      6: (0, 11),
#      7: (3, 10),
#      8: (14, 16)}

s = sys.stdin.readlines()

T = int(s[0])
ss = (line.strip() for line in s[1:])

for t in range(T):
    N = int(ss.next())
    d = {}
    for i in range(N):
        a, b = map(int, ss.next().split())
        d[i] = (a, b)
    res = rounds(d)
    if res == -1:
        res = 'Too Bad'
    print 'Case #' + str(t+1) + ':', res
