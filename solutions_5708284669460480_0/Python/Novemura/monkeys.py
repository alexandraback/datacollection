import datetime

def getnuml(ll,retu,L,S):
    numl=0
    for i in range(S-L+1):
        if ll==retu[i:i+L]:
            numl+=1
    return numl


def main():
    filename='B-small-attempt0.in'
    F=open(filename,'r')
    T=int(F.readline())
    answer=[]
    for q in range(T):
        d=datetime.datetime.today()
        #read text and make answer as ans for each  question
        [K,L,S]=[int(x) for x in F.readline().split()]
        kb=F.readline().strip()
        ll=F.readline().strip()
        retuzu=[k for k in kb]
        for i in range(S-1):
            newretuzu=[]
            for retu in retuzu:
                for k in kb:
                    newretuzu.append(retu+k)
            retuzu=newretuzu[:]
        #print retuzu
        req=0
        ss=0.0
        for retu in retuzu:
            numl=getnuml(ll,retu,L,S)
            ss+=numl
            req=max(req,numl)
        #print req,ss
        ans=req-ss/len(retuzu)
        ans=str(ans)
        print 'Case:%d %sh%sm%s.%ssecn' % (q,d.hour, d.minute, d.second, d.microsecond)
        print ans
        answer.append('Case #'+str(q+1)+': '+ans+'\n')
    F.close()
    makeanswer(filename,answer)
     
def makeanswer(filename,answer):
    F=open('answer_'+filename,'w')
    F.writelines(answer)
    F.close()