def positioner(k,c):
    pos=[]
    pointer=1
    level=1
    count=1
    while pointer<k:
        if level!=c:
            pointer+=1
            level+=1
            count+=(pointer-1)*(k**(c-level))
        else:
            pos.append(count)
            level=1
            pointer+=1
            count=(pointer-1)*(k**(c-level))+1
    pos.append(count)
    return pos

from math import ceil
t=input()
l=[]
for i in range(t):
    l.append(map(int, raw_input().split()))

for i in range(len(l)):
    [k,c,s]=l[i]
    oplist=[]
    q=ceil(float(k)/c)
    if q>s:
        print 'Case #'+str(i+1)+': IMPOSSIBLE'
        continue
    elif k==1:
        print 'Case #'+str(i+1)+': 1'
        continue
    elif k==q:
        print 'Case #'+str(i+1)+': '+' '.join(map(str,range(k+1)[1:]))
        continue
    else:
        print 'Case #'+str(i+1)+': '+' '.join(map(str,positioner(k,c)))
