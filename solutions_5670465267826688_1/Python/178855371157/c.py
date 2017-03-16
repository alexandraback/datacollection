import sys

i = 2
j = 3
k = 4

P = [
    [],
    [ 0,  1,  i,  j,  k ],
    [ 0,  i, -1,  k, -j ],
    [ 0,  j, -k, -1,  i ],
    [ 0,  k,  j, -i, -1 ]
]

def mult(x, y):
    if x < 0 and y < 0:
        return P[-x][-y]
    elif x < 0:
        return -P[-x][y]
    elif y < 0:
        return -P[x][-y]
    else:
        return P[x][y]

def read(c):
    if c == '1':
        return 1
    if c == 'i':
        return i
    if c == 'j':
        return j
    if c == 'k':
        return k
    
def find(target, p, seq):
    ret = 0
    while True:
        if p == target:
            return ret
        if ret == len(seq):
            return -1
        p = mult(p, seq[ret])
        ret += 1

def prod(seq):
    ret = 1
    for v in seq:
        ret = mult(ret, v)
    return ret

def pow(v, n):
    if n == 0:
        return 1
    if n == 1:
        return v
    if n == 2:
        return mult(v, v)    
    if n % 2 == 0:
        return pow(pow(v,2), n/2)
    if n % 2 == 1:
        return mult(pow(pow(v,2), n/2), v)

T = int(sys.stdin.readline())

for n in range(1, T+1):
    [L, X] = [int(p) for p in sys.stdin.readline().split()]     
    S = [read(c) for c in sys.stdin.readline()[:-1]]

    # Find the first i.
    suffix = S * min(8, X)
    X -= min(8, X)
    pos = find(i, 1, suffix)
    if pos == -1:
        print "Case #{}: NO".format(n)
        continue
    suffix = suffix[pos:]

    # Find the next j.
    suffix += S * min(8, X)
    X -= min(8, X)
    pos = find(j, 1, suffix)
    if pos == -1:
        print "Case #{}: NO".format(n)
        continue
    suffix = suffix[pos:]

    # Is the remaining product k?
    if mult(prod(suffix), pow(prod(S), X)) == k:
        print "Case #{}: YES".format(n)
    else:
        print "Case #{}: NO".format(n)
