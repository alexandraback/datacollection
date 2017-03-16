import sys

args = sys.argv

ijkDict = {'1':0, 'i':1, 'j':2, 'k':3}

quatTable = [['1','i','j','k'],['i','-1','k','-j'],['j','-k','-1','i'],['k','j','-i','-1']]

quatMultTable = {'1':'1', 'i':'i', 'j':'j', 'k':'k', '1j': 'j', '1k': 'k', 'k1': 'k', '1i': 'i', 'jk': 'i', 'jj': '-1', 'ji': '-k', 'kk': '-1', 'ij': 'k', 'ik': '-j', 'ii': '-1', 'j1': 'j', 'ki': 'j', 'kj': '-i', 'i1': 'i', '11': '1'}

def quatMultCharsTemp(a, b):
    checkChar = a
    reverse = False
    res = None
    if a.startswith('-'):
        checkChar = a[1]
        reverse = True
    res = quatTable[ijkDict[checkChar]][ijkDict[b]]
    if reverse:
        if res[0] == '-':
            res = res[1:]
        else:
            res = '-' + res
    return res

def quatMultChars(a, b):
    if a == '':
        return b
    if a[0] == '-' and b[0] == '-':
        return quatMultTable[a[1]+b[1]]
    elif a[0] == '-':
        res = quatMultTable[a[1]+b]
        if res[0] == '-':
            return res[1]
        return '-' + res
    elif b[0] == '-':
        res = quatMultTable[a+b[1]]
        if res[0] == '-':
            return res[1]
        return '-' + res
    else:
        return quatMultTable[a+b]

