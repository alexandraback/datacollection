#!/bin/python3

INF = (10**20, "x", "x")

NUMBER = '0123456789'

def trySolve(n, c, j):
    ac = []
    for i in range(n):
        if c[i] == '?' and j[i] == '?':
            ac.append('0')
        elif c[i] == '?':
            ac.append(j[i])
        elif j[i] == '?':
            ac.append(c[i])
        elif c[i] == j[i]:
            ac.append(c[i])
        else:
            return INF
    aj = ac.copy()
     
    if (n == len(c)):
        return (0, ''.join(ac), ''.join(aj))
    
    tans = INF
    
    for a in NUMBER:
        if (c[n] != '?') and (c[n] != a):
            continue
        #print('xxx {0} {1} {2}'.format(c[n], a, n))

        for b in NUMBER:
            if a == b:
                continue
            if (j[n] != '?') and (j[n] != b):
                continue
            ac = ac[:n]
            ac.append(a)
            aj = aj[:n]
            aj.append(b)
            for i in range(n+1, len(c)):
                ac.append(c[i] if c[i] != '?' else ('9' if a < b else '0'))
                aj.append(j[i] if j[i] != '?' else ('0' if a < b else '9'))
            
            sc = ''.join(ac)
            sj = ''.join(aj)
            tans2 = (abs(int(sc)-int(sj)), sc, sj)
            tans = min(tans, tans2)

    return tans     

def solveTest(C, J):
    ans = INF
    for i in range(len(C)+1):
        tans = trySolve(i, C, J)
        ans = min(ans, tans)
    #print("{0} {1}".format(C, J))
    #print("{0} {1}".format(ans[1], ans[2]))
#    print("{0} {1} {3} | {2} {4}".format(ans[0], ans[1], ans[2], C, J))
    return ans[1] + ' ' + ans[2]


def solve():
    T = int(input())
    for t in range(1, T+1):
        C, J = input().split()
        #solveTest(C, J)
        print("Case #{0}: {1}".format(t, solveTest(C, J)))

        
        #N , J = map(int, input().split())
        #for i in range(J):
        #    v = i+1
        #    str1 = bin(v)[2:]+"1"
        #    jamcoin = str1 + ("0" * (N - 2*len(str1))) + str1
        ##    for i in range(2, 11):
        #        ans += " " + str(int(str1, i))
        #    print(ans)

solve()
