__author__ = 'Peter'
import math
mat=[[1,2,3,4],[2,-1,4,-3],[3,-4,-1,2],[4,3,-2,-1]]
def mult(a,b):
    return int(math.copysign(1,a*b)*mat[abs(a)-1][abs(b)-1])

with open ("C-small-attempt0.out","w") as outF:
    with open("C-small-attempt0.in","r") as inF:
        nt= int(inF.readline())
        for t in xrange(nt):
            l,x= map(int,inF.readline().split())
            seqS=inF.readline()
            seq=[]
            for i in xrange(l):
                c=seqS[i]
                if c=="i":
                    seq.append(2)
                if c=="j":
                    seq.append(3)
                if c=="k":
                    seq.append(4)
            state=1
            leftI=-1
            for i in xrange(l*8):
                state=mult(state,seq[i%l])
                if state==2:
                    leftI=i
                    break
            if leftI==-1:
                outF.write("Case #%d: NO\n"%(t+1))
                continue

            state=1
            rightI=-1
            for i in xrange(l*8):
                state=mult(seq[(l-1-i)%l],state)
                if state==4:
                    rightI=i
                    break
            if rightI==-1:
                outF.write("Case #%d: NO\n"%(t+1))
                continue

            count=leftI+1+rightI+1
            state=1
            fromI=(leftI+1)%l
            toI=(l-1-rightI)%l
            for i in xrange(fromI,2*l):
                if i%l==toI:
                    break
                state=mult(state,seq[i%l])
                count+=1
            assert count%l==0
            if count>l*x:
                outF.write("Case #%d: NO\n"%(t+1))
                continue
            nPower= (x-count/l)%8
            for i in xrange(nPower*l):
                state=mult(state,seq[(toI+i)%l])
            if state==3:
                outF.write("Case #%d: YES\n"%(t+1))
            else:
                outF.write("Case #%d: NO\n"%(t+1))
