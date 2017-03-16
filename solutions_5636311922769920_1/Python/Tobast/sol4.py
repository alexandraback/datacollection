import math

def toInt(n,base):
    out=0
    for c in n:
        out *= base
        out += c
    return out

def toBase(n,base):
    out=[]
    while n > 0:
        out.append(n%base)
        n//=base
    return out

def solveCase():
    K,C,S = [int(x) for x in input().strip().split() ]
    minNeed = math.ceil(K/C)
    if(minNeed > S):
        return "IMPOSSIBLE"
    else:
        curDigit = 0
        curPos = []
        out = ''
        while curDigit < K:
            if(len(curPos) == C):
                out += str(toInt(curPos,K)+1)+' '
                curPos = []
            curPos.append(curDigit)
            curDigit += 1
        if len(curPos) > 0:
            out += str(toInt(curPos,K)+1)+' '
        return out[:-1]

T = int(input())
for c in range(T):
    print("Case #{}: {}".format(c+1, solveCase()))
