fichierR = open("D-small.in","r")
fichierW = open("D-small.out","w+")


def fractiles(k,c,s):
    return" ".join(str(j+1)for j in range(k))


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
    fichierW.write(fractiles(k,c,s))
    fichierW.write("\n")


print(fractiles(3,2,3))


