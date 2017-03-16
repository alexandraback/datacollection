inf = open('input.txt', 'r')
ouf = open('output.txt', 'w')

t = int(inf.readline())

for p in range(t):
    x, r, c = map(int, inf.readline().split())
    if r > c:
        (r, c) = (c, r)
    if r*c % x != 0 or x >= 7:
        print('Case #',p + 1, ':',' ','RICHARD', sep = '', file = ouf)
    elif x == 1 or x == 2:
        print('Case #',p + 1, ':',' ','GABRIEL', sep = '', file = ouf)
    elif x == 3:
        if r > 1 and c > 1:
            print('Case #',p + 1, ':',' ','GABRIEL', sep = '', file = ouf)
        else:
            print('Case #',p + 1, ':',' ','RICHARD', sep = '', file = ouf)
    elif x == 4:
        if r > 2 and c > 2:
            print('Case #',p + 1, ':',' ','GABRIEL', sep = '', file = ouf)
        else:
            print('Case #',p + 1, ':',' ','RICHARD', sep = '', file = ouf)
    elif x == 5:
        if (r >= 4 and c >= 4) or (r == 3 and c == 10) or (r == 3 and c == 15) or (r == 3 and c == 20):
            print('Case #',p + 1, ':',' ','GABRIEL', sep = '', file = ouf)
        else:
            print('Case #',p + 1, ':',' ','RICHARD', sep = '', file = ouf)
    elif x == 6:
        if r >= 4 and c >= 4:
            print('Case #',p + 1, ':',' ','GABRIEL', sep = '', file = ouf)
        else:
            print('Case #',p + 1, ':',' ','RICHARD', sep = '', file = ouf)
    
        
inf.close()
ouf.close()