data=open("jump.in").readlines()
out=open("jump.out","w")
c=1
for i in data[1:]:
    x=int(i.split()[0])
    print x
    y=int(i.split()[1])
    print y
    print ""
    
    r=''
    
    if y>=0:
        r+="SN"*y
    if y<0:
        r+="NS"*(-y)
    
    if x>=0:
        r+="WE"*x
    if x<0:
        r+="EW"*(-x)
    
    
        
    print "Case #"+str(c)+": "+r+"\n"
    out.write("Case #"+str(c)+": "+r+"\n")
    c+=1
