inf = open('input.txt', 'r')
ouf = open('output.txt', 'w')

t = int(inf.readline())
for i in range(t):
    x, r, c = map(int, inf.readline().split())
    if (r*c % x) != 0:
        print(1)
        print('Case #', end = '', file = ouf)
        print(i + 1, end = '', file = ouf)
        print(':', end = ' ', file = ouf)
        print('RICHARD', file = ouf)
    elif x == 1:
        print('Case #', end = '', file = ouf)
        print(i + 1, end = '', file = ouf)
        print(':', end = ' ', file = ouf)	
        print('GABRIEL', file = ouf)
    elif x == 2:
        print('Case #', end = '', file = ouf)
        print(i + 1, end = '', file = ouf)
        print(':', end = ' ', file = ouf)	
        print('GABRIEL', file = ouf)
    elif x == 3 and r*c >= 6:
        print('Case #', end = '', file = ouf)
        print(i + 1, end = '', file = ouf)
        print(':', end = ' ', file = ouf)	
        print('GABRIEL', file = ouf)
    elif x == 4 and r*c >= 12:
        print('Case #', end = '', file = ouf)
        print(i + 1, end = '', file = ouf)
        print(':', end = ' ', file = ouf)	
        print('GABRIEL', file = ouf)
    else:
        print('Case #', end = '', file = ouf)
        print(i + 1, end = '', file = ouf)
        print(':', end = ' ', file = ouf)
        print('RICHARD', file = ouf)
                
                    
        
inf.close()
ouf.close()


