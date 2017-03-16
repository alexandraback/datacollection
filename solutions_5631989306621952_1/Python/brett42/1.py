def go():
    f=open('1.in')
    c=int(f.readline())
    for case in range(1,c+1):        
        print 'Case #%d:'%case,
        print solve(f.readline())
    f.close()

    

def solve(s):
    s=s.replace('\n','')
    r=s[0]
    for c in s[1:]:
        if ord(c)>=ord(r[0]):
            r=c+r
        else:
            r=r+c
    return r

    
        
