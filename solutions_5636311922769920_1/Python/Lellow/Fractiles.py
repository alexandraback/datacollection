fichierR = open("D-large.in","r")
fichierW = open("D-large.out","w+")

def calcul(l,k,c):
    ret = 0
    for i in range(0,len(l)):
        ret+=l[i]* k**(len(l)-i-1)
    return ret+1


def fractiles(k,c,s):
    if (k > (s*c)):
        return "IMPOSSIBLE"
    a = list(range(0,k))
    res = []
    while(len(a)!=0):
        tab=[]
        for i in range(c):
            tab.append(a.pop(0) if (len(a)!=0) else k)
        res.append(calcul(tab,k,c))
    return res

a = int(fichierR.readline())
j=0
for i in range(a):
    tab = (fichierR.readline()).split()
    k = int(tab[0])
    c = int(tab[1])
    s = int(tab[2])
    fichierW.write("CASE #")
    fichierW.write(str(j+1))
    j+=1
    fichierW.write(": ")
    tab = fractiles(k,c,s)
    if tab == "IMPOSSIBLE":
        fichierW.write("IMPOSSIBLE")
    else:
        fichierW.write(" ".join(str(tab[l]) for l in range(len(tab))))
    fichierW.write("\n")
