import datetime
import itertools

def main():
    filename='test.txt'
    F=open(filename,'r')
    T=int(F.readline())
    answer=[]
    for q in range(T):
        d=datetime.datetime.today()
        #read text and make answer as ans for each  question
        [N,J]=[int(x) for x in F.readline().split()]
        
        #Small Dataset
        #2~14 4 1s, two for odd digit, 2 for even digit
        #nontrivial= 3,2,3,2,7,3,3,2,3
        odddigit=[2*x+1 for x in range(6)]
        evendigit=[2*(x+1) for x in range(6)]
        
        odl=list(itertools.combinations(odddigit,2))
        edl=list(itertools.combinations(evendigit,2))
        
        allanslist=[]
        
        for oo in odl:
            for ee in edl:
                aalist=[1]+[0]*14+[1]
                for o in oo:
                    aalist[o]=1
                for e in ee:
                    aalist[e]=1
                allanslist.append(''.join([str(x) for x in aalist]))
                
        #checkallans
        for an in allanslist[:J]:
            for k in range(9):
                div=[3,2,3,2,7,3,3,2,3][k]
                AN=0
                for i in range(N):
                    AN+=int(an[i])*(k+2)**i
                if AN%div!=0:
                    print False
        
        ans=''
        for i in range(J):
            ans+=allanslist[i]+' 3 2 3 2 7 3 3 2 3 \n'
        print 'Case:%d %sh%sm%s.%ssecn' % (q,d.hour, d.minute, d.second, d.microsecond)
        print ans
        answer.append('Case #'+str(q+1)+': '+str(ans)+'\n')
    F.close()
    makeanswer(filename,answer)

def makeanswer(filename,answer):
    F=open('answer_'+filename,'w')
    F.writelines(answer)
    F.close()