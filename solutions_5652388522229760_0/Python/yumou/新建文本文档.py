def calc(n):
    if n==0:
        return "INSOMNIA"
    dic={}
    i=1
    while True:
        w=i*n
        s=str(w)
        for k in s:
            if k not in dic:
                dic[k]=1
        if len(dic)==10:
            return(w)
        i+=1
    

file=open("A-small-attempt0.in")
outfile=open("output.txt","w")
t=file.readline()
t=int(t)
for i in range(t):
    n=file.readline()
    n=int(n[:-1])
    
    outfile.write("Case #"+str(i+1)+": "+str(calc(n))+"\n")

outfile.close()

