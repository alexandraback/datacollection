def v(b,n):
    a = 1
    r = 0
    for i in n:
        r += a*i
        a *= b
    return r
import math
def d(n):
    for i in range(2,int(math.sqrt(n))+1):
        if n % i == 0:
            return i
    return 0
import random
def randone(n):
    k = random.randrange(2**(n-2))
    s = [1]*n
    for i in range(1,n-1):
        s[i] = k&1
        k = k >> 1
    return s
def inc(n):
    i = 1
    while s[i]:
        s[i] = 0
        i+=1
    s[i] = 1
    return s
if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n,j = map(int,input().split())
        s = [1]+[0]*(n-2)+[1]
        print('Case #%d:' % (i+1))
        while j > 0:
            ds = [ d(v(b,s)) for b in range(2,11) ]
            if 0 not in ds:
                print(v(10,s),' '.join(map(str,ds)))
                j -= 1
            inc(s)