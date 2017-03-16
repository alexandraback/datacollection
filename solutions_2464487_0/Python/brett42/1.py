def go():
    f=open('A-small-attempt0.in')
    for case in range(int(f.readline())):
        print 'Case #%d: %s'%(case+1,solve(f))

def solve(f):
    inline=f.readline().split()
    r=int(inline[0])
    t=int(inline[1])

    ret=0
    oldarea=r**2
    while 1:
        r+=1
        newarea=r**2
        d=newarea-oldarea
        if d<=t:
            ret+=1
            t-=d
        else:
            break
        r+=1
        oldarea=r**2
    return ret
        
    
