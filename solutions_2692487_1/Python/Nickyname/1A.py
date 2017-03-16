g_l=[]
def l_mote(m,l,ans,le):
    if ans>=le:
        global g_l
        g_l.append(le)
        return le
    else:
        if len(l)==0:
            g_l.append(ans)
            return ans
        if(m<=l[0]):
            if(m!=1):
                r_ans=ans
                r_m=m
                while(r_m<=l[0]):
                    r_ans+=1
                    r_m+=r_m-1
                l_mote(r_m,l,r_ans,le)
            ans+=1
            l_mote(m,l[1:],ans,le)
        else:
            m+=l[0]
            l_mote(m,l[1:],ans,le)
def mote(m,l,ans):
    if len(l)==0:
        return ans
    else:
        if (m<=l[0] and (m+m-1)>l[0]):
            ans+=1
            m+=m-1
            return mote(m,l,ans)
        else:
            if(m<=l[0] and (m+m-1)<=l[0]):
                ans+=1
                return mote(m,l[1:],ans)
            else:
                m+=l[0]
                return mote(m,l[1:],ans)

def a():
    f=open('A-large.in','r')
    w=open('a.txt','w')
    line=int(f.readline())
    for i in range(line):
        s=f.readline()
        l=s.split()
        m=int(l[0])
        s=f.readline()
        q=s.split()
        l=[]
        for a in q:
            l.append(int(a))
        l.sort()
        ##print(m)
        ##print(l)
        global g_l
        g_l=[]
        l_mote(m,l,0,len(l))
        answer="Case #"+str(i+1)+": "+str(min(g_l))+"\n"
        ##print(answer)
        w.write(answer)