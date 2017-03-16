import datetime

def main():
    filename='A-small-attempt2.in'
    F=open(filename,'r')
    T=int(F.readline())
    answer=[]
    dp=[0 for i in range(10**6+1)]
    dp[1:12]=range(1,12)
    print dp[1:20]
    for s in range(11,10**6+1):
        rev=int(str(s)[::-1])
        if rev>=s or s!=int(str(rev)[::-1]):
            dp[s]=dp[s-1]+1
        else:
            dp[s]=min(dp[s-1]+1,dp[rev]+1)
       # print dp[s]
    print dp[1:30]
    for q in range(T):
        d=datetime.datetime.today()
        #read text and make answer as ans for each  question
        N=int(F.readline())
        ans=dp[N]
#        while(s<N):
#            rev=int(str(s)[::-1])
#            if rev>N:
#                s=s+1
#                ans+=1
#            else:
#                if s+1>rev:
#                    s=s+1
#                else:
#                    s=rev
#                ans+=1
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