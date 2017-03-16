import math
import sys
sys.setrecursionlimit(100000)

def dis((x,y),(cx,cy)):
    return math.sqrt(abs(x-cx)**2+abs(y-cy)**2)

def ref((x,y),(x1,y1)):
    xd,yd = x,y
    if x1>x:
        xd += 2*(x1-x)
    else:
        xd -= 2*(x-x1)
    if y1>y:
        yd += 2*(y1-y)
    else:
        yd -= 2*(y-y1)
    return ((xd,yd))

ans = 0

def dfs(d,h,w,du,(x,y),uh):
    global ans
    a = "-"
    if x-cx==0:
        if y>cy:
            hu = "V"
        else:
            hu = "-V"
    elif y-cy==0:
        if x>cx:
            hu = "H"
        else:
            hu = "-H"
    else:
        hu = (1.*(y-cy))/(x-cx)
        if x>cx:
            a = "+"
    if 0<dis((x,y),(cx,cy))<=du and d.count((x,y))==0:
        if uh.count((hu,a))==0:
            ans += 1
        d.append((x,y))
        #print x,y,hu,a
        uh.append((hu,a))
        if d.count(ref((x,y),(x,1)))==0:
            dfs(d,h,w,du,ref((x,y),(x,1)),uh)
        if d.count(ref((x,y),(x,h-1)))==0:
            dfs(d,h,w,du,ref((x,y),(x,h-1)),uh)
        if d.count(ref((x,y),(1,y)))==0:
            dfs(d,h,w,du,ref((x,y),(1,y)),uh)
        if d.count(ref((x,y),(w-1,y)))==0:
            dfs(d,h,w,du,ref((x,y),(w-1,y)),uh)
            print (ref((x,y),(w-1,y))),x,y

f = open("in.txt","r")
g = open("out.txt","w")

for t in range(1,int(f.readline())+1):
    print t
    st = f.readline().strip("\n").split()
    h = int(st[0])
    w = int(st[1])
    du = int(st[2])
    cx = 0.
    cy = 0.
    for i in range(h):
        aha = f.readline().find('X')
        if aha!=-1:
            cx = aha+0.5
            cy = i+0.5

    d = []
    uh = []
    ans = 0
    dfs(d,h,w,du,ref((cx,cy),(cx,1)),uh)
    dfs(d,h,w,du,ref((cx,cy),(cx,h-1)),uh)
    dfs(d,h,w,du,ref((cx,cy),(1,cy)),uh)
    dfs(d,h,w,du,ref((cx,cy),(w-1,cy)),uh)

    g.write("Case #"+str(t)+": "+str(ans)+"\n")

f.close()
g.close()
