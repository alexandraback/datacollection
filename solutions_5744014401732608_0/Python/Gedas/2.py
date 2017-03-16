def outp(s,b):
    out.write("0"*(b-len(s))+s+"\n")


def sleep(n):
    b,m=map(int,n.split())
    if m>2**(b-2): out.write("IMPOSSIBLE\n")
    elif m==2**(b-2):
        out.write("POSSIBLE\n")
        for x in range(b):
            outp("1"*(b-x-1),b)
    else:
        out.write("POSSIBLE\n")
        dcd = [] #decomposed into powers of 2
        i = 1
        while i <= m:
            if i & m: dcd.append(1)
            else: dcd.append(0)
            i <<= 1
        dcd.reverse()
        dcds="".join(map(str,dcd))
        out.write("0"+dcds+"0"*(b-len(dcds)-1)+"\n")
        l=len(dcd)
        for x in range(b-1):
            outp("1"*max(0,(l-x)),b)
        
        
            
    
    

inp=open("B-small-attempt2.in")
x=int(inp.readline()[:-1])
out=open("2sa.txt","w")
case=1
for n in range(x):
    #inp.readline()
    out.write("Case #"+str(case)+": ")
    sleep(inp.readline()[:-1])
    case+=1
inp.close()
out.close()
    
