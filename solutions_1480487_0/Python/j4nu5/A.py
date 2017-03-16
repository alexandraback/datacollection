t = input()
c = 1

while t:
    case = [int(i) for i in raw_input().split()]
    n = case.pop(0)
    
    sum_points = sum(case)
    
    ans = float(2 * sum_points) / n
    x = [ans for i in xrange(n)]
    
    y = [(x[i] - case[i]) / sum_points for i in xrange(n)]
    
    for i in y:
        if i < 0:
            y = [0] * n
            break
    
    print 'Case #%d:' % (c, ),
    for i in y:
        print '%.6f' % (round(i * 100, 6),),
    print
    
    t -= 1
    c += 1

