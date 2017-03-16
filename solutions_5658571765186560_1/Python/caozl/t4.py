def CalT4(x, r, c):
    if r>c:
        r,c = c,r
    if (r*c)%x != 0:
        return True
    if x>6:
        return True
    if x<3:
        return False
    if x==3:
        return r==1
    if x==4:
        return r<3
    if x==5:
        return r<4
    #if x==6:
    return r<4

f = file(u'input.txt')
nT = int(f.readline())
strArrR = []
for i in range(nT):
    sTemp = f.readline()
    ll = sTemp.split(u' ')
    if CalT4(int(ll[0]), int(ll[1]), int(ll[2])):
        sR = u'RICHARD'
    else:
        sR = u'GABRIEL'
    strR = u"Case #%d: %s"%(i+1, sR)
    print strR
    strArrR.append(strR+u'\n')
f.close()
f = file(u'output.txt', 'w')
f.writelines(strArrR)
f.close()