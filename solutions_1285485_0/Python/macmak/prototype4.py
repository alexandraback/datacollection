import fileinput

T=-1
case=1

def makeXgrid(a4,a2,D):
    grid=[0.0]
    l=0
    while l<=D:
        grid.append(grid[-1]+a2*2)
        grid.append(grid[-1]+a4*2)
        grid.insert(0,grid[0]-2*a4)
        grid.insert(0,grid[0]-2*a2)
        l+=2*a2+2*a4
    return grid

def makeGrid(a1,a2,a3,a4,D):
    xgrid=makeXgrid(a4,a2,D)
    ygrid=makeXgrid(a1,a3,D)
    return xgrid,ygrid

inp=fileinput.input()
for line in inp:
    if T<0:
        T=int(line)
    else:
        mmap={}
        me=()
        walls=[]
        empty=[]
        num=line.split(' ')
        H=int(num[0])
        W=int(num[1])
        D=int(num[2])
        for h in xrange(H):
            string=inp.next()
            for w in xrange(W):
                mmap[w,h]=string[w]
                if string[w]=='X':
                    me=(w,h)
                elif string[w]=='.':
                    empty.append((w,h))
                elif string[w]=='#':
                    walls.append((w,h))
        # for solving small part we need only 'me' and H,W,D
        a1=me[1]-0.5
        a4=me[0]-0.5
        a2=W-1-0.5-me[0]
        a3=H-1-0.5-me[1]
        #print a1,a2,a3,a4
        xgrid,ygrid = makeGrid(a1,a2,a3,a4,D)
        images=set()
        D2=D**2
        for x in xgrid:
            for y in ygrid:
                if x!=0 or y!=0:
                    #print 'considering ',x,y 
                    if x**2+y**2<=D2:
                        norm=(x**2+y**2)**0.5
                        images.add(((x/norm).__str__()[:8],(y/norm).__str__()[:8]))
        #print images
        
        print 'Case #%s: %i'%(case,images.__len__())
        case+=1
        if case>T:
            break
