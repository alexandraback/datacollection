def outp(a,b, c = True):
    # a is case no and b is a list
    file=open("output.txt","a")
    s="Case #" + str(a) + ": "
    if c:
        for i in b:
            s= s + str(i) +" "
    else:
        s = s + b + " "
    s = s[:-1] + "\n"
    file.write(s)
    file.close

q=open ("output.txt","w")
q.close()
inp = open("D-small-attempt6.in","r")
a= []
for line in inp:
    if "\n" in line:
        a.append(line[0:-1])
    else:
        a.append(line)
inp.close()
inpNum =int(a.pop(0))
for ii in range(inpNum):
    info = a[ii]
    print(info)
    info = info.split(" ")
    K = int(info[0])
    C = int(info[1])
    S = int(info[2])
    if K // C > S:
        outp(ii+1, "IMPOSSIBLE" , False)
        continue
    checktiles = []
    timestocheck = K
    for i in range(timestocheck):
        tileNo= i*(K**(C-1)) + 1
        checktiles.append(tileNo)   
    outp(ii+1,  checktiles)     
    
