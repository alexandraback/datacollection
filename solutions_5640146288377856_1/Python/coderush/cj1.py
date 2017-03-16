import sys
f=open("input.txt",'r')
f1=open("output.txt",'w')
sys.stdin=f
sys.stdout=f1


t=int(raw_input())
for test in xrange(t):
    r,c,w=map(int,raw_input().split())
    ans=c/w*r
    ans+=w-1
    if (c%w!=0):
        ans+=1
    print "Case #"+str(test+1)+": "+str(ans)
f.close()
f1.close()
