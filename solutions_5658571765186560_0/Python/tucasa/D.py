D = {1: (1, 1), 2: (1, 2), 3: (2, 3), 4: (3, 4)}

if __name__ == '__main__':
    T = int(raw_input())
    for t in xrange(1, T + 1):
        X, R, C = map(int, raw_input().split())
        if (R * C) % X:
            print "Case #%d: RICHARD" % t
            continue
        ryouhou, katahou = D[X]
        if min(R, C) >= ryouhou and max(R, C) >= katahou:
            print "Case #%d: GABRIEL" % t
        else:
            print "Case #%d: RICHARD" % t