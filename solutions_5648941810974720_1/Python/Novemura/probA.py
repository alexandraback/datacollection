import datetime
import string

def main():
    filename='A-large.in'
    F=open(filename,'r')
    T=int(F.readline())
    answer=[]
    for q in range(T):
        d=datetime.datetime.today()
        #read text and make answer as ans for each  question
        S=F.readline()
        ans=createanswer(S)        
        print 'Case:%d %sh%sm%s.%ssecn' % (q,d.hour, d.minute, d.second, d.microsecond)
        print ans
        answer.append('Case #'+str(q+1)+': '+str(ans)+'\n')
    F.close()
    makeanswer(filename,answer)
     
def makeanswer(filename,answer):
    F=open('answer_'+filename,'w')
    F.writelines(answer)
    F.close()
    
    
def createanswer(S):
    cntlist=[0 for i in range(10)]
    numberofascii=[S.count(x) for x in string.ascii_uppercase]
    #eight
    cntlist[8]=numberofascii[6]
    
    #SIX
    cntlist[6]=numberofascii[23]
    #FOUR
    cntlist[4]=numberofascii[20]
    #TWO
    cntlist[2]=numberofascii[22]
    #ZERO
    cntlist[0]=numberofascii[25]
    #SEVEN
    cntlist[7]=numberofascii[18]-cntlist[6]
    #THREE
    cntlist[3]=numberofascii[7]-cntlist[8]
    #five
    cntlist[5]=numberofascii[21]-cntlist[7]
    #nine
    cntlist[9]=numberofascii[8]-cntlist[5]-cntlist[8]-cntlist[6]
    #one
    cntlist[1]=numberofascii[13]-cntlist[7]-cntlist[9]*2
    
    ret=''
    for i in range(10):
        ret+=str(i)*cntlist[i]
    return ret