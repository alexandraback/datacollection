import string

def go():
    f=open('2.in')
    c=int(f.readline())
    for case in range(1,c+1):        
        print 'Case #%d:'%case,
        print solve(f)
    f.close()

    

def solve(f):
    n=int(f.readline())
    d={}
    for x in range(n*2-1):
        l=[int(x) for x in f.readline().split()]
        for y in l:
            if y in d:
                d[y]+=1
            else:
                d[y]=1
    l=[int(x) for x in d if d[x]%2]
    l.sort()
    l=[str(x) for x in l]
    s=string.join(l,' ')
    return s
        
        
        
    
    

    
        
