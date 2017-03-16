# -*- coding: utf-8 -*-
f = open('C-large.in','r')

count = f.readline().strip()

data = [line.strip() for line in f.readlines()]

f.close()

f = open('C-large.out','w')

for c in range(int(count)):
    T = c+1
    As,Bs = data[c].split()
    r = len(As)
    Ai = int(As)
    Bi = int(Bs)
    cnt = 0
    t = []
    
    for d in range(Ai,Bi+1):
        dd = str(d)*2
        i = 1
        j = i+r
        while(i<r):
            temp = int(dd[i:j])
            if temp >= Ai and temp <= Bi and temp != d:
                cnt = cnt +1
                t.append(str(d)+str(temp))
                #print str(d)+str(temp)
            i=i+1
            j=i+r
               
    out = 'Case #%d: %d'%(T,len(set(t))/2)+'\n'
    f.write(out)
    
f.close()
