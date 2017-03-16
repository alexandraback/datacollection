__author__ = 'peter'
import numpy as np

results=[]
with open("C-large.in","r") as inF:
    T= int(inF.readline())
    for iT in range(0,T):
        sp= map(int,inF.readline().split())
        R= sp[0]
        C= sp[1]
        M= sp[2] #M=R*C is not allowed, so we don't treat that case
        rM= R*C-M

        swapped=False
        possible=True
        if R>C:
            R,C=C,R
            swapped=True
        mat= np.zeros((R,C),int)

        if rM==1:
            for ir in range(0,R):
                for ic in range(0,C):
                    mat[ir,ic]=1
            mat[0,0]=2
        else:
            if R==1:
                mat[0,0]=2
                for i in range(C-M,C):
                    mat[0,i]=1
            if R==2:
                if M%2==0 and rM>2:
                    mat[0,0]=2
                    for i in range(C-M/2,C):
                        mat[0,i]=1
                        mat[1,i]=1
                else:
                    possible=False
            if R>2:
                if rM<8:
                    if rM==4:
                        mat[0,0]=2
                        for ir in range(0,R):
                            for ic in range(0,C):
                                if ir>1 or ic>1:
                                    mat[ir,ic]=1
                    elif rM==6:
                        mat[0,0]=2
                        for ir in range(0,R):
                            for ic in range(0,C):
                                if ir>1 or ic>2:
                                    mat[ir,ic]=1
                    else:
                        possible=False
                else:
                    if rM>=2*C+2:
                        mat[0,0]=2
                        MCount= M
                        for ir in reversed(range(0,R)):
                            if MCount==0:
                                break
                            for ic in reversed(range(0,C)):
                                if MCount==1:
                                    if ic==1:
                                        mat[ir-1,C-1]=1
                                    else:
                                        mat[ir,ic]=1
                                    MCount=0
                                    break
                                else:
                                    mat[ir,ic]=1
                                    MCount-=1
                    else:
                        mat[0,0]= 2
                        sMCount= M-((R-2)*C-3)
                        MCount=M-sMCount
                        for ir in reversed(range(0,R)):
                            if MCount==0:
                                break
                            for ic in reversed(range(0,C)):
                                if MCount==0:
                                    break
                                mat[ir,ic]=1
                                MCount-=1

                        if sMCount%2==1:
                            mat[2,2]=1
                            sMCount-=1
                        for i in range(C-sMCount/2,C):
                            mat[0,i]=1
                            mat[1,i]=1
        if not possible:
            results.append("\nImpossible")
        else:
            if swapped:
                mat= np.transpose(mat)
            entry=[]
            for ir in range(0,len(mat)):
                entry.append("\n")
                for ic in range(0,len(mat[0])):
                    if mat[ir,ic]==0:
                        entry.append(".")
                    if mat[ir,ic]==1:
                        entry.append("*")
                    if mat[ir,ic]==2:
                        entry.append("c")
            results.append("".join(entry))

for iRes in range(0,len(results)):
    print "Case #%d:%s"%(iRes+1,results[iRes])