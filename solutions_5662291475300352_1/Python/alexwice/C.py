
def solve(N,A):
    #print N,A
    #Each item in A is a group: D, H, M
    #Representing H hikers starting at D that take M, M+1, ... M+H-1 to revolve
    #Lets try to stunt the small quickly
    B = []
    for d,h,m in A:
        for i in xrange(h):
            B.append((d,m+i))
    #B are all the hikers
    
    #If theres only one hiker, you can do it
    if len(B)<=1: return 0
    B.sort()
    ans = 0
    for i in xrange(len(B)-1):
        for j in xrange(i+1,len(B)):
            a,x = B[i]
            b,y = B[j]
            if x==y: return 0
            if x>y:
                if (720-b)*y <= (360-a)*x: ans+=1
            else:
                if (720-a)*x <= (360-b)*y: ans+=1
    return ans 

        
    
########
fo = open('out.txt','w')
with open('in.txt','r') as fi:
    rr = lambda: fi.readline().strip()
    rrI = lambda: int(rr())
    rrM = lambda: map(int,rr().split())
    for tc in xrange(rrI()):
        N = rrI()
        A = [rrM() for i in xrange(N)]
        zetaans = solve(N,A)
        zeta = "Case #%i: "%(tc+1) + str(zetaans)
        print zeta
        fo.write(zeta+'\n')
fo.close()
