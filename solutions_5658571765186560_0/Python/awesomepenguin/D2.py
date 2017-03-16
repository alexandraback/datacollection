t = int(raw_input())

for qq in xrange(1, t+1):
    x, r, c = map(int, raw_input().split())
    if r > c: (r, c) = (c, r)
    n = r * c

    if x == 1: winner = 'GABRIEL'
    elif x == 2:
        if n % 2 == 0: winner = 'GABRIEL'
        else: winner = 'RICHARD'
    elif x == 3:
        if r == 1 and c == 1: winner = 'RICHARD'
        elif r == 1 and c == 2: winner = 'RICHARD'
        elif r == 2 and c == 2: winner = 'RICHARD'
        elif r == 1 and c == 3: winner = 'RICHARD'
        elif r == 1 and c == 4: winner = 'RICHARD'
        elif r == 2 and c == 4: winner = 'RICHARD'
        elif r == 4 and c == 4: winner = 'RICHARD'
        else: winner = 'GABRIEL'
    else: #x = 4
        if r == 1 and c == 1: winner = 'RICHARD'
        elif r == 1 and c == 2: winner = 'RICHARD'
        elif r == 2 and c == 2: winner = 'RICHARD'
        elif r == 1 and c == 3: winner = 'RICHARD'
        elif r == 2 and c == 3: winner = 'RICHARD'
        elif r == 3 and c == 3: winner = 'RICHARD'
        elif r == 1 and c == 4: winner = 'RICHARD'
        elif r == 2 and c == 4: winner = 'RICHARD'
        else: winner = 'GABRIEL'
    
    print 'Case #%d: %s' % (qq, winner)
