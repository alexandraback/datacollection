import sys
sys.stdin=open("K.txt",'r')
sys.stdout=open("OUT.txt",'w')
for t in xrange(int(raw_input())):
    a=int(raw_input())
    hiker=[]
    circ=1.0
    for i in xrange(a):
        b,c,d=map(int,raw_input().split())
        for k in xrange(c):
            hiker.append((b,d+k))
    hiker.sort()
    if a<=1 or hiker[0][1]==hiker[1][1]:
        ans=0
    else:
        v1=circ/hiker[0][1]
        v2=circ/hiker[1][1]
        time1=(360-hiker[0][0])/360.0*circ/v1
        time2=(360-hiker[1][0])/360.0*circ/v2
        time3=max(time1,time2)+0.0001
        time1+=hiker[0][1]
        time2+=hiker[1][1]
        if time3<min(time1,time2):ans=0
        else:ans=1
    print 'Case #%i: %i'%(t+1,ans)
sys.stdout.close()

