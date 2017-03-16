import datetime

def main():
    filename='A-large.in'
    F=open(filename,'r')
    T=int(F.readline())
    answer=[]
    for q in range(T):
        d=datetime.datetime.today()
        #read text and make answer as ans for each  question
        [R,C,W]=[int(x) for x in F.readline().split()]
        bb=(R-1)*(C/W)
        ans=((C/W-1)+W)+bb
        if C%W!=0:
            ans+=1
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