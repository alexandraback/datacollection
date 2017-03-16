import datetime

def main():
    filename='A-large.in'
    F=open(filename,'r')
    T=int(F.readline())
    answer=[]
    for q in range(T):
        d=datetime.datetime.today()
        #read text and make answer as ans for each  question
        N=int(F.readline())
        N0=N
        if N==0:
            ans="INSOMNIA"
        else:
            flag=[0 for i in range(10)]
            Nchar=str(N)
            for c in Nchar:
                flag[int(c)]=1
            while flag!=[1,1,1,1,1,1,1,1,1,1]:
                N+=N0
                #print N
                Nchar=str(N)
                for c in Nchar:
                    flag[int(c)]=1
            ans=N
        print 'Case:%d %sh%sm%s.%ssecn' % (q,d.hour, d.minute, d.second, d.microsecond)
        print ans
        answer.append('Case #'+str(q+1)+': '+str(ans)+'\n')
    F.close()
    makeanswer(filename,answer)
     
def makeanswer(filename,answer):
    F=open('answer_'+filename,'w')
    F.writelines(answer)
    F.close()