def check(n):
    if(str(n)==str(n)[::-1] and str(n*n)==str(n*n)[::-1]):
        return 1
    else:
        return 0

n=input()
for i in range(n):
    cnt=0
    s=raw_input()
    s=s.split()
    x=int(s[0])
    y=int(s[1])
    p=x**(0.5)
    if(p-int(p)):
       p+=1
    p=int(p)
    q=int(y**(0.5))
#    print x,y,p,q
    print "Case #"+str(i+1)+": "+str(len(filter(check,range(p,q+1))))
