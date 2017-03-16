import numpy

def GenBase(L):
    B=[int(0)]*9
    for i in range(2,11):
        a = [L[j]*pow(i,(len(L)-j-1)) for j in range(0,len(L))]
        B[i-2] = sum(a)
    return B

def GetDivisor(i):
    if i % 2 == 0:
        return 2
    if i % 3 == 0:
        return 3
    if i % 5 == 0:
        return 5
    if i % 7 == 0:
        return 7
    if i % 11 == 0:
        return 11
    if i % 13 == 0:
        return 13
    if i % 23 == 0:
        return 23
        

print("Case #1:")

n = 0
i = 0x80000001
while n < 500 and i < 0xFFFFFFFF:
    st = bin(i)[2:]
    st = [int(s) for s in st]
    b=GenBase(st)
    res = [(
        bi % 2 == 0 or
        bi % 3 == 0 or
        bi % 5 == 0 or
        bi % 7 == 0 or
        bi % 11 == 0 or
        bi % 13 == 0 or
        bi % 23 == 0)
     for bi in b]
    if all(res):
        resstr = str(bin(i)[2:])
        for bi in b:
            resstr += " " + str(int(GetDivisor(bi)))
        print(resstr)
        n+=1
    i += 2
