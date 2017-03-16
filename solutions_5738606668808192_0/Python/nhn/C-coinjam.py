import sys
from time import time as ti
import numpy as np

def step(li,n):
# a string of 1s and 0s of length (N-2) in this problem
    li = list(li)
    if '0' not in li:
        return(-1)
    elif li[len(li)-1] == '1':
        return step("".join(li[0:(len(li)-1)]),n)
    elif li[len(li)-1] == '0':
        li[len(li)-1] = '1'
        for i in range(n-len(li)):
            li.append('0')
        return "".join(li)

def checkprime(num,verbose=True):
    div = 2
    while div <= (1e4):
        if (num%div==0):
            if verbose: print(str(num)+" is not prime!")
            return(div)
        #if verbose: print div
        div+=1
    if verbose: print(str(num)+" is prime!")
    return(-1)

def checkbase(li,verbose=True):
    # input string of 1s and 0s 
    li = list(li)
    N = len(li)
    divs = []
    for b in range(2,11):
        value = 0 
        for i in range(N):
            value += int(li[i])*(b**(N-1-i))
        cp = checkprime(value)
        if cp == -1:
            if verbose: print("".join(li)+"---eliminate")
            return(-1)
        else:
            divs.append(cp)
    if verbose: print("".join(li)+"---add")
    return divs

def coin(ini,out):
    f = open(ini,'r')
    o = open(out,'w')
    T = int(f.readline())

    for t in range(T):
        o.write("Case #"+str(t+1)+":\n")
        N,J = f.readline().split(' ')
        N = int(N)
        J = int(J)
        jam = ""
        for n in range(N-2):
            jam+='0'
        j = 0
        while True:
            if j == J:
                print("Done!")
                return(0)
            if jam == -1:
                print("Unsolved!")
                return(0)
            cjam = '1'+jam+'1'
            cb = checkbase(cjam)
            if cb == -1:
                jam = step(jam,N-2)
            else:
                o.write(cjam+" "+" ".join(map(str,cb))+"\n")
                j += 1
                jam = step(jam,N-2)
            print("j ="+str(j))

def main(argv):
    ini = "C-small-attempt2.in"
    out = "C-small-attempt2.txt"
    start = ti()
    coin(ini,out)
    end = ti()
    print("Time(sec): "+str(end-start))

if (__name__ == "__main__"):
    main(sys.argv[1:])

