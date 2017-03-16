T = input()
for TC in range(1, T+1):
    print "Case #%d:" % TC,

    N = input()
    datas = []
    for i in range(N):
        datas.append(map(int, raw_input().split()))

    if (N == 1 and datas[0][1] == 1):
        print 0
        continue

    if N == 1:
        d1, s1 = datas[0][0], datas[0][2]
        d2, s2 = datas[0][0], datas[0][2] + 1
    else:
        d1, s1 = datas[0][0], datas[0][2]
        d2, s2 = datas[1][0], datas[1][2]

    if d1 > d2:
        d1, s1, d2, s2 = d2, s2, d1, s1

    # parallel
    if s1 == s2:
        print 0
        continue

    s1 = 360.0 / s1
    s2 = 360.0 / s2

    # d2 (front) faster
    if s2 > s1:
        dd = (d1  - d2 + 360) / (s2 - s1) * s1
        if dd >= 360.0:
            print 0
            continue
        else:
            print 1
            continue

    # d1 (rear) faster
    else:
        dd = (d1  - d2 - 360) / (s2 - s1) * s2
        if dd >= 360.0:
            print 0
            continue
        else:
            print 1
            continue
