def point(num,mx):
    if num<(3*mx-4):
        return False
    else:
        flag=[]
        for a in range(mx,11):
            if (a-2)<0:
                ma=0
            else:
                ma=a-2
            for b in range(ma,11):
                for c in range(ma,11):
                    if (b-c)<=2 and (a-b)<=2 and (a-c)<=2 and (a+b+c)==num:
                        if (a-b)==2 or (a-c)==2:
                            flag.append(2)
                        else:
                            return 1
        if 1 in flag:
            return 1
        if 2 in flag:
            return 2
        return 0
def judg(l,mx,s):
    a=[]
    for i in l:
        if point(int(i),mx)==1:
            a.append(1)
        elif point(int(i),mx)==2 and s>0:
            s=s-1
            a.append(1)
        else:
            a.append(0)
    return sum(a)
def test():
    filea=open('B-small-attempt0.in','r')
    fileb=open('output-Large','w')
    total=int(filea.readline().strip())
    for case in range(1,total+1):
        ss="Case #"+str(case)+": "
        li=filea.readline().strip()
        li=li.split(" ")
        s=int(li[1])
        mx=int(li[2])
        li=li[3:]
        ss=ss+str(judg(li,mx,s))
        fileb.write(ss+"\n")