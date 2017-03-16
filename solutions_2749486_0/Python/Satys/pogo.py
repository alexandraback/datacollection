f=open("B-small-attempt0.in")
out=open("out.txt",'w')
def inp():
    for i in f:
        return i
t=int(inp())
for case in range(1,t+1):
    x,y=[int(i) for i in inp().split()]
    current=[0,0]
    d=[]
    step=1
    #print current[0],current[1]
    while current[0]!=x or current[1]!=y:
        #print current[0],current[1],x-current[0],y-current[1]
        if abs(x-current[0])>=abs(y-current[1]):
            #print step,x-current[0]
            if step<=x-current[0]:
                current[0]+=step
                d.append("E")
                step+=1
                #print current[0],current[1],d,step
            else:
                current[0]-=step
                d.append("W")
                step+=1
                #print current[0],current[1],d,step
        else:
            #print step,y-current[1]
            if step<=y-current[1]:
                current[1]+=step
                d.append("N")
                step+=1
                #print current[0],current[1],d,step
            else:
                current[1]-=step
                d.append("S")
                step+=1
                #print current[0],current[1],d,step
    #print ''.join(d)
    out.write("Case #"+str(case)+": "+''.join(d)+"\n")
f.close()
out.close()
    
