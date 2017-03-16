def formatList(l):
    out=''
    for x in l:
        out += ' '+str(x)
    return out

def solveCase():
    K,C,S = [ int(x) for x in input().strip().split(' ') ]
    return formatList(list(range(1,S+1)))

T = int(input())
for c in range(T):
    print("Case #{}: {}".format(c+1, solveCase()))
