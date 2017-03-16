import sys
t=int(raw_input())
for cs in range(1,t+1):
    nums=map(int,raw_input().split(' '))
    N=nums[0]
    S=nums[1]
    p=nums[2]
    pts=nums[3:]
    res=0
    sc=0
    for i in range(N):
        done=False
        for j in range(3):
            a = (pts[i]+j)/3
            b = (pts[i]+j)%3
            if b>0:
                continue
            if (a>=1 or j==0) and a>=p and a<=10:
                res+=1
                done=True
                break
        if not done and sc<S:
            a = (pts[i]+3)/3
            b = (pts[i]+3)%3
            if b==0 and a>=2 and a>=p and a<=10:
                res+=1
                sc+=1
                continue
            a = (pts[i]+4)/3
            b = (pts[i]+4)%3
            if b==0 and a>=2 and a>=p and a<=10:
                res+=1
                sc+=1

    print 'Case #%d: %d' % (cs,res)
