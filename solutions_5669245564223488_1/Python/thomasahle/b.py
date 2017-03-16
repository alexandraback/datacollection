import sys
from itertools import groupby
from string import lowercase
read = lambda t=int: list(map(t,sys.stdin.readline().split()))
T, = read()

def parse_train(t):
    parts = list(groupby(t))
    inner = set(k for k,g in parts[1:-1])
    return (parts[0][0], inner, parts[-1][0])

def inner_problem(ts):
    for t in ts:
        # abba
        if t[1] and t[0] == t[2]:
            # print(t,)
            return True
        # aba ba, ababa
        for y in ts:
            if y[0] in t[1] or y[2] in t[1]:
                # print(t,y)
                return True
    return False

def loop_check(normals):
    for c in lowercase:
        x = c
        while True:
            t = [y for y in normals if y[0] == x]
            if not t:
                # good
                break
            if t[0][2] == c:
                # loop
                return True
            x = t[0][2]
    return False


MOD = 1000000007
facts = [1]
for k in range(1,10000):
    facts.append(facts[-1]*k % MOD)

def solve(ts):
    if inner_problem(ts):
        return 0

    # dummies = [t for t in ts if t[0] == t[2]]
    normals = [t for t in ts if t[0] != t[2]]

    dums = {c: len([t for t in ts if t[0]==t[2]==c]) for c in lowercase}
    ins = {c: len([t for t in normals if t[2]==c]) for c in lowercase}
    outs = {c: len([t for t in normals if t[0]==c]) for c in lowercase}

    for c, k in ins.items():
        if k > 1:
            # print (c,k)
            return 0
    for c, k in outs.items():
        if k > 1:
            # print (c,k)
            return 0

    res = 1
    for c, k in dums.items():
        res *= facts[k]
        res %= MOD
    

    used = [c for c in lowercase if ins[c]!=0 or outs[c]!=0 or dums[c]!=0]
    blocks = len([c for c in used if ins[c]==0])

    # Loop check
    if loop_check(normals):
        return 0

    # niceblocks = len([c for c in lowercase if ins[c]==0 and outs[c]!=0])
    # verts = len([c for c in lowercase if ins[c]!=0 or outs[c]!=0])
    # edges = sum(ins[c]+outs[c] for c in lowercase)
    # print(edges, verts+len(normals), niceblocks)
    # if edges != verts+len(normals)-niceblocks:
    #     # print(edges, verts+len(normals), niceblocks)
        # return 0

    res *= facts[blocks]
    res %= MOD
    return res

for t in range(T):
    N, = read()
    ts = read(parse_train)
    print("Case #{}: {}".format(t+1, solve(ts)))
