import sys

def test_offset():
    print("TEST_OFFSET")
    #print(offset_calc(3,3,3,0))
    #print(offset_calc(3,3,3,1))
    #print(offset_calc(3,3,3,2))
    #print(offset_calc(3,3,2,0))
    #print(offset_calc(3,3,2,1))
    #print(offset_calc(3,3,2,2))
    #print(offset_calc(3,3,1,0))
    #print(offset_calc(3,3,1,1))
    #print(offset_calc(3,3,1,2))
    print(offset_calc(3,3,3,1))


def offset_calc(k,c,lvl,pos):
    if c==lvl:return pos
    return pos*(k**(c-lvl))

def solve(k,c,s):
    if s*c<k:return ["IMPOSSIBLE"]
    if k<=s:return [str(i) for i in (range(1,k+1))]
    res = []
    remaining = list(range(k))
    while s > 0 and len(remaining)> 0:
        max_elimination = min(len(remaining),c)
        pos=0
        for i in range(1,max_elimination+1):
            to_eliminate=remaining.pop(0)
            pos += offset_calc(k,c,i,to_eliminate)
        res.append(pos)
        s-=1
    return [str(i+1) for i in res]





"""
NE PAS OUBLIER DE REINCREMENTER
"""
t = int(input())
for i in range(1,t+1):
    k, c, s = list(map(int,input().split()))
    print("Case #"+str(i)+": "+" ".join(solve(k,c,s)))
