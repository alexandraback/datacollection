import sys
from random import randint

from collections import Counter,deque,defaultdict
from itertools import combinations, product

IS_LOCAL = False
try:
    import os
    IS_LOCAL = os.getenv("AGLAE") == "nondual" and os.getenv("SIDONIE") == "improbable"
except:
    pass

def read_ints(inp = sys.stdin):
    return list(map(int,next(inp).strip().split()))


def sol1(j,p,s,k):
    ll =  sorted([(j,0),(p,1),(s,2)])
    a,b,c = (x[1] for x in ll)
    jps = (j,p,s)
    res=[]
    seen=defaultdict(lambda:set())
    cc1 = Counter()
    cc2 = Counter()
    for n0 in range(k):  #count (x,y)
        for x,y in product(range(jps[a]), range(jps[b])):
            """
            best = float("inf"),None
            for z in range(jps[c]):
                n1 = cc1[(x,z)]
                n2 = cc2[(y,z)]
                if z not in seen[(x,y)]:
                    if n1<k and n2<k:
                        if n1<best[0]:
                            best = n1,z
                        if n2<best[0]:
                            best = n2,z
            z= best[1]
            if z is None:
                continue
            """
            for zz in range(1,jps[c]+1):
                z = (y+zz) % jps[c]
                if z not in seen[(x,y)] and cc1[(x,z)]<k and cc2[(y,z)]<k:
                    break
            else:
                continue

            row = x,y,z
            res.append("%s %s %s" % (row[a]+1,row[b]+1,row[c]+1))
            seen[(x,y)].add(z)
            cc1[(x,z)]+=1
            cc2[(y,z)]+=1

    return "%s\n%s" % (len(res),"\n".join(res))


if IS_LOCAL:
    inp = iter("""4
1 1 1 10
1 2 3 2
1 1 3 2
1 2 3 1
""".split('\n'))
    # inp = iter(map(str,[6, "2 3 2", "1 1 1", "2 1 1", "2 1 2", "3 2 3", "100 9 50"]))
    # inp = open("A-small-attempt0.in")
    inp = sys.stdin
else:
    inp = sys.stdin

T ,= read_ints(inp)
# T=1
mm = 0
for t in range(T):
    j,p,s,k =read_ints(inp)
    x = sol1(j,p,s,k)
    # if i>=mm:
    #     print(N,i,x)
    #     mm=i
    print("Case #%d: %s" % (t+1,x) )
