from collections import defaultdict
t = int(raw_input())
mat = defaultdict(dict)
# 1,i,j,k = 1,2,3,4
mat[1][1] = 1
mat[1][2] = 2
mat[1][3] = 3
mat[1][4] = 4
mat[2][1] = 2
mat[2][2] = -1
mat[2][3] = 4
mat[2][4] = -3
mat[3][1] = 3
mat[3][2] = -4
mat[3][3] = -1
mat[3][4] = 2
mat[4][1] = 4
mat[4][2] = 3
mat[4][3] = -2
mat[4][4] = -1
def mul(x, y):
    return mat[abs(x)][abs(y)] * (-1 if x*y < 0 else 1)
for kei in xrange(t):
    l, x = [int(x) for x in raw_input().split()]
    orig = raw_input()
    s = [{"i":2, "j":3, "k":4}[c] for c in orig]
    curr = 1
    for c in s:
        curr = mul(curr, c)
    if curr == -1:
        neg = x%2 == 1
    elif curr == 1:
        neg = False
    else:
        neg = x%2 == 0 and x%4 != 0
    # print(curr, x, neg)
    if neg:
        pi, pk = l*x+1, -1
        m = min(4, x)
        curr = 1
        for i in xrange(m*l):
            curr = mul(curr, s[i%l])
            if curr == 2:
                pi = i
                break
        curr = 1
        for i in xrange(m*l-1, -1, -1):
            curr = mul(s[i%l], curr)
            if curr == 4:
                pk = x*l-1-(m*l-1 - i)
                break
        res = pi+1 < pk
    else:
        res = False
    if res:
        w = orig*x
        # print w[:pi+1], w[pi+1:pk], w[pk:]
        print "Case #%d: YES" % (kei+1)
    else:
        # print neg
        print "Case #%d: NO" % (kei+1)
            

