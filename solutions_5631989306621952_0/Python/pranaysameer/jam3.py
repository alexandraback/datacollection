n=int(raw_input())
for j in range(0,n):
    x=raw_input()
    sol=x[0]
    y=x[1:len(x)]
    for i in y:
        if ord(i)>=ord(sol[0]):
            sol=i+sol
        else:
            sol=sol+i
    print "Case #"+str(j+1)+": "+sol
        
