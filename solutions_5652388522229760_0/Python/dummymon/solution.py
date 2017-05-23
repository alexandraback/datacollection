def outp(a,b):
    file=open("output.txt","a")
    s="Case #"+str(a+1)+": "+str(b)+"\n"
    file.write(s)
    file.close
    print(s)

q=open ("output.txt","w")
q.close()
inp = open("A-small-attempt0.in","r")
a= []
for line in inp:
    if "\n" in line:
        a.append(line[0:-1])
    else:
        a.append(line)
inp.close()
inpNum =int(a.pop(0))
for ii in range(inpNum):
    n = int(a[ii])
    if n== 0:
        outp(ii,"INSOMNIA")
        continue
    digits = []
    current = 0
    while True:
        current += n
        curlist = list(str(current))
        for i in curlist:
            if not i in digits:
                digits.append(i)
        if len(digits) == 10:
            outp(ii , current)
            break
