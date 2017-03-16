# https://code.google.com/codejam/contest/6254486/dashboard#s=p3

from collections import deque

def generate_artwork(setGold, nOrigin, iComplex):

    nSetMax    = nOrigin ** (iComplex-1)
    nGenSetMax = nOrigin * nSetMax
    
    setGenGold = set()
    for gold in setGold:

        setGenGold.update(set(range(gold, nGenSetMax+1, nOrigin)))
        setGenGold.update(set(range(nOrigin*(gold-1)+1, nOrigin*gold+1)))

    return setGenGold


def merge_set(listsetGold):

    listsetRest = deque(listsetGold)
    listsetRest.append(set())

    listsetJoint = list()

    setJoint = set()
    while True:

        #print(listsetRest)
        curSet = listsetRest.popleft()
        if len(curSet) == 0: # reach the end of queue

            listsetJoint.append(setJoint)
            setJoint = set()

            if len(listsetRest) == 0: # all sets done

                break

            else:

                listsetRest.append(set())
                continue

        if len(setJoint) == 0:

            newsetJoint = set(curSet)

        else:

            newsetJoint = setJoint.intersection(curSet)


        if len(newsetJoint) == 0: # no joint, continue

            listsetRest.append(curSet)
            continue

        else:

            setJoint = newsetJoint

    return listsetJoint



fhIn  = open('input_small',  'r')
fhOut = open('output', 'w') 

nCase = int(fhIn.readline())
for iCase in range(1, nCase+1):

    listParam = fhIn.readline().split(' ')
    nOrigin   = int(listParam[0])
    nComplex  = int(listParam[1])
    nSlave    = int(listParam[2])

    listsetGold = list()
    for iOrigin in range(0, nOrigin):

        listsetGold.append(set([iOrigin+1]))

    listsetJoint = merge_set(listsetGold)


    for iComplex in range(2, nComplex+1):

        listsetGold = list()
        for setGold in listsetJoint:

            setGenGold = generate_artwork(setGold, nOrigin, iComplex)
            listsetGold.append(setGenGold)

        #print(listsetGold)
        listsetJoint = merge_set(listsetGold)
        #print(listsetJoint)

        if len(listsetJoint) <= nSlave:

            break

    if len(listsetJoint) > nSlave: # more independent sets than slaves

        strResult = format('Case #%d: IMPOSSIBLE\n' % iCase)

    else:

        strResult = format('Case #%d:' % iCase)
        for setJoint in listsetJoint:

            strResult = strResult + ' ' + str(setJoint.pop())

        strResult = strResult + '\n'
    
    print(strResult)

    fhOut.write(strResult)



fhIn.close()
fhOut.close()
