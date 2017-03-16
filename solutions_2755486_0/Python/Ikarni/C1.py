# Python version 2.7
import sys
import math
     
def oneCase(inputFile):
    [N] = map(int, inputFile.readline().split(' '))
    attacks = []
    for i in range(N):
        [d,n,w,e,s,dd,dp,ds] = map(int, inputFile.readline().split(' '))
        for j in range(n):
            attacks.append((d+j*dd,w+j*dp, e+j*dp,s+j*ds))
    attacks = sorted(attacks)
    wall = [0 for i in range (-10000,10000)]
    x = 0
    oldd=0
    nwall = []
    for a in attacks:
        succ=0
        d,w,e,s = a
        if d>oldd: 
            for j,w in nwall: wall[j]=w
            nwall = []
        for i in range(w,e+1):
            if wall[i] < s: 
                succ=1
                nwall.append((i,s))
        x += succ
        oldd = d
                
    return str(x)

def main(f = None):
    inputFile = sys.stdin if f==None else open(f)
    cases = int(inputFile.readline())
    for i in range(cases):
        print "Case #" + str(i+1) + ": " + oneCase(inputFile) 

#main("B-test.in")
main()