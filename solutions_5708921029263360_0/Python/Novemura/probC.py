import datetime
import string

def countpairs(anslist,j,p,s):
    nj=0
    np=0
    ns=0
    for outfit in anslist:
        if (outfit[1]==p and outfit[2]==s):
            nj+=1
        if (outfit[0]==j and outfit[2]==s):
            np+=1
        if (outfit[1]==p and outfit[0]==j):
            ns+=1
    ret= max(nj,np,ns)
    return ret
    
def main():
    filename='C-small-attempt0.in'
    F=open(filename,'r')
    T=int(F.readline())
    answer=[]
    for q in range(T):
        d=datetime.datetime.today()
        #read text and make answer as ans for each  question
        [J,P,S,K]=[int(x) for x in F.readline().split()]
        anslist=[]
        for j in range(J):
            for p in range(P):
                for s in range(S):
                   if countpairs(anslist,j,p,s)<K:
                       anslist.append([j,p,s])
        ans=str(len(anslist))+"\n"
        for outfit in anslist:
            ans+=' '.join([str(x+1) for x in outfit])+"\n"
        ans.strip()
        
        print 'Case:%d %sh%sm%s.%ssecn' % (q,d.hour, d.minute, d.second, d.microsecond)
        print ans
        answer.append('Case #'+str(q+1)+': '+str(ans)+'\n')
    F.close()
    makeanswer(filename,answer)
     
def makeanswer(filename,answer):
    F=open('answer_'+filename,'w')
    F.writelines(answer)
    F.close()