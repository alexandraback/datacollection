for t in range(int(raw_input())):

    x, r, c = map(int, raw_input().split())

    winner = 'GABRIEL'

    if x >= 7:
        winner = 'RICHARD'
    elif x > r and x > c:
        winner = 'RICHARD'
    elif r * c % x != 0:
        winner = 'RICHARD'
    elif (x + 1) // 2 > min(r, c):
        winner = 'RICHARD'
    elif x in (1, 2, 3):
        winner = 'GABRIEL'
    elif x == 4:
        if(min(r, c) > 2):
            winner = 'GABRIEL'
        else:
            winner = 'RICHARD'
    elif x == 5:
        if(min(r, c) == 3 and max(r, c) == 5):
            winner = 'RICHARD'
        else:
            winner = 'GABRIEL'
    elif x == 6:
        if (min(r, c) > 3):
            winner = 'GABRIEL'
        else:
            winner = 'RICHARD'

    print 'Case #%d: %s' % (t + 1,winner) 