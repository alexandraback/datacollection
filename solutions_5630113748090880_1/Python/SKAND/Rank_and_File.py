a = input()
b=[]
c=[]
d=[]

for i in range(a):
    b.append(input())
    c.append('Case #'+str(i+1)+':')
    d.append([])
    for j in range(2*b[i]-1):
        d[i].append(map(int,raw_input().split()))

def func(lst,col):
    f ={}
    for i in range(len(lst)):
        for j in range(col):
            f[lst[i][j]] = 0
    for i in range(len(lst)):
        for j in range(col):
            f[lst[i][j]] += 1

    out = []
    for j in f.keys():
        if f[j]%2 != 0:
            out.append(j)
    out = sorted(out)

    rslt = str(out[0])
    for k in range(1,len(out)):
        rslt += ' ' + str(out[k])

    return rslt

for x in range(a):
    print c[x],func(d[x],b[x])
