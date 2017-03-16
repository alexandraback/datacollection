#f = open('A.in')
#def input():
#    return next(f)

for x in range(1, int(input()) + 1):
    R, C, W = map(int, input().split())
    #print(R, C, W)
    print('Case #%d:' % x, W + (C-1) // W)
