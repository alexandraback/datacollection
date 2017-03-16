from sys import stdin


def getInt():
    return [int(i) for i in stdin.readline().split()]

def getFloat():
    return [float(i) for i in stdin.readline().split()]

def solve():
    si=getInt()
    sum=0
    n=si[0]
    si.pop(0)
    max1=0
    max2=0
    
    for i in range(n):
        sum+=si[i]

    for i in range(n):
        low=0.0
        up=1.0
        for j in range(100):
            mid=(low+up)/2
            su=si[i]+mid*sum
            u=0
            for j in range(n):
                if i==j:
                    continue
                if si[j]>=su:
                    continue
                u+=(su-si[j])/sum

            if u+mid<=1:
                low=mid
            else:
                up=mid
        print "%.8f"%(low*100),

    print 
        
    return 0


for i in range(getInt()[0]):
    print "Case #"+str(i+1)+":",
    solve()
