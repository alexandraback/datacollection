T = int(raw_input())
for t in range(T):
    X, R, C = map(int, raw_input().split())
    if R * C % X != 0:
        r = 'NO'
    elif X <= 2:
        r = 'YES'
    elif (R == 1 or C == 1) or (X == 4 and (R, C) in [(2, 2), (2, 4), (4, 2)]):
        r = 'NO'
    else:
        r = 'YES'
    print 'Case #%d: %s' % (t + 1, 'GABRIEL' if r == 'YES' else 'RICHARD')
