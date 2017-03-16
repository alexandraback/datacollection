import sys
from fractions import gcd
fileName = 'D-small-attempt0'
sys.stdin = open('F:/Desktop/' + fileName + '.in' , 'r')
sys.stdout = open('F:/Desktop/' + fileName + '.out' , 'w')

T = int(input()) 
for case in range(1 , 1 + T) :
    line = input().split()
    H , W , D = int(line[0]) , int(line[1]) , int(line[2])
    m = []
    for i in range (H) :
        m.append(input())
        assert(len(m[i]) == W)
    
    arr = []
    h2 = (H - 2) * 2
    w2 = (W - 2) * 2
    for i in range (-(int(D / h2) + 3) , int(D / h2) + 3) : 
        for j in range (-(int(D / w2) + 3) , int(D / w2) + 3) :
            arr.append((i * h2 , j * w2))
    
    R = C = -1
    for i in range (H) :
        for j in range (W) :
            if (m[i][j] == 'X') :
                R , C = i , j
                break
    
    u = 2 * R - 1
    l = 2 * C - 1 ;
    
    for p in arr[:] :
        arr.append((p[0] - u , p[1]))
        arr.append((p[0] - u , p[1] - l))
        arr.append((p[0] , p[1] - l))
    
    arr2 = set()
    for p in arr :
        if p[0] * p[0] + p[1] * p[1] <= D * D :
            g = abs(gcd(p[0] , p[1]))
            if(g != 0) :
                arr2.add((p[0] / g , p[1] / g))
    
    cnt = len(arr2)
    print ('Case #%d:'%case , cnt)