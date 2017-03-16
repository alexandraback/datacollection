FILE_PATH = 'C:\\codejam\\'
FILE_NAME = 'B-small-attempt0'

f = open(FILE_PATH + FILE_NAME + '.in', 'r')
o = open(FILE_PATH + FILE_NAME + '.out', 'w')

def Count(G) :
    n = len(G)
    P = [0] * n
    P[-1] = 1
    for i in range(n-2, -1, -1) :
        for j in range(n - i - 1) :
            if ((2**j) & G[i]) != 0:
                P[i] += P[n - j - 1]
    return P[0]
def solve(G, B, M) :
    if len(G) == B :
        return Count(G) == M
    elif len(G) == B-1 :
        G.append(0)
        if solve(G, B, M) :
            return True
        G.pop(-1)
        return False

    k = 2**(B - len(G))
    for i in range(k) :
        G.append(i)
        if solve(G, B, M) :
            return True
        G.pop(-1)
    return False
def case_result(case) :
    print(case)
    B, M = map(int, f.readline().split())

    G = []
    ret = solve(G, B, M)
    if ret :
        ans = 'POSSIBLE'
        for b in G :
            s = bin(b)[2:]
            ans += '\n' + '0'*(B-len(s)) + s
    else :
        ans = 'IMPOSSIBLE'
    return ans

T = int(f.readline())
for case in range(1, T+1) :
    o.write('Case #'+str(case)+': '+case_result(case)+'\n')
 
f.close()
o.close()
 