f=open('B-large.in')
cases=int(f.readline())
for c in range(1,cases+1):
    l=f.readline().split()
    l.pop(0)
    s=int(l.pop(0))
    p=int(l.pop(0))
    r=0
    for x in l:
        x=int(x)

        if x-p<0:
            continue
        
        low=(x-p)/2
        if p-low<=1:
            r+=1
        elif p-low<=2 and s:
            r+=1
            s-=1
    print 'Case #%d: %d'%(c,r)


f.close()

