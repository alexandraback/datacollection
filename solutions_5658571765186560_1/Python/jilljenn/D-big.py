T = int(raw_input())
for t in range(T):
    X, R, C = map(int, raw_input().split())
    if R * C % X != 0:
        r = 'NO'
    elif X <= 2:
        r = 'YES'
    elif (X <= 4 and min(R, C) <= X - 2) or (X == 5 and (min(R, C) < 3 or (min(R, C) == 3 and max(R, C) < 10))) or (X == 6 and min(R, C) <= 3):
        r = 'NO'
    elif X <= 6:
        r = 'YES'
    else:
        r = 'NO'
    print 'Case #%d: %s' % (t + 1, 'GABRIEL' if r == 'YES' else 'RICHARD')