def removeKnown1s(s):
    ls = len(s)
    todel = []
    done = False
    ss = 0
    while ss < ls:
        changed = False
        if s[ss] == 'k':
            if ss + 2 < ls and s[ss+1] == 'j' and s[ss+2] == 'i':
                todel.append(ss)
                todel.append(ss+1)
                todel.append(ss+2)
                ss = ss + 3
                changed = True
            elif ss + 3 < ls and s[ss+1] == 'k' and s[ss+2] == 'k' and s[ss+3] == 'k':
                todel.append(ss)
                todel.append(ss+1)
                todel.append(ss+2)
                todel.append(ss+3)
                ss = ss + 4
                changed = True
            elif ss + 3 < ls and s[ss+1] == 'k' and s[ss+2] == 'i' and s[ss+3] == 'i':
                todel.append(ss)
                todel.append(ss+1)
                todel.append(ss+2)
                todel.append(ss+3)
                ss = ss + 4
                changed = True
            elif ss + 3 < ls and s[ss+1] == 'k' and s[ss+2] == 'j' and s[ss+3] == 'j':
                todel.append(ss)
                todel.append(ss+1)
                todel.append(ss+2)
                todel.append(ss+3)
                ss = ss + 4
                changed = True
            elif ss + 3 < ls and s[ss+1] == 'i' and s[ss+2] == 'i' and s[ss+3] == 'k':
                todel.append(ss)
                todel.append(ss+1)
                todel.append(ss+2)
                todel.append(ss+3)
                ss = ss + 4
                changed = True
            elif ss + 3 < ls and s[ss+1] == 'j' and s[ss+2] == 'j' and s[ss+3] == 'k':
                todel.append(ss)
                todel.append(ss+1)
                todel.append(ss+2)
                todel.append(ss+3)
                ss = ss + 4
                changed = True
        elif s[ss] == 'j':
            if ss + 2 < ls and s[ss+1] == 'i' and s[ss+2] == 'k':
                todel.append(ss)
                todel.append(ss+1)
                todel.append(ss+2)
                ss = ss + 3
                changed = True
            elif ss + 3 < ls and s[ss+1] == 'j' and s[ss+2] == 'j' and s[ss+3] == 'j':
                todel.append(ss)
                todel.append(ss+1)
                todel.append(ss+2)
                todel.append(ss+3)
                ss = ss + 4
                changed = True
            elif ss + 3 < ls and s[ss+1] == 'j' and s[ss+2] == 'i' and s[ss+3] == 'i':
                todel.append(ss)
                todel.append(ss+1)
                todel.append(ss+2)
                todel.append(ss+3)
                ss = ss + 4
                changed = True
            elif ss + 3 < ls and s[ss+1] == 'j' and s[ss+2] == 'k' and s[ss+3] == 'k':
                todel.append(ss)
                todel.append(ss+1)
                todel.append(ss+2)
                todel.append(ss+3)
                ss = ss + 4
                changed = True
            elif ss + 3 < ls and s[ss+1] == 'i' and s[ss+2] == 'i' and s[ss+3] == 'j':
                todel.append(ss)
                todel.append(ss+1)
                todel.append(ss+2)
                todel.append(ss+3)
                ss = ss + 4
                changed = True
            elif ss + 3 < ls and s[ss+1] == 'k' and s[ss+2] == 'k' and s[ss+3] == 'j':
                todel.append(ss)
                todel.append(ss+1)
                todel.append(ss+2)
                todel.append(ss+3)
                ss = ss + 4
                changed = True
        elif s[ss] == 'i':
            if ss + 2 < ls and s[ss+1] == 'k' and s[ss+2] == 'j':
                todel.append(ss)
                todel.append(ss+1)
                todel.append(ss+2)
                ss = ss + 3
                changed = True
            elif ss + 3 < ls and s[ss+1] == 'i' and s[ss+2] == 'i' and s[ss+3] == 'i':
                todel.append(ss)
                todel.append(ss+1)
                todel.append(ss+2)
                todel.append(ss+3)
                ss = ss + 4
                changed = True
            elif ss + 3 < ls and s[ss+1] == 'i' and s[ss+2] == 'k' and s[ss+3] == 'k':
                todel.append(ss)
                todel.append(ss+1)
                todel.append(ss+2)
                todel.append(ss+3)
                ss = ss + 4
                changed = True
            elif ss + 3 < ls and s[ss+1] == 'i' and s[ss+2] == 'j' and s[ss+3] == 'j':
                todel.append(ss)
                todel.append(ss+1)
                todel.append(ss+2)
                todel.append(ss+3)
                ss = ss + 4
                changed = True
            elif ss + 3 < ls and s[ss+1] == 'k' and s[ss+2] == 'k' and s[ss+3] == 'i':
                todel.append(ss)
                todel.append(ss+1)
                todel.append(ss+2)
                todel.append(ss+3)
                ss = ss + 4
                changed = True
            elif ss + 3 < ls and s[ss+1] == 'j' and s[ss+2] == 'j' and s[ss+3] == 'i':
                todel.append(ss)
                todel.append(ss+1)
                todel.append(ss+2)
                todel.append(ss+3)
                ss = ss + 4
                changed = True
        if not changed:
            ss = ss + 1
    todel.sort()
    ltdel = len(todel)
    st = 0
    delS = 0
    delSStarted = False
    curr = -1
    hasbeendeleted = 0
    while st < ltdel:
        todel[st] = todel[st] - hasbeendeleted
        if not delSStarted:
            delS = todel[st]
            curr = delS
            delSStarted = True
            st = st + 1
        else:
            if curr != -1 and todel[st] != curr+1:
                s = s[:delS] + s[curr+1:]
                todel[st] = todel[st] + hasbeendeleted
                hasbeendeleted = hasbeendeleted + curr - delS + 1
                delSStarted = False
            else:
                curr = todel[st]
                st = st + 1
                continue;
    if delSStarted:
        s = s[:delS] + s[curr+1:]
    return s

def quatMultStr(multstring):
    mlen = len(multstring)
    if mlen == 0:
        return ''
    multstring = removeKnown1s(multstring)
    mlen = len(multstring)
    if mlen == 0:
        return '1'
    uptoNow = None
    for m in range(0, mlen):
        if uptoNow == None:
            uptoNow = multstring[m]
        else:
            uptoNow = quatMultChars(uptoNow, multstring[m])
    return uptoNow


