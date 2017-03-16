import datetime

def main():
    filename='B-small-attempt0.in'
    F=open(filename,'r')
    T=int(F.readline())
    answer=[]
    for q in range(T):
        d=datetime.datetime.today()
        #read text and make answer as ans for each  question
        P=F.readline().strip()
        Pbool=[1 if x=='+' else 0 for x in P]
        mode=Pbool[0]
        ans=0
        for i in range(len(P)):
            if Pbool[i]!=mode:
                ans+=1
                mode=Pbool[i]
        if mode==0:
            ans+=1
        print 'Case:%d %sh%sm%s.%ssecn' % (q,d.hour, d.minute, d.second, d.microsecond)
        print ans
        answer.append('Case #'+str(q+1)+': '+str(ans)+'\n')
    F.close()
    makeanswer(filename,answer)
     
def makeanswer(filename,answer):
    F=open('answer_'+filename,'w')
    F.writelines(answer)
    F.close()