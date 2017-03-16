def dist(mi,mx):
    ans={}
    d=[]
    if(mx<10):
        return 0
    for i in range(mi,mx+1):
        s=str(i)
        for e in range(1,len(s)):
            new_s=s[e:]+s[:e]
            if (not (int(new_s),i) in d) and (not (i,int(new_s)) in d) :
                if int(new_s)<=mx and int(new_s)!=i and int(new_s)>=mi:
                    ans[i]=int(new_s)
                    d.append((int(new_s),i))
    return len(d)
def test():
    filea=open('C-small-attempt0.in','r')
    fileb=open('c-Large','w')
    total=int(filea.readline().strip())
    for case in range(1,total+1):
        ss="Case #"+str(case)+": "
        li=filea.readline().strip()
        li=li.split(" ")
        mx=int(li[0])
        mi=int(li[1])
        ss=ss+str(dist(mx,mi))
        fileb.write(ss+"\n")