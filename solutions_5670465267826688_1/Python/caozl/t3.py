multR = [[1,2,3,4], [2,-1,4,-3], [3,-4,-1,2], [4,3,-2,-1]]

def CalMult(n1,n2):
    bPos = n1*n2>0
    if n1 < 0:
        n1 = -n1
    if n2 < 0:
        n2 = -n2
    nR = multR[n1-1][n2-1]
    if not bPos:
        nR = -nR
    return nR

def CalPartV(nArr):
    nRet = 1
    for nT in nArr:
        nRet = CalMult(nRet,nT)
    return nRet

def CalIJKByList(nArr):
    nRet = 1
    nSize = 0
    for nT in nArr:
        nRet = CalMult(nRet,nT)
        if nRet == nSize+2:
            nSize += 1
            nRet = 1
    return nSize == 3

def CalT3(nArr, nSize):
    nPart = CalPartV(nArr)
    if nPart == 1:
        return False
    elif nPart == -1:
        if nSize%2 != 1:
            return False
    else:
        if nSize%2 != 0 or (nSize/2)%2 != 1:
            return False
    if nSize > 12:
        nLast = nSize%4
        nSize = 12+nLast
    nArrAll = nArr * nSize
    return CalIJKByList(nArrAll)

f = file(u'input.txt')
nT = int(f.readline())
strArrR = []
for i in range(nT):
    sTemp = f.readline()
    ll = sTemp.split(u' ')
    nSize = int(ll[1])
    sPart = f.readline()
    sPart = sPart.replace('i','2')
    sPart = sPart.replace('j','3')
    sPart = sPart.replace('k','4')
    sPart = sPart[:-1]
    nArr = [int(c) for c in sPart]
    if CalT3(nArr, nSize):
        sR = u'YES'
    else:
        sR = u'NO'
    strR = u"Case #%d: %s"%(i+1, sR)
    print strR
    strArrR.append(strR+u'\n')
f.close()
f = file(u'output.txt', 'w')
f.writelines(strArrR)
f.close()