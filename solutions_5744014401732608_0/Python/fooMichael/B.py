import math
t = int(input())  
for i in range(1, t + 1):    
    b, m = [int(si) for si in input().split()]
    
    # 1 2 3 4 5 6
    #2, 3, 4, 5, 6
    #1, 2, 4, 8, 16
##    lg2m = math.log2(m)
##    lg2mi = int(lg2m)
##    lgdif = lg2m - lg2mi
    
##    maxv = 2 ** (b - 2)
##    if m > maxv:# or (lgdif != 0):
##        res = 'IMPOSSIBLE'
##    else:
##        res = 'POSSIBLE'
    res = 'POSSIBLE'    
    
    matx = [[0 for j in range(b)] for i in range(b)]
    matx[0][b - 1] = 1
    m -= 1
    
    bj = 1
    while m > 0:
        if bj < (b - 1):
            matx[0][bj] = 1
            matx[bj][b - 1] = 1
            m -= 1
            bj += 1
        else:
            break                                

    bi = 1
    bj = 2
    while m > 0:
        if bj < (b - 1):
            matx[bi][bj] = 1
            m -= 1
            bj += 1
        else:
            bi += 1
            bj = bi + 1
        if bi >= b - 1:
            res = 'IMPOSSIBLE'
            #print('error')
            break

    print('Case #{}: {}'.format(i, res))
    if res == 'POSSIBLE':
        for j in range(b):
            print(''.join([str(ni) for ni in matx[j]]))

        
