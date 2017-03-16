__author__ = 'walid'

filename = 'C-small-attempt2'
# dirname = '/Users/walid/Downloads/'
dirname = 'D:\\Downloads\\'
inFile = open(dirname+filename+'.in', 'r')
outFile = open(dirname+filename+'.out', 'w')


idx = {'1':0, 'i':1, 'j':2, 'k':3}
mult = [['1', 'i', 'j', 'k'], ['i', '1', 'k', 'j'], ['j', 'k', '1', 'i'], ['k', 'j', 'i', '1']]
signs = [[1, 1, 1, 1], [1, -1, 1, -1], [1, -1, -1, 1], [1, 1, -1, -1]]

def prod(a1, a2, s1, s2):
    return (mult[idx[a1]][idx[a2]], s1*s2*signs[idx[a1]][idx[a2]])

def pow(a, s, p):
    if(p == 0):
        return ('1', 1)
    elif(p == 1):
        return (a, s)
    else:
        (a0, s0) = pow(a, s, p//2)
        (a1, s1) = prod(a0, a0, s0, s0)
        if(p % 2 == 0):
            return (a1, s1)
        else:
            return prod(a, a1, s, s1)


def findIdx(st, a, s):
    (a1, s1) = ('1', 1)
    l = len(st)
    i = -1
    while((a1, s1) != (a, s) and i < l*4):
        i += 1
        (a1, s1) = prod(a1, st[i % l], s1, 1)
    return ((a1, s1) == (a, s), i)

def findIdxReverse(st, a, s):
    (a1, s1) = ('1', 1)
    st = list(reversed(st))
    l = len(st)
    i = -1
    while((a1, s1) != (a, s) and i < l*4):
        i += 1
        (a1, s1) = prod(st[i % l], a1, 1, s1)
    return ((a1, s1) == (a, s), i)

def process(X, st, it):
    (p, s) = ('1', 1)
    # different characters in st
    n = len(set(st))
    for c in st:
        (p, s) = prod(p, c, s, 1)
    (p, s) = pow(p, s, X)

    hasIandK = False
    if(n > 1):
        (hasI, iIdx) = findIdx(st, 'i', 1)
        (hasK, kIdx) = findIdxReverse(st, 'k', 1)
        if(hasI and hasK and (iIdx + kIdx + 2 < X*len(st))):
            hasIandK = True
        print(hasI, iIdx, hasK, kIdx, hasIandK)
    if(p == '1' and s == -1 and hasIandK):
        r = 'YES'
    else:
        r = 'NO'
    out = 'Case #{}: {}\n'.format(it, r)
    print(out)
    outFile.write(out)



Testcases = (int)(inFile.readline())

for it in range(1, Testcases+1):
    [L, X] = [(int)(a) for a in inFile.readline().strip().split(' ')]
    st = inFile.readline().strip()
    process(X, st, it)
    it += 1
