# -*- coding: utf-8 -*-
"""
Created on Tue Apr  5 11:53:03 2016

@author: pellowes
"""
import numpy as np
#import bigfloat
#format 1 digit, then 
#n digits
#then 
#several data lines (x) based on one of the n digits
def readThroughDataGeneric(filename):
    outputs = []
    f = open(filename,'r')
    lct=0
    for line in f.readlines():
        if lct==0:
            t = int(line.strip())          
        else:
            l = line.strip().split(' ')
            n = int(l[0])
            j = int(l[1])
            #we need j, and are working with length n
            for i in range(0,np.power(2,n-2)):#don't need to change first or last
                print(i)                
                binrep = bin(i)[2:]
                while len(binrep) < n-2:
                    binrep='0'+binrep
                cointocheck = '1'+binrep+'1'
                #print(cointocheck)
                coinjamout = checkValidCoinJam(cointocheck,n)
                if coinjamout is not None:              
                    out = []
                    out.append(cointocheck)
                    out.extend(coinjamout)
                    outputs.append(out)
                    print('--->'+str(len(outputs)))
                    if(len(outputs)==j):
                        return outputs
        lct+=1
    f.close()
    return outputs        
        

def solve(series):
    prev_val = True
    changes = 0    
    for i in range(len(series)-1,-1,-1):
        if(prev_val != series[i]):
            changes+=1
            prev_val = series[i]
    return changes

#get number in 01011s of some base, then do long division. return remainder
#divisor assumed to be in base 10
def SimulateLongDivision(toDivide,base,divisor):
    digitstring = str(toDivide)
    currentvalue=0
    for i in range(0,len(digitstring)):
        currentvalue = 2**currentvalue+int(digitstring[i])
        currentvalue = currentvalue%base
    return currentvalue

#assumes it's getting a string of 0s and 1s
def checkValidCoinJam(candidateString,n):
    if candidateString[0] != '1' or candidateString[len(candidateString)-1] != '1':
        return None
    #check each base, keep track of valid divisors
    divisors = []
    for i in range(2,11):
        #num = convertToBase10(int(candidateString),i)
        lvd = lowestValidDivisor(candidateString,i,n)
        if lvd is None:
            return None
        divisors.append(lvd)
    return divisors

def convertToBase10(num,base):
    currentSum = int(0)
    print(base)
    reversestring = str(num)[::-1]
    for i in range(0,len(reversestring)):
    #    print(i)
        if reversestring[i]=='1':
            #manually do the power to prevent overflows in large case
            runningproduct=1
            for j in range(0,i):
                runningproduct*=base
            currentSum+=int(runningproduct)
    #print (currentSum)
    return currentSum    
    
#get whether a valid divisor can be found
def lowestValidDivisor(num,base,n):
    #print(num)
    for i in range(2,int(np.floor(np.sqrt(float(base**(n+1)))))+1):
        if SimulateLongDivision(num,base,i) == 0:
            #print(i)
            return i
    return None

#infile_name = '/Users/pellowes/Downloads/B-small-attempt0.in'
#infile_name = '/Users/pellowes/Downloads/B-large.in'
infile_name = '/Users/pellowes/dummydata'
outputs = readThroughDataGeneric(infile_name)
print(len(outputs))
outfile_name = '/Users/pellowes/Downloads/long.out'
f = open(outfile_name,'w')
f.write("Case #1: ")
for i in range(0,len(outputs)):
    f.write('\n')
    f.write(outputs[i][0])
    for j in range(1,10):
        f.write(' ')
        f.write(str(outputs[i][j]))
f.close()