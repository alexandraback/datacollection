mod = 1000000007
F = [1] * 101

for i in range(2, 101):
    F[i] = (F[i-1] * i) % mod

C = [0] * 26
q = 0

def pos(c):
    return ord(c) - ord('a')

def unique(w):
    for i in xrange(1, len(w)):
        if w[i] != w[i-1]:
            return False
    return True

B = [0] * 26
M = [0] * 26
E = [0] * 26
valid = True

def proc(w):
    global C, B, E, M, q, valid
    if unique(w):
        C[pos(w[0])] += 1
    else:
        B[pos(w[0])] += 1
        E[pos(w[-1])] += 1
        for i in xrange(1, len(w)):
            if w[i] != w[i-1]:
                M[pos(w[i])] += 1
                q -= 1
                valid = valid and w[i] != w[0]


tc = int(raw_input())
for caso in xrange(1, tc+1):
    print 'Case #%d:' % (caso),
    n = int(raw_input())
    W = raw_input().split()
    C = [0] * 26
    B = [0] * 26
    E = [0] * 26
    M = [0] * 26
    q = 0
    valid = True
    for w in W:
        proc(w)
    #print q
    ans = 1
    for i in xrange(26):
        valid = valid and B[i] < 2 and M[i] < 2 and B[i] + M[i] - E[i] < 2
        if C[i]:
            valid = valid and not M[i] - E[i]
        ans *= F[C[i]]
        if B[i] or M[i] or C[i]:
            q += 1
    ans *= F[q]
    ans %= mod
    print ans if valid else 0
