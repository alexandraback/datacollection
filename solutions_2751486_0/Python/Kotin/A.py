#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      qmarchal
#
# Created:     11/04/2013
# Copyright:   (c) qmarchal 2013
# Licence:     <your licence>
#-------------------------------------------------------------------------------
import os,math,sys
from math import factorial
f = open("A-small-attempt1.in")
T = int(f.readline())

def WriteOutput(output):
    w = open("ouput.txt","w")
    w.write(output)
    w.close()
def Print(string):
    sys.stdout.write(str(string)+"\n")
def NextInt():
    return int(f.readline())
def NextList():
    return f.readline().split()
def NextIntList():
    strings = f.readline().split()
    ints = []
    for string in strings:
        ints.append(int(string))
    return ints
def NextStr():
    return f.readline()
def Main():
    output = ""
    ######### TO DO ##########
    for t in range(1,T+1,1):
        output +="Case #%d: "%t + Case() + "\n"
    WriteOutput(output)
def Parmi(k, n):
    return factorial(n) // (factorial(k) * factorial(n - k))
def HasNCon(w,n):
    s= False
    c=0
    for l in w:
        if isCon(l):
            c+=1
        else:
            c=0
        if c>=n:
            return True
    return False
def isCon(l):
    if l=='a' or l=='e' or l=='i' or l=='o' or l=='u':
        return False
    return True
def Case():
    output = ""
    name,n = NextList()
    n = int(n)
    ######### TO DO ##########
##    v = ['a','e','i','y','o','u']
##    nm = name.replace("a",".")
##    nm = nm.replace("e",".")
##    nm = nm.replace("i",".")
##    nm = nm.replace("o",".")
##    nm = nm.replace("u",".")
##    nm = nm.replace("y",".")
##    syls = nm.split('.')
##    subs = []
##    count = 0
##    for syl in syls:
##        if len(syl)>=n:
##            count+=Parmi(n,len(syl))
##    p=0
    count = 0
    for i in range(0,len(name),1):
        for j in range(i,len(name),1):
            if HasNCon(name[i:j+1],n):
                count+=1
    output += str(count)
    return output
if __name__ == '__main__':
    Main()
