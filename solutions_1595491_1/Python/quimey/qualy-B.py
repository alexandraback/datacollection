T=int(raw_input())
for t in range(T):
    l=map(int,raw_input().split())
    N=l[0]
    S=l[1]
    p=l[2]
    tt=l[3:]
    tt.sort()
    tt=tt[::-1]
    c=0
    for x in tt:
        if x%3==0:
            if x/3>=p:
                c+=1
            elif x/3+1>=p and S and x/3>0:
                c+=1
                S-=1
        elif x%3==1:
            if x/3+1>=p:
                c+=1
        elif x%3==2:
            if x/3+1>=p:
                c+=1
            elif x/3+2>=p and S:
                c+=1
                S-=1
    #print S
    print "Case #%d:"%(t+1),c
