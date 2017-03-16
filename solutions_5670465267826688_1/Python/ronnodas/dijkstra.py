i = 'i'
j = 'j'
k = 'k'
e = '1'

cs = [i,j,k]
QT = [(s,c) for s in (1,-1) for c in (e,i,j,k)]
def mult(qt,c):
    s,d = qt
    if c == i:
        if d == e:
            return (s,i)
        if d == i:
            return (-s,e)
        if d == j:
            return (-s,k)
        if d == k:
            return (s,j)
    if c == j:
        if d == e:
            return (s,j)
        if d == i:
            return (s,k)
        if d == j:
            return (-s,e)
        if d == k:
            return (-s,i)
    if c == k:
        if d == e:
            return (s,k)
        if d == i:
            return (-s,j)
        if d == j:
            return (s,i)
        if d == k:
            return (-s,e)

good = [(0,(1,i)), (1,(1,j)),(2,(1,k))]

transitions = {}
for matched in range(4):
    for qt in QT:
        for c in cs:
            newqt = mult(qt,c)
            if (matched,newqt) in good:
                transitions[((matched,qt),c)] = (matched+1,(1,e))
            else:
                transitions[((matched,qt),c)] = (matched,newqt)


def process(string):
    ret = {}
    for matched in range(4):
        for qt in QT:
            state = (matched,qt)
            for c in string:
                state = transitions[(state,c)]
            ret[(matched,qt)] = state
    return ret

def multiply (map1,map2):
    return {start:map2[end] for (start,end) in map1.items()}
    
def repeat(mapping,N):
    if N==0:
        return {start:start for start in mapping}
    if N==1:
        return {start:end for (start,end) in mapping.items()}
    half = repeat(mapping,N//2)
    almost = multiply(half,half)
    if N%2:
        return multiply(almost,mapping)
    else:
        return almost

T = int(input())
for case in range(1,T+1):
    L,X = (int(x) for x in input().split())
    CS = input().strip()
    total = repeat(process(CS),X)
    if total[(0,(1,e))] == (3,(1,e)):
        ans = 'YES'
    else:
        ans = 'NO'
    print("Case #",case,": ",ans,sep = '')
