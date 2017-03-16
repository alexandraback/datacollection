T = int(input())

for CC in range(T):
    R, C, W = map(int,input().split())

    RowsN = C//W

    Find = False
    Ans = 0
    
    if W == 1:
        Ans = R*C
        Find = True

    if not Find:
        if C%W == 0:
            Ans = RowsN + W - 1
        else:
            Ans = RowsN + W

    print('Case #{}: {}'.format(CC+1,Ans))
