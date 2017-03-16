def CalT1(nSm, sData):
    nAdd = 0
    nCur = 0
    for i in range(nSm+1):
        if nCur < i:
            nAdd += i-nCur
            nCur = i
        nCur += int(sData[i])
    return nAdd

f = file(u'input.txt')
nT = int(f.readline())
strArrR = []
for i in range(nT):
    sTemp = f.readline()
    ll = sTemp.split(u' ')
    nSm = int(ll[0])
    sData = ll[1]
    strR = u"Case #%d: %d"%(i+1, CalT1(nSm, sData))
    print strR
    strArrR.append(strR+u'\n')
f.close()
f = file(u'output.txt', 'w')
f.writelines(strArrR)
f.close()