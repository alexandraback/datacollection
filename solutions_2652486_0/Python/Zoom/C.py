import sys,math
from decimal import *

f = open(sys.argv[1],'r')
T = int(next(f))

def valuation(n,p):
    answer = 0
    while(n%p == 0):
        answer += 1
        n /= p
    return answer

def find_original_set_size_3(a):
    cur = 0
    ans = [1,1,1]
    
    if(8 in a): return [2,2,2]

    for i in [1,2,3]:
        for x in a:
            if(valuation(x,2) == i):
                if(i == 2 and not (2 in ans)): 
                    ans[cur] = 4
                else:
                    ans[cur] = 2
                cur += 1
                break
        if(cur == 3): return ans
        for x in a:
            if(valuation(x,3) >= i):
                ans[cur] = 3
                cur += 1
                break
        if(cur == 3): return ans
                
        for x in a:
            if(valuation(x,5) >= i):
                ans[cur] = 5
                cur += 1
                break
        if(cur == 3): return ans

    if(1 in ans):
        return [2,2,2]

a = next(f).split(" ")
R,N,M,K = int(a[0]),int(a[1]),int(a[2]),int(a[3])
print("Case #1:")
for i in range(R):
    a = list(map(int,next(f).split(" ")))
    ans = find_original_set_size_3(a)
    #print(ans)
    print("".join(list(map(str,ans))))
