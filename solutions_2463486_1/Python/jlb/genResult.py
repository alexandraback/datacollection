# -*- coding: utf-8 -*-
"""
Created on Sat Apr 13 16:43:43 2013

@author: jlb
"""
from math import *
import os
import bisect

def isSymm(num):
    strNum=str(num)
    i=0;
    j=len(strNum)-1
    while(i<j):
        if(strNum[i]!=strNum[j]):
            return False
        i=i+1
        j=j-1
    return True

def genData():
    data=list()
    upper=int("1"+10*'0')
    i=0
    while i<upper:
        sq=i*i
        if (isSymm(i) and isSymm(sq)):
            print("{0}\t{1}".format(i,sq))
            data.append(sq)
        i=i+1
    return data

def getEvenData(data,i):
    low=int('1'+(i-1)*'0')
    high=int('1'+i*'0')
    while low<high:
        strNum=str(low)
        Num=int(strNum+strNum[::-1])
        sq=Num*Num
        if(isSymm(sq)):
            print(sq)
            data.append(sq)
        low=low+1

def getOddData(data,i):
    low=int('1'+(i-1)*'0')
    high=int('1'+i*'0')
    while low<high:
        strNum=str(low)
        for i in range(0,10):
            Num=int(strNum+str(i)+strNum[::-1])
            sq=Num*Num
            if(isSymm(sq)):
                print sq
                data.append(sq)
        low=low+1

def genSymmData():
    data=list()
    data.append(0)
    data.append(1)
    data.append(4)
    data.append(9)
    for i in range(1,25):
        getEvenData(data,i)
        getOddData(data,i)
    return data

def getNum(data,low,high):
    lowIndex=0
    highIndex=len(data)-1
#    while((lowIndex<len(data))and(low < data[lowIndex])):
#        lowIndex=lowIndex+1
#    while((highIndex>0)and(high > data[highIndex])):
#        highIndex=highIndex-1
    lowIndex=bisect.bisect(data,low)
    highIndex=bisect.bisect(data,high)
    if(lowIndex>0 and low==data[lowIndex-1]):
        lowIndex=lowIndex-1
#    if(high!=data[highIndex]):
#        highIndex=highIndex-1
    print(lowIndex,highIndex)
    return highIndex-lowIndex

def runTest(dataPath,inPath,outPath):
    data=list()
    with open(dataPath,'r') as dataFile:
        for line in dataFile.readlines():
#            print("#"+line)
            data.append(int(line))
    with open(inPath,'r') as inFile:
        with open(outPath,'w') as outFile:
            line=inFile.readline()
            caseNum=int(line)
            for i in range(1,caseNum+1):
                line=inFile.readline()
                low,high=line.split(" ")
                low=int(low)
                high=int(high)
                num=getNum(data,low,high)
#                print("Case #{0}: {1}".format(i,num))
                outFile.write("Case #{0}: {1}\n".format(i,num))

def preData(dataPath):
    data=genData()
    with open(dataPath,'w') as dataFile:
        for item in data:
            dataFile.write("{0}\n".format(item))
    print("Data is OK")

def preSymmData(dataPath):
    data=genSymmData()
    with open(dataPath,'w') as dataFile:
        for item in data:
            dataFile.write("{0}\n".format(item))
    print("Data is OK")

def main():
#    inPath=r"C:\Users\jlb\Documents\Visual Studio 2012\Projects\AlgoContestProject\Debug\data.txt"
#    outPath=r"C:\Users\jlb\Documents\Visual Studio 2012\Projects\AlgoContestProject\Debug\Data\genC.txt"
#    dataPath=r"C:\Users\jlb\Documents\Visual Studio 2012\Projects\AlgoContestProject\Debug\Fair2.txt"
    inPath=r"C:\Users\jlb\Documents\Visual Studio 2012\Projects\AlgoContestProject\Debug\Data\C-large-1.in"
    outPath=r"C:\Users\jlb\Documents\Visual Studio 2012\Projects\AlgoContestProject\Debug\Data\C-large-1.out"
    dataPath=r'data.txt'
#    inPath=r'./Data/C-small-attempt0.in'
#    inPath=r'small-input.txt'
#    outPath=r'./Data/C-small-attempt0-py.out'
    runTest(dataPath,inPath,outPath)
#    preSymmData(dataPath)
    print('OK')
    print"END"




if __name__=="__main__":
    main()