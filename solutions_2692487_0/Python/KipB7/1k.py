import math

filename = r'A-test.txt'
filename = r'A-small-attempt0.in'
#filename = r'A-small-practice.in'
#filename = 'A-large.in'
foutname = r'A-out.txt'

FILE = open(filename)
FOUT = open(foutname,"w")
T = int(FILE.readline())
dbg=1

def find_intermediates(A,Goal):
    res = []
    while A<=Goal and A>1:
        res.append(A-1)
        A += (A-1) #absorb just smaller
    return res

def A1(A,V):
    if dbg: print "A1(",A,",",V,")"
    addlist=[]
    droplist=[]
    for k,kv in enumerate(V): #k=0,1,2...
        if A>kv:
            A += kv #can just absorb
            if dbg: print "Absorb ",kv," A=",A
        else: #maybe some intermediates would help
            inter = find_intermediates(A,kv)
            nv_left = len(V) - (k) #counting kv itself
            if nv_left < len(inter): #drop instead of add
                if dbg: print "nv_left=",nv_left," but inter=",inter," so just drop ",V[k:]
                droplist.extend(V[k:])
                break
            else:
                si = sum(inter)
                addlist.extend(inter)
                A += si + kv
                if dbg: print "Invent ",inter," = ",si," A=",A
       
    return len(addlist)+len(droplist),addlist,droplist

def A2(A,V,d="."):#recursive version
    #we only do the work to handle the first one < A
    if dbg: print d,"A1(",A,",",V,")"
    if len(d)>10:
        raise Exception("too deep! "+str(len(d)))
        #return None,None,None
    k=0
    while k<len(V) and V[k]<A: #absorb
        vk = V[k]
        A += vk
        k += 1
        if dbg: print d,"absorb ",vk, " A=",A
    #we've absorbed k motes
    if k>=len(V):
        if dbg: print d,"done, A=",A, " N=0"
        return 0,[],[]
    #to eat the next one, we'd have to invent a few:
    vk = V[k]
    addl = find_intermediates(A,vk)
    na = len(addl)
    nv_left = len(V) - k #what if we just dropped the rest
    if na==0 or nv_left <= na: #quick 'n dirty OK to drop the rest
        #na==0 when no possible adds work
        if dbg: print d,"drop1 ",V[k:]," A=",A
        return nv_left,[],V[k:] #we drop the rest, no need to recurse
    if dbg: print d,"not drop1 ",nv_left,addl
    #If we keep addl, what is minimum that we could do the rest?  maybe dropping is still better
    sumaddl = sum(addl)
    if dbg: print d,"what if"
    n2,a2,d2 = A2(A+sumaddl+vk,V[k+1:], d+". ")
    if dbg: print d,"==>",n2,a2,d2
    if nv_left <= na + n2: #still better to drop the rest
        if dbg: print d,"drop2 ",V[k:]," A=",A
        return nv_left,[],V[k:]
    #keep the adds
    if dbg: print d,"add ",addl," sum=",sumaddl," and absorb ",vk
    A += sumaddl + vk
    k += 1
    if dbg: print d,"keep2 ",vk," A=",A
    return na + n2, addl+a2, d2

#nstep,addl,dropl = A2(3,[7,20])
#print "nstep=",nstep," addl=",addl," dropl=",dropl

if 1:
  dbg=0
  for i in range(1,T+1):
    rawline = FILE.readline()
    A,N = map(int,rawline.split(' ',2))
    V = map(int,FILE.readline().split(' ',N))
    V.sort()
    if i>0:
        rets = A2(A,V)
        if dbg: print "Case #" + str(i)+": begin A,N=",(A,N),"V=",V
        msg = 'Case #' + str(i) + ': ' + str(rets[0])
        print msg, ", addl=",rets[1]," dropl=",rets[2]
        #if i%10==1: print msg
        FOUT.write(msg + "\n")
        if dbg: print ""
FOUT.close()
