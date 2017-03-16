def CalT2N(dataArr, n):
    nR = 0
    for i in dataArr:
        nR += (i-1)/n
    return nR

def CalT2(dataArr):
    rArr = []
    for i in range(1, dataArr[len(dataArr)-1]+1):
        rArr.append(CalT2N(dataArr, i)+i)
    rArr.sort()
    return rArr[0]

f = file(u'input.txt')
nT = int(f.readline())
strArrR = []
for i in range(nT):
    nD = int(f.readline())
    sData = f.readline()
    ll = sData.split(u' ')
    dataArr = [int(s) for s in ll]
    dataArr.sort()
    strR = u"Case #%d: %d"%(i+1, CalT2(dataArr))
    print strR
    strArrR.append(strR+u'\n')
f.close()
f = file(u'output.txt', 'w')
f.writelines(strArrR)
f.close()