
def deco(a,n):
    while(n!=0):
        k=n%10
        n=n//10
        a[k] = 0

def count(k):
    n=k
    a = [1,1,1,1,1,1,1,1,1,1]
    nprec=0
    while(nprec != n):
        nprec=n
        deco(a,n)
        if (1 in a):
            n=n+k
        else:
            return n
    return "INSOMNIA"



fichierR = open("test.txt","r")
fichierW = open("solution.txt","w+")
fichierR.readline()
i=1
for ligne in fichierR:
    fichierW.write("CASE #")
    fichierW.write(str(i))
    fichierW.write(": ")
    fichierW.write(str(count(int(ligne))))
    fichierW.write("\n")
    i=i+1

fichierW.close()
fichierR.close()