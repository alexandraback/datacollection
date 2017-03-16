'''
Created on 2013/4/13

@author: 13k
'''
import math
def read_input(fileName):
    f = open(fileName,"r")
    lines   = f.readlines()
    for i in range(len(lines)):
        lines[i]= lines[i].strip()
    return lines
def refineData(rawData, keyFun):
    dataList    = []
    for i in range(0,len(rawData)):
        dataList.append(list(map(keyFun,rawData[i].split())))
    return dataList
def outWrite(s):
    outF.write(str(s)+'\n')
if __name__ == '__main__':
    rawData = [ 
        "3",
        "1 4",
        "10 120",
        "100 1000"
      ]
    rawData = read_input("C-small-attempt0.in")
    #rawData = read_input("B-large.in")
    allData    = refineData(rawData,int)
    outF    = open('out.in','w')
    
    caseNum = allData.pop(0)[0]
    
    countLt = {0:0}
    sum     = 0 
    for i in range(1,10**3):
        
        if str(i*i) == str(i*i)[::-1] and str(i) == str(i)[::-1]:
            sum+=1
        countLt[i] = sum 
        
        
    #print(countLt)
    for caseIndex in range(caseNum):
        print("Case #%d: " % (caseIndex+1),end = "")
        outF.write("Case #%d: " % (caseIndex+1))
        (A,B)   = allData.pop(0)
        
        tmpA = math.ceil(A**0.5)
        tmpB = math.floor(B**0.5)
        result = countLt[tmpB]-countLt[tmpA]
        if str(tmpA*tmpA) == str(tmpA*tmpA)[::-1] and str(tmpA) == str(tmpA)[::-1]:
            result+=1
        print(result)
        outWrite(result)
        
    outF.close()
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    