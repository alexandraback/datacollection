# -*- coding: utf-8 -*-
f = open('B-large.in','r')

count = f.readline().strip()

data = [line.strip() for line in f.readlines()]

f.close()

f = open('B-large.out','w')

for c in range(int(count)):
    T = c + 1
    d = data[c].split()
    N,s,p = int(d[0]),int(d[1]),int(d[2])
    v = 3*(p-1)+1
    t = []
    cnt = 0
    
    for p in range(3,3+N):
        t.append(int(d[p]))

    #print N,s,p,v

    t.sort(lambda a,b :-cmp(a,b))
    #print t
    for a in t:
    #    print a,s,cnt
        if a>=v:
            cnt=cnt+1
        elif a<v:
            if s>0 and a>=v-2 and a>1:
                cnt=cnt+1
                s=s-1
            else:
                break
    #print cnt
                
    out = 'Case #%d: %d'%(T,cnt)+'\n'
    #print out
    f.write(out)
    

f.close()
