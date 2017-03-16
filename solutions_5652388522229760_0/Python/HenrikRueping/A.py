filename  = "A-small-attempt0.in"#"Asample.in" 
f = open(filename,'r')
out = open("output.out",'w')
T =int(f.readline())
#print(tobase(18,"012"))
for i in range(T):
    N = int(f.readline())
    #print(" N "+str(N))
    if N==0:
        out.write("Case #"+str(i+1)+": INSOMNIA\n")
    else:
        found =[0,0,0,0,0,0,0,0,0,0]
        cur =0
        while sum(found)<10:
            cur+=N
            for k in range(10):
                #print(str(cur)+" "+str(found[k]))
                if str(k) in str(cur):
                    found[k]=1
        print("Case #"+str(i+1)+": "+str(cur)+"\n")
        out.write("Case #"+str(i+1)+": "+str(cur)+"\n")
f.close()
out.close()
