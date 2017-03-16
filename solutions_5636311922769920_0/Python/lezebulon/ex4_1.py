import sys
import time



    
for tc in range(int(input())):
    K,C,S = input().split(' ')
    K = int(K)
    C = int(C)

    _list = [str(1+pow(K,(C-1))*i) for i in range(K)]
    res = ' '.join(_list)
    print("Case #" + str(tc+1) + ": " + res)
