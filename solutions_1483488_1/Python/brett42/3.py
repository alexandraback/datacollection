
def f(n,digits):
	p=10**digits
	m=10**len(str(n))/p
	return n/p+(n%p*(m))
    
def go(a,b):
    r=set()
    for x in range(a,b+1):
        for y in range(1,len(str(a))):
            t=f(x,y)
            if a<=t and t<=b and t>x:
                r.add((x,t))
    return len(r)

infile=open('C-large.in')
cases=int(infile.readline())
for c in range(1,cases+1):
    l=infile.readline().split()
    a=int(l[0])
    b=int(l[1])
    print 'Case #%d: %d'%(c,go(a,b))
infile.close()
    
