#!/usr/bin/env python
import math
T=int(raw_input().strip())

global opend, N, needtype, gettype, dpdict
openstack=[]
opend=[]
needtype=[]
gettype=[]
N=0
dpdict={}

def openchest(hastype):
    #print begin, opend, needtype, gettype
    hastype=sorted(hastype)
    unopens=[]
    for i in range(1, N+1):
        if not opend[i]:unopens.append(i)
    #key=' '.join(hastype), unopens)
    key=' '.join(map(str, hastype))+'+'+' '.join(map(str, unopens))
    if key in dpdict:return False

    for i in range(1,N+1):
        if opend[i]:
            continue
        need=needtype[i-1]
        if hastype.count(need)!=0:
            opend[i]=True
            hastype.remove(need)
            hastype.extend(gettype[i-1])
            openstack.append(i)
            if openchest(hastype):
                return True
            else:
                dpdict[key]=False
                opend[i]=False
                del hastype[len(hastype)-len(gettype[i-1]) :]
                hastype.append(need)
                openstack.pop()
    for i in range(1, N+1):
        if not opend[i]:
            dpdict[key]=False
            return False
    return True
    

for i in range(1, T+1):
    #global opend, N, needtype, gettype
    K, N = raw_input().strip().split()
    K, N = int(K), int(N)
    begin=[int(x) for x in raw_input().strip().split()]
    opend=[False]*(N+1)
    needtype=[]
    gettype=[]
    openstack=[]
    dpdict.clear()
    for j in range(N):
        chest=[int(x) for x in raw_input().strip().split()]
        needtype.append(chest[0])
        gettype.append(chest[2:])
    if openchest(begin):
        seq=''
        #print len(openstack), N
        assert len(openstack)==N
        for j in range(len(openstack)):
            seq=seq+('%d ' % openstack[j])
        print 'Case #%d: %s' % (i, seq.strip())
    else:
        print 'Case #%d: IMPOSSIBLE' % i

