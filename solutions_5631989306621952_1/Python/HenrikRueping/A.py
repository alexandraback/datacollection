filename  = "A-large.in"
f = open(filename,'r')
out = open("output.out",'w')
T =int(f.readline())
for C in range(T):
    S=f.readline()
    toFront=S[0]+""
    S=S[1:]
    i=0
    while (i<len(S)):
        #print(S+" "+toFront+" "+str(i))
        if S[i]>=toFront[0]:
            toFront=S[i]+toFront
            S =S[:i]+S[i+1:]
        else:
            i+=1
    S=toFront+S
    out.write("Case #"+str(C+1)+": "+S)
    print("Case "+str(C+1)+": "+S)
f.close()
out.close()
