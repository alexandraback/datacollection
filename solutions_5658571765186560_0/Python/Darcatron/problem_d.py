for trial in range(int(raw_input())):

    X, R, C = map(int, raw_input().split(' '))

    ans = True # Gabriel

    if X >= 7:
        ans = False # Richard
    elif X > R and X > C:
        ans = False # Richard
    elif R * C % X != 0:
        ans = False # Richard
    elif (X + 1) // 2 > min(R, C):
        ans = False # Richard
    elif X in (1, 2, 3):
        ans = True # Gabriel
    elif X == 4:
        ans = min(R, C) > 2
    elif X == 5:
        ans = not(min(R, C) == 3 and max(R, C) == 5)
    elif X == 6:
        ans = min(R, C) > 3

    print 'Case #%d:' % (trial + 1), 'GABRIEL' if ans else 'RICHARD'