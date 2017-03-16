f = open("A-small-attempt0.in",'r')
output  = open("output.txt",'w')
cases =int(f.readline())
for case in range(1,cases+1):
    S=[int(j) for j in str.split(f.readline())[1]]
    ret = 0
    buf =0
    for i in range(len(S)):
        print([ret,buf])
        if i>buf:
            ret+=i-buf
            buf+=(i-buf)+S[i]
        else:
            buf +=S[i]
    output.write("Case #"+str(case)+": "+str(ret)+"\n")
output.close()
f.close()
