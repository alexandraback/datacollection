def outp(a,b):
    file=open("output.txt","a")
    s="Case #"+str(a+1)+": "+str(b)+"\n"
    file.write(s)
    file.close
    print(s)


def flipping(flipstack,flips):
    lasthappy = -1
    for i , pancake in enumerate(flipstack):
        if pancake =="+":
            lasthappy = i
            break
    if lasthappy == -1:
        return(flips)
    flipthis = flipstack[lasthappy:]
    flipstack = []
    for i in flipthis:
        if i == "-":
            flipstack.append("+")
        else:
            flipstack.append("-")
    flips += 1
    flips = flipping(flipstack,flips)
    return (flips)

q=open ("output.txt","w")
q.close()
inp = open("B-large.in","r")
a= []
for line in inp:
    if "\n" in line:
        a.append(line[0:-1])
    else:
        a.append(line)
inp.close()
inpNum =int(a.pop(0))
for ii in range(inpNum):
    stack = list(a[ii])
    reStack = stack[::-1]
    lastSad = "none"
    for i , pancake in enumerate(reStack):
        if pancake =="-":
            lastSad = i
            break
    if lastSad == "none":
        outp( ii, "0")
        continue
    flipthis = reStack[lastSad:]
    fliped = 1
    fliped = flipping(flipthis,fliped)
    outp (ii, fliped)
            
