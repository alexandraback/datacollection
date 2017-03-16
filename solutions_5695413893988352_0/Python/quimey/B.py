def gen(s):
    ans = []
    for j in range(1000):
        u = str(j)
        if len(u) <= len (s):
            while len(u) < len(s):
                u = '0' + u
            sirve = True
            for i in range(len(s)):
                if u[i] != s[i] and s[i] != '?':
                    sirve = False
            if sirve: ans.append(u)
    return ans
            
def check(s, t):
    a = gen(s)
    b = gen(t)
    m = 10000
    for x in a:
        for y in b:
            if abs(int(x)-int(y)) < m:
                m = abs(int(x)-int(y))
                ma = x
                mb = y
    return (ma, mb, m)

T = input()
for t in range(T):
    C, J = raw_input().split()
    n = len(C)
    r = 1
    u = ""
    v = ""
    for i in range(n):
        if C[i] == '?' and J[i] == '?':
            if r == 0:
                u += '0'
                v += '9'
            elif r == 1:
                u += '0'
                v += '0'
            else:
                u += '9'
                v += '0'
        elif C[i] == '?':
            if r == 0:
                u += '0'
                v += J[i]
            elif r == 1:
                u += J[i]
                v += J[i]
            else:
                u += '9'
                v += J[i]
        elif J[i] == '?':
            if r == 0:
                u += C[i]
                v += '9'
            elif r == 1:
                u += C[i]
                v += C[i]
            else:
                u += C[i]
                v += '0'
        else:
            if C[i] < J[i] and r == 1:
                r = 2
            elif C[i] > J[i] and r == 1:
                r = 0
            u += C[i]
            v += J[i]
    u, v, m = check(C, J)
    print "Case #%d: %s %s" % (t + 1, u, v)
    

