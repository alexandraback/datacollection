def inv(a,b):
    if (a==1):
        c=0
    else:
        c=1
    if (b==1):
        d=0
    else:
        d=1
    return (c,d)

def inverse(s,l):
    a=s[0]
    i=0
    while (l!=i and s[i]==a):
        i=i+1
    if (l!=i or a!=1):
        for j in range(i//2):
            (s[i-j-1],s[j])=inv(s[i-j-1],s[j])
        if(i%2==1):
            s[i//2]=1-s[i//2]
        return (True,s)
    return ((a!=1),s)


def inverseAll(s):
    l = len(s)
    j = -1
    bool = True
    while(bool):
        (bool,s)=inverse(s,l)
        j=j+1
    return j

def convert(s):
    l = len(s)
    a = []
    for i in range(l):
        if (s[i]=="+"):
            a.append(1)
        elif(s[i]=="-"):
            a.append(0)
        else:
            return a
    return a



fichierR = open("A-small.in","r")
fichierW = open("A-small.out","w+")
fichierR.readline()
i=1
for ligne in fichierR:
    fichierW.write("CASE #")
    fichierW.write(str(i))
    fichierW.write(": ")
    print(convert(ligne))
    fichierW.write(str(inverseAll(convert(ligne))))
    fichierW.write("\n")
    i=i+1

fichierW.close()
fichierR.close()