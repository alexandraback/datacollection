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
    print(s)

# Pls email me for rationale behind code if required for clarification as i believe there can be over 100000 sets of answers for some cases.

q=open ("output.txt","w")
q.close()
inp = open("D-large.in","r")
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
    for i in range(K//C):
        tileNo= i*(K**(C-1))*C + 1
        for q in range(C-1):
            aq = q+1+(i*C)
            tileNo += aq * (K**(C-q-2))
        checktiles.append(tileNo)   
      
    if K%C != 0 :
        tileNo= (K - (K%C))*(K**(C-1)) + 1
        for q in range(C-1):
            aq = q+1+((K - (K%C))*C)
            if aq >=  K:
                aq = K-1
            tileNo += aq * (K**(C-q-2))
        checktiles.append(tileNo)
    outp(ii + 1 ,checktiles)
