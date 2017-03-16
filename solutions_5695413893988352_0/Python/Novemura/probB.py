import datetime
import itertools

def main():
    filename='B-small-attempt0.in'
    F=open(filename,'r')
    T=int(F.readline())
    answer=[]
    for q in range(T):
        d=datetime.datetime.today()
        #read text and make answer as ans for each  question
        [C,J]=F.readline().split()
        digits=len(C)
        #000~999
        allps=[''.join(x) for x in itertools.product('0123456789', repeat=digits)]
        Ccand=[]
        Jcand=[]
        #check if ok for c and j
        for ps in allps:
            for i in range(digits):
                if not (ps[i]==C[i] or C[i]=='?'):
                    break
            else:
                Ccand.append(ps)
                
            for i in range(digits):
                if not (ps[i]==J[i] or J[i]=='?'):
                    break
            else:
                Jcand.append(ps)
        mindif=999999999999999
        anslist=[99999999,999999999]
        for c in Ccand:
            for j in Jcand:
                abscj=abs(int(c)-int(j))
                if abscj<mindif:
                    anslist=[c,j]
                    mindif=abscj
                elif abscj==mindif:
                    if c<anslist[0]:
                        anslist=[c,j]
                    elif c==anslist[0] and j<anslist[1]:
                        anslist=[c,j]
        ans=' '.join(anslist)
        print 'Case:%d %sh%sm%s.%ssecn' % (q,d.hour, d.minute, d.second, d.microsecond)
        print ans
        answer.append('Case #'+str(q+1)+': '+str(ans)+'\n')
    F.close()
    makeanswer(filename,answer)
     
def makeanswer(filename,answer):
    F=open('answer_'+filename,'w')
    F.writelines(answer)
    F.close()