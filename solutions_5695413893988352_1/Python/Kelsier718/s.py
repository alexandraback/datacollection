def best(a,b):
    m = min(b)
    for k in range(len(b)):
        if b[k] != m:
            a[k] = -1
            b[k] = -1
    tmpA = [x for x in a if x is not -1]
    tmpB = [x for x in b if x is not -1]
    a = tmpA
    b = tmpB
    cs = [k[0] for k in a]
    m = min(cs)
    for k in range(len(a)):
        if a[k][0] != m:
            a[k] = -1
    tmpA = [x for x in a if x is not -1]
    a = tmpA
    cs = [k[1] for k in a]
    m = min(cs)
    for k in range(len(a)):
        if a[k][1] != m:
            a[k] = -1
    tmpA = [x for x in a if x is not -1]
    a = tmpA
    return a[0]

def solve(c, j):
    if c==[]:
        return ('','')
    if c[0]!='?' and j[0]!='?':
        if int(c[0])<int(j[0]):
            newC = ''
            for d in c:
                if d == '?':
                    newC = newC + '9'
                else:
                    newC = newC + d
            newJ = ''
            for d in j:
                if d == '?':
                    newJ = newJ + '0'
                else:
                    newJ = newJ + d
            return (newC,newJ)
        if int(c[0])>int(j[0]):
            newC = ''
            for d in c:
                if d == '?':
                    newC = newC + '0'
                else:
                    newC = newC + d
            newJ = ''
            for d in j:
                if d == '?':
                    newJ = newJ + '9'
                else:
                    newJ = newJ + d
            return (newC,newJ)
        tmpC = list(c)
        tmpJ = list(j)
        lc = tmpC[0]
        lj = tmpJ[0]
        del tmpC[0]
        del tmpJ[0]
        res = solve(tmpC,tmpJ)
        return (lc+res[0],lj+res[1])
    if c[0]=='?' and j[0]=='?':
        tmpC = list(c)
        tmpJ = list(j)
        res = [0,0,0]
        tmpC[0] = '0'
        tmpJ[0] = '0'
        res[0] = solve(tmpC,tmpJ)
        #print('sep')
        #print(tmpC)
        #print(tmpJ)
        #print(res[0])
        tmpC[0] = '0'
        tmpJ[0] = '1'
        res[1] = solve(tmpC,tmpJ)
        tmpC[0] = '1'
        tmpJ[0] = '0'
        res[2] = solve(tmpC,tmpJ)
        diff = [0,0,0]
        for k in range(3):
            diff[k] = abs(int(res[k][0])-int(res[k][1]))
        return best(res,diff)
        #for k in range(3):
        #    if diff[k] == min(diff):
        #        return res[k]
    if c[0]=='?':
        tmpC = list(c)
        tmpJ = list(j)
        res = [-1,-1,-1]
        tmpC[0] = tmpJ[0]
        res[0] = solve(tmpC,tmpJ)
        if tmpJ[0] != '9':
            tmpC[0] = str(int(tmpJ[0])+1)
            res[1] = solve(tmpC,tmpJ)
        if tmpJ[0] != '0':
            tmpC[0] = str(int(tmpJ[0])-1)
            res[2] = solve(tmpC,tmpJ)
        tmp = [x for x in res if x is not -1]
        res = tmp
        diff = [0 for a in res]
        for k in range(len(diff)):
            diff[k] = abs(int(res[k][0])-int(res[k][1]))
        return best(res,diff)
    if j[0]=='?':
        tmpC = list(c)
        tmpJ = list(j)
        res = [-1,-1,-1]
        tmpJ[0] = tmpC[0]
        res[0] = solve(tmpC,tmpJ)
        if tmpC[0] != '9':
            tmpJ[0] = str(int(tmpC[0])+1)
            res[1] = solve(tmpC,tmpJ)
        if tmpC[0] != '0':
            tmpJ[0] = str(int(tmpC[0])-1)
            res[2] = solve(tmpC,tmpJ)
        tmp = [x for x in res if x is not -1]
        res = tmp
        diff = [0 for a in res]
        for k in range(len(diff)):
            diff[k] = abs(int(res[k][0])-int(res[k][1]))
        return best(res,diff)

t = int(input())
for i in range(1, t + 1):
    c, j = [s for s in input().split(" ")]
    res = solve(list(c),list(j))
    print("Case #{}: {} {}".format(i, res[0], res[1]))
