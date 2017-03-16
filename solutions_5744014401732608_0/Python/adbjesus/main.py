def fac(N):
    r = 1
    for i in range(2,N+1):
        r *= i
    return r

def max(N):
    ret = 1
    n = N-2
    for r in range(1,N-1):
        ret += fac(n) / fac(r) / fac(n-r)

    return ret    

def solve():
    B, M = [int(i) for i in raw_input().split()]
    
    ret = ""
    MAX = max(B)
    if M > MAX:
        return "IMPOSSIBLE"

    mat = []
    for b in range(B):
        mat.append([0]*B)

    m = 1
    mat[0][B-1] = 1
    
    while m < M:
        for i in range(B-1):
            for j in range(i+1,B-1):
                mat[i][j]=1
                mat[j][B-1]=1
                m += 1
                if m == M:
                    break
            if m == M:
                break

    for m in mat:
        ret += '\n'
        ret += ''.join([str(i) for i in m])

    return "POSSIBLE"+ret 

T = int(raw_input())
for t in range(1,T+1):
    print("Case #%d: %s" % (t,solve()))
