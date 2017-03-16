import datetime
import bisect
import itertools

def asciibin(seq):
    return [ord(s) for s in seq]


def main():
    filename='C-small-attempt2.in'
    F=open(filename,'r')
    T=int(F.readline())
    answer=[]
    for q in range(T):
        d=datetime.datetime.today()
        #read text and make answer as ans for each  question
        N=int(F.readline())
        topiclist=[]
        dictA=[]
        dictB=[]
        for i in range(N):
            topicascii=F.readline().split()
            topicA=int(''.join([str(x) for x in asciibin(topicascii[0])]))
            topicB=int(''.join([str(x) for x in asciibin(topicascii[1])]))
            topic=[topicA,topicB]
            topiclist.append(topic)
            dictA.append(topic[0])
            dictB.append(topic[1])
        dictA.sort()
        dictB.sort()
        print dictA
        ans=0

        #create scenario
        for scenario in itertools.product((0,1), repeat=N):
            truetopic=[topiclist[x] for x in range(N) if not scenario[x]]
            talist=[top[0] for top in truetopic]
            tblist=[top[1] for top in truetopic]
            falsetopic=[topiclist[x] for x in range(N) if scenario[x]]
            for ft in falsetopic:
                if not( ft[0] in talist and ft[1] in tblist):
                    break
            else:
                ans=max(ans,sum(scenario))

        print 'Case:%d %sh%sm%s.%ssecn' % (q,d.hour, d.minute, d.second, d.microsecond)
        print ans
        answer.append('Case #'+str(q+1)+': '+str(ans)+'\n')
    F.close()
    makeanswer(filename,answer)
     
def makeanswer(filename,answer):
    F=open('answer_'+filename,'w')
    F.writelines(answer)
    F.close()