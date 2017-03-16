#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys

def getRet(N,lv1,lv2):
    #print N,lv1,lv2
    x1 = dict()
    sol1 = []
    x2 = dict()
    sol2 = []
    for i in xrange(len(lv1)):
        if lv1[i] not in x1:
            x1[lv1[i]]=[]
        x1[lv1[i]].append(i)
        x1[lv1[i]].sort()
    for i in xrange(len(lv2)):
        if lv2[i] not in x2:
            x2[lv2[i]]=[]
        x2[lv2[i]].append(i)
        x2[lv2[i]].sort()
    #print x1,x2
    ret = 0
    st = 0
    while len(sol2) < N:
        #print 'loop',st,sol2
        update = False
        j = -1
        for i in xrange(st,-1,-1):
            if i in x2:
                lm1 = [x for x in x2[i] if x not in sol1]
                if lm1:
                    j = i
                    break
        if j > -1:
            i=j
            if i in x2:
                #print 'x2',i
                while x2[i]:
                    a = x2[i][0]
                    lm1 = [x for x in x2[i] if x not in sol1]
                    if lm1:
                        ma = max([lv1[x] for x in lm1])
                        #print lm1,ma,lv1
                        lm2 = [x for x in x2[i] if lv1[x] == ma]
                        a = lm2[0]
                    if a not in sol2:
                        if a not in sol1:
                            sol1.append(a)
                            st += 1
                        sol2.append(a)
                        st+=1
                        ret += 1
                        update = True
                        x2[i].remove(a)
                        #print 'x2',a,'rem',i,x2[i],'st',st
                        break
        else:
            for i in xrange(st,-1,-1):
                if i in x2:
                    #print 'x2',i
                    while x2[i]:
                        a = x2[i][0]
                        lm1 = [x for x in x2[i] if x not in sol1]
                        if lm1:
                            ma = max([lv1[x] for x in lm1])
                            #print lm1,ma,lv1
                            lm2 = [x for x in x2[i] if lv1[x] == ma]
                            a = lm2[0]
                        if a not in sol2:
                            if a not in sol1:
                                sol1.append(a)
                                st += 1
                            sol2.append(a)
                            st+=1
                            ret += 1
                            update = True
                            x2[i].remove(a)
                            #print 'x2',a,'rem',i,x2[i],'st',st
                            break
            if update == True:
                break
        if update == True:
            continue
        for i in xrange(st,-1,-1):
            if i in x1:
                #print 'x1',i,x1[i]
                while x1[i]:
                    ma = max([lv2[x] for x in x1[i]])
                    lma = [x for x in x1[i] if lv2[x] == ma]
                    a = lma[0]
                    #print a,sol1
                    x1[i].remove(a)
                    if a not in sol1:
                        sol1.append(a)
                        st+=1
                        ret += 1
                        update = True
                        #print 'x1',a,'rem',i,x1[i],'st',st
                        break
            if update == True:
                break
        if update == False:
            return "Too Bad"
    return str(ret)

if __name__=="__main__":
    inFile = sys.argv[1]
    inFileObj = file(inFile)
    inLines = [line.strip() for line in inFileObj]
    nbTest = int(inLines[0])
    pos = 1
    for i in xrange(nbTest):
        N = int(inLines[pos])
        pos += 1
        lv1 = []
        lv2 = []
        for j in xrange(N):
            #print inLines[pos+j]
            a,b =[int(x) for x in inLines[pos+j].split()]
            lv1.append(a)
            lv2.append(b)
        pos += N
        s = 'Case #%d: ' % (i+1)
        s += getRet(N,lv1,lv2)
        print s
