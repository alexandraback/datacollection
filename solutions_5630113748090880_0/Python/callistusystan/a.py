def intput():
    return int(input())
def insplit():
    return input().split()
def intsplit():
    a = input().split()
    for i in range(len(a)):
        a[i] = int(a[i])
    return a
def strtolist(a):
    list = []
    for c in a:
        list.append(c)
    return list
def s(a):
    return str(a)

T = intput()
for t in range(T):
    N = intput()
    a = []
    for i in range(2*N-1):
        a.append(intsplit())
    nOccur = [0]*2500
    for i in a:
        for j in i:
            nOccur[j-1]+=1
    b = []
    for i in range(len(nOccur)):
        if nOccur[i]%2 == 1:
            b.append(i+1)
    b.sort()
    print("Case #" + str(t+1) + ": ",end = "")
    for i in b:
        print(i, end = " ")
    print()
