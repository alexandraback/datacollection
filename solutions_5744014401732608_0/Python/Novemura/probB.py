import datetime
import string
import itertools
def calcways(pattern,BB):# calculate ways to go to B from city k
    ret=0
    tmp=0
    #print pattern,BB
    for i in range(BB-1):
        tmp+=(BB-i)
        ret+=pattern[i]*calcways(pattern[tmp:],BB-i-1)
    ret+=pattern[BB-1]
    return ret
    
def main():
    filename='B-small-attempt0.in'
    F=open(filename,'r')
    T=int(F.readline())
    answer=[]
    for q in range(T):
        d=datetime.datetime.today()
        #read text and make answer as ans for each  question
        [B,M]=[int(x) for x in F.readline().split()]
        for pattern in itertools.product([0,1],repeat=(B**2-B)/2):
            actualslide=[]
            tmp=0
            #for i in range(B-1,0,-1):
                #actualslide.append([0]*(B-i)+pattern[tmp:i])
                #tmp+=i
            ways=calcways(pattern,B-1)
            if ways==M:
                ans="POSSIBLE\n"
                tmp=0
                for i in range(1,B):
                    ans+="0"*i+''.join([str(x) for x in pattern[tmp:tmp+(B-i)]])+"\n"
                    tmp+=B-i
                ans+="0"*B
                break
        else:
            ans="IMPOSSIBLE"
        print 'Case:%d %sh%sm%s.%ssecn' % (q,d.hour, d.minute, d.second, d.microsecond)
        print ans
        answer.append('Case #'+str(q+1)+': '+str(ans)+'\n')
    F.close()
    makeanswer(filename,answer)
     
def makeanswer(filename,answer):
    F=open('answer_'+filename,'w')
    F.writelines(answer)
    F.close()