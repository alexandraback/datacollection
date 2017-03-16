#!/usr/bin/env python3

################################################################################

def read_int():
    return int(input())


def read_words():
    return input().split()


def parse(f):
    return [f(x) for x in read_words()]


def read_ints():
    return parse(int)


def read_floats():
    return parse(float)


################################################################################

def e(s,i,pfxs):
    if i == len(s):
        return pfxs

    npfxs = []
    if s[i] == '?':
        npfxs.extend([x*10 + i for i in range(10) for x in pfxs ])
    else:
        npfxs.extend( map(lambda x : x * 10 + int(s[i]), pfxs) )

    return e(s,i+1,npfxs)
    
# str -> [int]
def expand(s):
    return e(s,0,[0])
        

def solve(a,b):
    ae = expand(a)
    be = expand(b)

    md = 10000
    cs = 10000
    js = 10000
    
    for i in ae:
        for j in be:
            df = abs(i-j)
            if df < md or (df == md and (i<cs or (i==cs and j<js))):
                md = df
                cs = i
                js = j

    pattern = '{0:0' + str(len(a)) + 'd}';
    return ' '.join([pattern.format(n) for n in [cs,js] ])


for C in range(read_int()):
    [a,b] = input().split()
    R = solve(a,b)
    print("Case #{}: {}".format(C + 1, R))
