import sys
p = [ -1 for i in range(31) ]
q = list(p)

for i in range(11):
    for j in range(3):
        t1 = i + j
        if t1 <= 10:
            for k in range(3):
                t2 = t1 + k
                if t2 <= 10 and j + k <= 2:
                    total = i + t1 + t2
                    if (j == 2 or k == 2 or j + k == 2):
                        p[total] = max(p[total], t2)
                    else:
                        q[total] = max(q[total], t2)

case = int(raw_input())
for T in range(1,case+1):
    data = raw_input().split()
    N = int(data[0])
    S = int(data[1])
    p_atleast = int(data[2])
    t = [ int(i) for i in data[3:] ]
    f = [ [ 0 for j in range(S+1) ] for i in range(N+1) ]
    for i in range(1,N+1):
        j_limit = min(S,i)
        if (p[t[i - 1]] >= p_atleast):
            add = 1
        else:
            add = 0
        for j in range(1,j_limit+1):
            f[i][j] = max(f[i][j], f[i-1][j-1] + add)

        if (q[t[i - 1]] >= p_atleast):
            add = 1
        else:
            add = 0
        for j in range(j_limit+1):
            f[i][j] = max(f[i][j], f[i-1][j] + add)
    print("Case #%d: %d" %(T, f[N][S]))


