import sys
I = 2
J = 3
K = 4
def c2i(c):
    if c == "i":
        return I
    if c == "j":
        return J
    if c == "k":
        return K

multable = [
    [0, 0, 0, 0, 0],
    [0, 1, I, J, K],
    [0, I, -1, K, -J],
    [0, J, -K, -1, I],
    [0, K, J, -I, -1],
]
def mul(a, b):
    sig = 1
    if a < 0:
        sig = -sig
        a = -a
    if b < 0:
        sig = -sig
        b = -b
    return sig * multable[a][b]

invtable = [None, 1, -I, -J, -K]
def inv(a):
    if a < 0:
        return -invtable[-a]
    else:
        return invtable[a]

def solve(L, X, s):
    left = [1]
    for x in s:
        left.append(mul(left[-1], x))
    right = [1]
    for x in s[::-1]:
        right.append(mul(x, right[-1]))
    right.reverse()
    whole = right[0]
    #print left
    #print right
    #print whole

    leftcands = []
    t = 1
    for j in range(4): # x^4 = 1
        for i, x in enumerate(left[:-1]):
            if mul(t, x) == I:
                leftcands.append((j, i))
        t = mul(t, whole)

    rightcands = []
    t = 1
    for j in range(4): # x^4 = 1
        for i, x in enumerate(right[:-1]):
            if mul(x, t) == K:
                rightcands.append((j, i))
        t = mul(whole, t)

    #print leftcands
    #print rightcands

    for lj, li in leftcands:
        for rj, ri in rightcands:
            #print (lj, li, right[li]), (rj, ri, left[ri])
            mj = X - lj - rj - 2
            #print mj
            if mj < -1:
                continue
            if mj == -1:
                if li < ri:
                    t = mul(right[li], inv(right[ri]))
                else:
                    continue
            else:
                t = right[li]
                for i in range(mj % 4):
                    t = mul(t, whole)
                t = mul(t, left[ri])
            #print right[li], mj, left[ri], t
            if t == J:
                return "YES"
    return "NO"

T = int(sys.stdin.readline())
for _c in range(T):
    L, X = map(int, sys.stdin.readline().strip().split())
    s = map(c2i, sys.stdin.readline().strip())
    print "Case #%d: %s" % (_c + 1, solve(L, X, s))
