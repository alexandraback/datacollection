import datetime

def main():
    filename='C-small-attempt0.in'
    F=open(filename,'r')
    T=int(F.readline())
    answer=[]
    for q in range(T):
        d=datetime.datetime.today()
        #read text and make answer as ans for each  question
        [C,D,V]=[int(x) for x in F.readline().split()]
        vals=range(1,V+1)
        dom=[int(x) for x in F.readline().split()]+[0]
        ans=0
        #C=1only
        #def
        pos=[0]
        for dd in dom:
            newpos=[]
            for p in pos:
                newpos.append(p+dd)
            pos=pos+newpos[:]
        #print pos
        unable=[]
        for v in vals:
            if v not in pos:
                unable.append(v)
        vals=sorted(unable)
        while len(vals)!=0:
            newd=vals[0]
            ans+=1
            for p in pos:
                newpos.append(p+newd)
            pos=pos+newpos[:]
            unable=[]
            for v in vals:
                if v not in pos:
                    unable.append(v)
            vals=sorted(unable)
            # vals
        print 'Case:%d %sh%sm%s.%ssecn' % (q,d.hour, d.minute, d.second, d.microsecond)
        print ans
        answer.append('Case #'+str(q+1)+': '+str(ans)+'\n')
    F.close()
    makeanswer(filename,answer)
     
def makeanswer(filename,answer):
    F=open('answer_'+filename,'w')
    F.writelines(answer)
    F.close()