if len(args) == 2:
    readLoc = args[1]
    f = open(readLoc,'r')
    of = open('output.txt','w')
    breakFlag = False
    num = 0
    numCalculated = False
    i = -1
    while not breakFlag:
        l = f.readline()
        if not numCalculated:
            num = int(l.strip())
            numCalculated = True
            i = 0
        elif i < num:
            l1 = f.readline().strip()
            ds = l.strip().split(' ')
            sslen = int(ds[0])
            mult = int(ds[1])
            totalstr = ''
            for j in range(0,mult):
                totalstr = totalstr+l1
            stringeval = quatMultStr(totalstr)
            if sslen == 1:
                of.write('Case #'+str(i+1)+': NO\n')
                print('Case #'+str(i+1)+': NO')
            elif sslen * mult < 3:
                of.write('Case #'+str(i+1)+': NO\n')
                print('Case #'+str(i+1)+': NO')
            elif sslen == 3 and mult == 1 and l1 == 'ijk':
                of.write('Case #'+str(i+1)+': YES\n')
                print('Case #'+str(i+1)+': YES')
            elif stringeval != '-1':
                of.write('Case #'+str(i+1)+': NO\n')
                print('Case #'+str(i+1)+': NO')
            else:
                ltot = sslen * mult
                #print(totalstr + " - " + str(ltot))
                iPoss = {}
                iPossLen = 0
                jPoss = {}
                jPossLen = 0
                kPoss = {}
                kPossLen = 0
                allmatch = {}
                upto = ''
                for x in range(0,ltot):
                    ch = totalstr[x]
                    if x == 0 :
                        upto = ch
                    else:
                        upto = quatMultChars(upto, ch)
                    if upto == 'i':
                        iPoss[x+1] = True
                        iPossLen = iPossLen + 1
                for x in range(0,ltot):
                    ch = totalstr[ltot - 1 - x]
                    if x == 0:
                        upto = ch
                    else:
                        upto = quatMultChars(ch, upto)
                    if upto == 'k':
                        kPoss[ltot - x - 1] = True
                        kPossLen = kPossLen + 1
                if kPossLen == 0:
                    of.write('Case #'+str(i+1)+': NO\n')
                    print('Case #'+str(i+1)+': NO')
                if iPossLen == 0:
                    of.write('Case #'+str(i+1)+': NO\n')
                    print('Case #'+str(i+1)+': NO')
                else:
                    alreadyDone = {}
                    foundOutVList = []
                    foundOutVNum = {}
                    vlistLen = 0
                    flag = False
                    for t in iPoss.keys():
                        for u in kPoss.keys():
                            if t < u:
                                #upto = quatMultStr(totalstr[t:u])
                                #print(totalstr[t:u])
                                v = t
                                tempU = u
                                ddFl = False
                                while not ddFl:
                                    HighestFOVL = -1
                                    HighestFOVLNum = -1
                                    HighestFOVLI = -1
                                    FOVLLen = vlistLen
                                    for fOVL in range(0,FOVLLen):
                                        if foundOutVList[fOVL] >= v:
                                            if HighestFOVL < foundOutVList[fOVL]:
                                                HighestFOVL = foundOutVList[fOVL]
                                                HighestFOVLI = fOVL
                                    if HighestFOVLI != -1:
                                        HighestD = -1
                                        xv = foundOutVList[HighestFOVLI]
                                        donesMain = alreadyDone[xv]
                                        for d in donesMain:
                                            if d < u:
                                                if d > HighestD:
                                                    HighestD = d
                                        if HighestD != -1:
                                            prev = quatMultStr(totalstr[v:foundOutVList[HighestFOVLI]])
                                            if v in alreadyDone:
                                                dones = alreadyDone[v]
                                                if foundOutVList[HighestFOVLI] not in dones:
                                                    dones[foundOutVList[HighestFOVLI]] = prev
                                            else:
                                                foundOutVList.append(v)
                                                foundOutVNum[v] = 1
                                                vlistLen = vlistLen + 1
                                                alreadyDone[v] = {}
                                                alreadyDone[v][foundOutVList[HighestFOVLI]] = prev
                                            c = donesMain[HighestD]
                                            after = quatMultStr(totalstr[HighestD:u])
                                            if HighestD+1 in alreadyDone:
                                                dones = alreadyDone[HighestD+1]
                                                if u not in dones:
                                                    dones[u] = after
                                            else:
                                                foundOutVList.append(HighestD+1)
                                                foundOutVNum[HighestD+1] = 1
                                                vlistLen = vlistLen + 1
                                                alreadyDone[HighestD+1] = {}
                                                alreadyDone[HighestD+1][u] = after
                                            upto = quatMultChars(prev,c)
                                            upto = quatMultChars(upto,after)
                                            v = u
                                            ddFl = True
                                            break;
                                        else:
                                            upto = quatMultStr(totalstr[v:u])
                                            if v in alreadyDone:
                                                dones = alreadyDone[v]
                                                if u not in dones:
                                                    dones[u] = upto
                                            else:
                                                foundOutVList.append(v)
                                                foundOutVNum[v] = 1
                                                vlistLen = vlistLen + 1
                                                alreadyDone[v] = {}
                                                alreadyDone[v][u] = upto
                                            v = u
                                            ddFl = True
                                            break;
                                    else:
                                        upto = quatMultStr(totalstr[t:u])
                                        if t in alreadyDone:
                                            dones = alreadyDone[t]
                                            if u not in dones:
                                                dones[u] = upto
                                        else:
                                            foundOutVList.append(t)
                                            foundOutVNum[t] = 1
                                            vlistLen = vlistLen + 1
                                            alreadyDone[t] = {}
                                            alreadyDone[t][u] = upto
                                        v = u
                                        ddFl = True
                                        break;
                                #print("jstr - " + totalstr[t:u])
                                #print("upto - " + upto)
                                if upto == 'j':
                                    of.write('Case #'+str(i+1)+': YES\n')
                                    print('Case #'+str(i+1)+': YES')
                                    flag = True
                                    break;
                        if flag:
                            break;
                    if not flag:
                        of.write('Case #'+str(i+1)+': NO\n')
                        print('Case #'+str(i+1)+': NO')
                            
                """for x in range(0,ltot):
                    for y in range(x, ltot):
                        if x == y:
                            allmatch[(x,y)] = totalstr[y]
                        else:
                            allmatch[(x,y)] = quatMultChars(allmatch[(x,y-1)],totalstr[y])
                        if x == 0:
                            if allmatch[(x,y)] == 'i':
                                iPoss[0][y] = True
                                iPossLen = iPossLen + 1
                        elif y == ltot - 1:
                            if allmatch[(x,y)] == 'k':
                                kPoss[0][x] = True
                                kPossLen = kPossLen + 1
                        else:
                            if allmatch[(x,y)] == 'j':
                                if x not in jPoss:
                                    jPoss[x] = {}
                                jPoss[x][y] = True
                                jPossLen = jPossLen + 1
                if kPossLen == 0:
                    of.write('Case #'+str(i+1)+': NO\n')
                    print('Case #'+str(i+1)+': NO')
                elif jPossLen == 0:
                    of.write('Case #'+str(i+1)+': NO\n')
                    print('Case #'+str(i+1)+': NO')
                elif iPossLen == 0:
                    of.write('Case #'+str(i+1)+': NO\n')
                    print('Case #'+str(i+1)+': NO')
                else:
                    flag = False
                    for t in iPoss[0].keys():
                        jTs = jPoss.get(t+1)
                        if jTs is not None:
                            for jT in jTs.keys():
                                kts = kPoss[0].get(jT+1)
                                if kts is not None and kts:
                                    of.write('Case #'+str(i+1)+': YES\n')
                                    print('Case #'+str(i+1)+': YES')
                                    flag = True
                                    break;
                        if flag:
                            break;
                    if not flag:
                        of.write('Case #'+str(i+1)+': NO\n')
                        print('Case #'+str(i+1)+': NO')"""
            i = i + 1
        else:
            breakFlag = True
    of.flush()
    of.close()
    f.close()

sys.exit()
