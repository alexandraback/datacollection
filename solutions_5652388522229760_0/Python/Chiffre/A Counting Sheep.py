def removal(n,d):
    for j in map(int,list(str(n))):
        if j in d:
            d.remove(j)
    return d

t=input()
l=[]
for i in range(t):
    l.append(input())
for i in range(len(l)):
    n=l[i]
    c=n
    if c==0:
        print 'Case #'+str(i+1)+': '+'INSOMNIA'
    else:
        d=range(10)
        while n/c<200:
            if not d:
                break
            else:
                removal(n,d)
                n=n+c
        if d:
            print 'Case #'+str(i+1)+': '+'INSOMNIA'
        else:
            print 'Case #'+str(i+1)+': '+str(n-c)        
