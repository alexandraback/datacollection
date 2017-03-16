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
import os,math,sys,copy
f = open("B-small-attempt1.in")
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
    string = str(f.readline())
    return string.replace('\n',"")
def Main():
    output = ""
##    Print(Compare("caraban","pajabas","abcdefghijklmnopqrstuvwxyz"))
    ######### TO DO ##########
    for t in range(1,T+1,1):
        output +="Case #%d: "%t + Case() + "\n"
    WriteOutput(output)
def Abs(x):
    if x>=0:
        return x
    else:
        return -x
def Case():
    output = ""
    X,Y = NextIntList()
    ######### TO DO ##########
    p=""
    if abs(X)<abs(Y):
        if X==0:
            pass
        elif X>0:
            p+="E"
            for i in range(0,X-1,1):
                p+="WE"
        else:
            p+="W"
            for i in range(0,X+1,-1):
                p+="EW"
        if Y==0:
            pass
        elif Y>0:
            for i in range(0,Y,1):
                p+="SN"
        else:
            for i in range(0,Y,-1):
                p+="NS"
    else:
        if Y==0:
            pass
        elif Y>0:
            p+="N"
            for i in range(0,Y-1,1):
                p+="SN"
        else:
            p+="S"
            for i in range(0,Y+1,-1):
                p+="NS"
        if X==0:
            pass
        elif X>0:
            for i in range(0,X,1):
                p+="WE"
        else:
            for i in range(0,X,-1):
                p+="EW"
    output += str(p)
    return output
if __name__ == '__main__':
    Main()
