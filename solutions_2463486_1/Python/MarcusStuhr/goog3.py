import sys
from math import sqrt

fin = open("inp.in","r")
fout = open("out.txt","w")
T = int(fin.readline())

def getPals(limit):
    res = set()
    i=0
    while i<=9 and i<=limit:
        res.add(i)
        i+=1
    go = True
    i=1
    while go:
        binI = bin(i)[2:]
        rev = str(binI)[::-1]
        go = False
        for d in ["","0","1","2"]:
            n = int(str(binI) + d + rev)
            if n<=limit:
                go = True
                res.add(n)
        i+=1
    go=True
    i=0
    while go:
        go = False
        n = "2" + i*"0" + "2"
        if int(n)<=limit:
            go = True
            res.add(int(n))
        if len(n) % 2 == 1:
            n = "2" + ((i-1)/2)*"0" + "1" + ((i-1)/2)*"0" + "2"
            if int(n)<=limit:
                go = True
                res.add(int(n))
            n = "2" + ((i-1)/2)*"0" + "2" + ((i-1)/2)*"0" + "2"
            if int(n)<=limit:
                go = True
                res.add(int(n))
        i+=1
    return sorted(res)

pals = getPals(sqrt(10**14))

for trial in range(1,T+1):
    A,B = map(int,fin.readline().replace('\n','').split(' '))

    ans=0
    for pal in pals:
        n=pal*pal
        if n>=A and n<=B:
            if str(n)==str(n)[::-1]:
                #print pal
                ans+=1
        if n>B: break
    fout.write( "Case #" + str(trial) + ": " + str(ans) + "\n")

fin.close()
fout.close()