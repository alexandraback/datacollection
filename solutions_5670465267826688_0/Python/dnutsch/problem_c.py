#!/usr/bin/python

mult_table = [1,2,3,4,
2,-1,4,-3,
3,-4,-1,2,
4,3,-2,-1]

val_map = {
    'i' : 2,
    'j' : 3,
    'k' : 4
}

def factor(total, a):
    '''
        for a . b = total, find b
    '''
    sgn = -1 if a < 0 else 1
    row = (abs(a)-1) * 4
    for i in range(4):
        if mult_table[row+i] == total:
            return (i+1) * sgn
    return None # no factor

def mult (a,b):
    sgn = -1 if a < 0 and b > 0 or a > 0 and b < 0 else 1;
    idx = (abs(a)-1) * 4 + (abs(b)-1)
    return sgn* mult_table[idx]

def product (a):
    p = a[0]
    for i in xrange(1,len(a)):
        p = mult(p, a[i])
    return p

f = open('C-small-attempt0.in','r');
out = open('C.small.out','w');
T = int(f.readline().strip())

for t in xrange(0,T):
    L, X = [int(x) for x in f.readline().strip().split(' ')]
    c = [val_map[x] for x in f.readline().strip()]
    repeats = 4 if X%4 == 0 else X%4 + 4
    repeats = min(X, repeats)
    c= c * repeats
    total= product(c)

    partitions_to_check=[]
    found = False

    # find partition for i, i
    p = c[0]
    for i in xrange(1,len(c)):

        jk = factor(total, p)
        # if jk could be factored, and p is i and and jk = i
        if jk and p == 2 and jk == 2 or p == -2 and jk == 2:
            partitions_to_check.append(i)
        p = mult(p, c[i])

    for partition in partitions_to_check:
        p = c[partition]
        for i in xrange(partition+1, len(c)):
            k = factor(2,p);
            if k and p == 3 and k == 4:
                found = True
                break
            p = mult(p, c[i])
        if found:
            break;

    out.write( "Case #{}: {}\n".format(t+1, "YES" if found else "NO"))

f.close()
out.close()

