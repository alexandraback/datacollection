triangles=[0]*2001
for i in range(2000):
    triangles[i+1]=triangles[i]+i+1

def parse():
    with open('B-small-attempt1.in','r') as f:
        cases=int(f.readline())
        for i in range(cases):
            a,b=f.readline().split(' ')
            a,b=int(a),int(b)
            ans=answer(a,b)
            print 'Case #'+str(i+1)+': '+str(ans)

def answer(a,b):
    direcs=direc(a,b)
    a,b=abs(a),abs(b)
    (i,n)=search(a+b)
    s=(n-a-b)/2
    dirs,moves=move(a,b,s,i,n)
    out=''
    for j in range(i):
        offset=0
        if moves[j]==1:
            offset=offset+1
        if dirs[j]==-1:
            offset=offset+2
        out=out+direcs[offset]
    return out

def move(a,b,s,i,n):
    x,y=a+s,b
    dirs=[-1]*i
    moves=[0]*i
    k=i
    x=x+s
    while y>0 or x>0:
        m=max(x,y,s)
        if k<=m:
            if x>=y:
                x=x-k
                dirs[k-1]=1
            elif y>=x:
                moves[k-1]=1
                dirs[k-1]=1
                y=y-k

        k=k-1
    return dirs,moves
            

def search(n):#remember same parity
    left=0
    right=2000
    while right-left>1:
        middle=(left+right)/2
        if triangles[middle]>=n:
            right=middle
        elif triangles[middle]<n:
            left=middle
    if (triangles[left+1]-n)%2==0:
        return (left+1,triangles[left+1])
    elif (triangles[left+2]-n)%2==0:
        return (left+2,triangles[left+2])
    else:
        return (left+3,triangles[left+3])

def direc(a,b):
    dirs=['E','N','W','S']
    if a<0:
        dirs[2]='E'
        dirs[0]='W'
    if b<0:
        dirs[1]='S'
        dirs[3]='N'
    return dirs


parse()
