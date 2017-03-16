import datetime

def main():
    filename='C-large.in'
    F=open(filename,'r')
    T=int(F.readline())
    answer=[]
    for q in range(T):
        d=datetime.datetime.today()
        #read text and make answer as ans for each  question
        [C,D,V]=[int(x) for x in F.readline().split()]
        dom=sorted([int(x) for x in F.readline().split()])
        ans=0
        baseline=C+1
        if 1 not in dom:
            ans=1
        else:
            dom.pop(0)
        bb=1
        b2=C
        while b2<V and len(dom)>=1:
            reqb=b2+1
            if dom[0]<=reqb:
                b2+=C*dom.pop(0)
                while(len(dom)>=1 and b2>=dom[0]):
                    b2+=C*dom.pop(0)
            else:
                #print reqb
                ans+=1
                b2+=C*reqb
                while(len(dom)>=1 and  b2>=dom[0]):
                    b2+=C*dom.pop(0)
        #while(dom[-1]>=bb):
        #    if bb not in dom:
        #        ans+=1
        #        dom.append(bb)
        #    dom.sort()
        #    bb=bb*baseline
        #required doms
        #b2=sum(dom)+1
        #ans+=V/b2
        
        ##C=1only
        ##def
        #pos=[0]
        #for dd in dom:
        #    newpos=[]
        #    for p in pos:
        #        newpos.append(p+dd)
        #    pos=pos+newpos[:]
        #print pos
        #unable=[]
        #for v in vals:
        #    if v not in pos:
        #        unable.append(v)
        #vals=sorted(unable)
        #while len(vals)!=0:
        #    newd=vals[0]
        #    ans+=1
        #    for p in pos:
        #        newpos.append(p+newd)
        #    pos=pos+newpos[:]
        #    unable=[]
        #    for v in vals:
        #        if v not in pos:
        #            unable.append(v)
        #    vals=sorted(unable)
        #    print vals
        print 'Case:%d %sh%sm%s.%ssecn' % (q,d.hour, d.minute, d.second, d.microsecond)
        print ans
        answer.append('Case #'+str(q+1)+': '+str(ans)+'\n')
    F.close()
    makeanswer(filename,answer)
     
def makeanswer(filename,answer):
    F=open('answer_'+filename,'w')
    F.writelines(answer)
    F.close()