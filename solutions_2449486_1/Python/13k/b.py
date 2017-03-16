'''
Created on 2013/4/13

@author: 13k
'''
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
    outF.write(s+'\n')
if __name__ == '__main__':
    rawData = [ 
        "3",
        "3 3",
        "2 1 2",
        "1 1 1",
        "2 1 2",
        "5 5",
        "2 2 2 2 2",
        "2 1 1 1 2",
        "2 1 2 1 4",
        "2 1 1 1 5",
        "2 2 2 2 2",
        "1 3",
        "1 2 1"
      ]
    #rawData = read_input("B-small-attempt0.in")
    rawData = read_input("B-large.in")
    allData    = refineData(rawData,int)
    outF    = open('out.in','w')
    
    caseNum = allData.pop(0)[0]
    #print(data)
    for caseIndex in range(caseNum):
        print("Case #%d: " % (caseIndex+1),end = "")
        outF.write("Case #%d: " % (caseIndex+1))
        (n,m) = allData.pop(0)
        print(n,m)
        data = []
        for i in range(n):
            data.append(allData.pop(0))
        print(data)
        
        lR  = []
        lC  = []
        for i in range(n):
            tmp = data[i]
            lR.append(max(tmp))
        
        for i in range(m):
            tmp = []
            for j in range(n):
                tmp.append(data[j][i])
            lC.append(max(tmp))
        print(lR,lC)
        
        endTrigger = False
        for i in range(n):
            for j in range(m):
                if data[i][j] < lR[i] and data[i][j] < lC[j]:
                    print("NO") 
                    outWrite('NO')
                    endTrigger =True
                if endTrigger:
                    break
            if endTrigger:
                break
        if not endTrigger:
            print("YES")
            outWrite('YES')
        
    outF.close()
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    