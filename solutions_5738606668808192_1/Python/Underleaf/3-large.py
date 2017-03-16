# -*- coding: utf-8 -*-
import fractions
import math


def parseNum(numString,base):
    result = 0
    l = len(numString)
    for i in range(0,l):
       result += int(numString[i]) * (base ** (l-i-1))
    return result

def nString(n,cases):
    binStr = str(bin(n)).replace('0b','')
    binStr = '1'+(cases-len(binStr))*'0' + binStr+'1'
    return binStr
    
def nPartialString(n,cases):
    binStr = str(bin(n)).replace('0b','')
    binStr = binStr+'1'
    return binStr

def generateListRemainder(n,limit):
    newlist = []
    for i in range(2,11):
        innerList = []
        for k in range(2,limit):
            innerList.append((i**(n-1))%k)
        newlist.append(innerList)
    return newlist
    
   
#file = open('Inputs/Input.in', 'r')
with open('Inputs/Input.in', 'r') as infile, open('Outputs/Output.out', 'w') as outfile: 
   
    T = int(infile.readline().split('\n')[0]);
    
    line = infile.readline().split('\n')[0].split(' ');
    N = int(line[0])
    J = int(line[1])
    limit = 40
    
    print 'Case #1:'
    outfile.write('Case #1:\n')  
    
    remList = generateListRemainder(N,limit)
    
    for i in range(0,(2**20)):
        num = nPartialString(i,N-1)
        realnum = nString(i,N-2)
        divisorList = []
        fatoresList = []
        totalPrime = False;
        for j in range(2,11):
            parsedNum = parseNum(num,j);
            prime = True;
            for k in range(2,limit):
                if ((remList[j-2][k-2] + parsedNum % k) % k  == 0):
                    divisorList.append(k);
                    #print float(parseNum(realnum,j))/k % 10
                    prime = False;
                    break;
            if prime == True:
                break;
        if len(divisorList) == 9:
            result = realnum+" "+" ".join(str(x) for x in divisorList)
            print str(J)+":"+result
            outfile.write(result+'\n') 
            J = J-1
            if J == 0:
                break;
                
                
                
                
                
                
                
        
