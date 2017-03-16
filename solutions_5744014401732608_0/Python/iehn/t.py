import math,string,itertools,fractions,heapq,collections,re,array,bisect,random

t = int(input())

def g(a, ff=False):
    l = len(a)
    s = [1]
    for i in range(1,l):
        ss = 0
        for j in range(i):
            if a[j][i] == 1:
                ss += s[j]
        s.append(ss)
    if ff:
        print(s)
    return s[-1]

for i in range(1,t+1):
    b,m = list(map(int, input().split()))
    a = [[0]*b for _ in range(b)]
    f = False
    for rr in range(3000):
        for j in range(b):
            for k in range(j+1,b):
                if rr < 500:
                    a[j][k] = 1
                else:
                    a[j][k] = random.randint(0,1)

        h = g(a)
        while h > m:
            rj = random.randint(0,m-1)
            rk = random.randint(0,m-1)
            ff = False
            for j in range(rj,rj+b):
                if ff:
                    break
                j = j%b
                for k in range(rk,rk+b):
                    k = k%b
                    if a[j][k] == 1:
                        a[j][k] = 0
                        ff = True
                        break
            if not ff:
                break
            h = g(a)

        if h == m:
            f = True
            break

    if f:
        print("Case #{0}: {1}".format(i, "POSSIBLE"))
        print("\n".join(["".join(map(str, aa)) for aa in a]))
    else:
        print("Case #{0}: {1}".format(i, "IMPOSSIBLE"))
