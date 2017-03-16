mulString = """\
 1  i  j  k -1 -i -j -k
 i -1  k -j -i  1 -k  j
 j -k -1  i -j  k  1 -i
 k  j -i -1 -k -j  i  1
-1 -i -j -k  1  i  j  k
-i  1 -k  j  i -1  k -j
-j  k  1 -i  j -k -1  i
-k -j  i  1  k  j -i -1"""
mulTable = [l.split() for l in mulString.split('\n')]
mul = {(mulTable[i][0],mulTable[0][j]):mulTable[i][j] for i in xrange(8) for j in xrange(8)}

def solve(L,X,s):
    cur = '1'
    for x in s: cur = mul[cur,x]
    end = '1'
    for _ in xrange(X%4): end = mul[end,cur]
    if end!='-1':
        return False
    cur = '1'
    for i,x in enumerate(s*4):
        cur = mul[cur,x]
        if cur=='i':
            I = i
            break
    else:
        return False
    cur = '1'
    for i,x in enumerate(reversed(s*4)):
        cur = mul[x,cur]
        if cur=='k':
            K = i
            break
    else:
        return False
    return I+K+1<X*L

for t in xrange(input()):
    L,X = map(int,raw_input().split())
    s = raw_input().strip()
    print "Case #%d: %s"%(t+1,["NO","YES"][solve(L,X,s)])
