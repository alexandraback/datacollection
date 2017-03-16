f = file("c:\\input.txt")
strArr = []
while True:
    line = f.readline()
    if len(line)==0:
        break
    strArr.append(line)
f.close()
nSize = int(strArr[0])
for i in range(nSize):
    strArrT = strArr[i+1].split(' ')
    ns = int(strArrT[0])
    nL = int(strArrT[1])
    ns*=2
    ns+=1
    fl = (long(((ns-2)*(ns-2)+8*nL)**(1.0/2))-ns+2)/4
    nR = int(fl)
    nUse = (ns+2*nR-2)*nR
    while nUse>nL:
        nR-=1
        nUse = (ns+2*nR-2)*nR
    while nUse<=nL:
        nR+=1
        nUse = (ns+2*nR-2)*nR
    strArr[i+1] = "Case #%d: %ld\n"%(i+1, nR-1)
del strArr[0]
f = file("c:\\output.txt", 'w')
f.writelines(strArr)
f.close()
