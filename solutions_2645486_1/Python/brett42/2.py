def go():
    f=open('B-large.in')
    for case in range(int(f.readline())):
        print 'Case #%d: %s'%(case+1,solve(f))

def solve(f):
    line1=[int(x) for x in f.readline().split()]
    v=[int(x) for x in f.readline().split()]
    e=line1[0]
    maxe=e
    r=line1[1]
    ret=0
    for x in range(len(v)):
        if x==len(v)-1:
            ret+=v[x]*e
            break
        
        nextgood=0
        for y in range(len(v[x+1:x+2+maxe/r])):
            if v[x+1:][y]>=v[x]:
                nextgood=y+1
                break
        if nextgood==0:
            ret+=v[x]*e
            e=0            
        elif e+r*nextgood<maxe:
            burnable=0
        else:
            
            burnable=e+r*nextgood-maxe
            if burnable>e:
                burnable=e
            ret+=burnable*v[x]
            e-=burnable
        e+=r

    return ret
