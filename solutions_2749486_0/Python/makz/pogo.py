for t in range(input()):
    print "Case #%s:" % str(t + 1),
    x, y = map(int, raw_input().split())
    n = 0
    path = ''
    while (x != 0 or y != 0) and n <= 500:
        n += 1
        if x == n:
            x -= n
            path += 'E'
        elif x == -n:
            x += n
            path += 'W'
        elif y == -n:
            y += n
            path += 'S'
        elif y == n:
            y -= n
            path += 'N'
        elif x != 0:
            if (abs(x) > n and x < 0) or (abs(x) < n and x > 0):
                x += n
                path += 'W'
            else:
                x -= n
                path += 'E'
        else:
            if (abs(y) > n and y < 0) or (abs(y) < n and y > 0):
                y += n
                path += 'S'
            else:
                y -= n
                path += 'N'
    print path




