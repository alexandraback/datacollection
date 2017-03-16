import sys
import time



    
for tc in range(int(input())):
    K,C,S = input().split(' ')
    K = int(K)
    C = int(C)
    S = int(S)

    if S<K-1:
        print("Case #" + str(tc+1) + ": IMPOSSIBLE")
        continue

    if K == S:
        _list = [str(1+pow(K,(C-1))*i) for i in range(K)]
        res = ' '.join(_list)
        print("Case #" + str(tc+1) + ": " + res)
        continue

    #S == K-1:

    if C == 1:
        print("Case #" + str(tc+1) + ": IMPOSSIBLE")
        continue

    # C = 2:
    base = list(range(2,K+1))

    _list = [str(pow(K,(C-2))*i) for i in base]
    res = ' '.join(_list)
    print("Case #" + str(tc+1) + ": " + res)
