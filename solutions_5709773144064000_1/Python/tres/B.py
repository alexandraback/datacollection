import math
for t in range(1,int(input())+1):
    C,F,X=map(float,input().split())
    n=max(0,math.ceil((F*X-2*C)/(C*F)-1))
    result=X/(2+F*n)+C*sum(1/(2+F*k) for k in range(n))
    print('Case #{0}: {1}'.format(t, result))
