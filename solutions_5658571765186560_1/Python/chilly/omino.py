with open('input', 'r') as f:
    num = int(f.readline())
    data = f.readlines()
    for idx, row in enumerate(data):
        x, r, c = map(int, row.strip().split(' '))
        if r*c % x != 0:
            print 'Case #' + str(idx+1) + ': RICHARD'
        elif x >= 7:
            print 'Case #' + str(idx+1) + ': RICHARD'
        else:
            longside = max(r, c)
            shortside = min(r, c)
            if shortside < (x/2 + x%2):
                print 'Case #' + str(idx+1) + ': RICHARD'
            else:
                if x == 4 and shortside < 3:
                    print 'Case #' + str(idx+1) + ': RICHARD'
                elif x == 5 and shortside < 4:
                    print 'Case #' + str(idx+1) + ': RICHARD'
                elif x == 6 and shortside < 4:
                    print 'Case #' + str(idx+1) + ': RICHARD'
                else:
                    print 'Case #' + str(idx+1) + ': GABRIEL'


