def isGood(point, p):
    if point == 0:
        if p > 0:
            return (0,0)
        else:
            return (1,0)
        
    if point % 3 == 0:
        if point / 3 >= p:
            return (1,0)
        elif point / 3 + 1 >= p:
            return (0,1)
        else:
            return (0,0)
    elif point % 3 == 1:
        if point / 3 + 1 >= p:
            return (1,0)
        else:
            return (0,0)
    else:
        if point / 3 + 1 >= p:
            return (1,0)
        elif point / 3 + 2 >= p:
            return (0,1)
        else:
            return (0,0)
            
T = int(raw_input());
for iCase in range(T):
    line = raw_input();
    items = line.split(' ')
    N, S, p = int(items[0]), int(items[1]), int(items[2])
    points = [int(items[3+i]) for i in range(N)]
    num, s = 0, 0
    for point in points:
        a, b = isGood(point, p)
        num, s = num + a, s + b
    num += min(s, S)
    print "Case #%d: %d" %(iCase+1, num)

