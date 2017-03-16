'''
Created on 2012/4/14

@author: 13k
'''
def read_input(fileName):
    f = open(fileName,"r")
    data    = []
    while True:
        line    = f.readline()
        
        if len(line) == 0:
            break
        data.append(line)
    return data
def refineData(rawData):
    dataList    = []
    for i in range(0,len(rawData)):
        dataList.append(rawData[i].split())
    return dataList
def refineData_int(rawData):
    dataList    = []
    for i in range(0,len(rawData)):
        #dataList.append(rawData[i].split())
        dataList.append(list(map(int,rawData[i].split())))
    return dataList

if __name__ == '__main__':
    rawData = ["4",
               "3 1 5 15 13 11",
               "3 0 8 23 22 21",
               "2 1 1 8 0",
               "6 2 8 29 20 8 18 18 21"]
    rawData = read_input("c:\\B-small-attempt0.in")
    data    = refineData_int(rawData)
    caseNum = data.pop(0)[0]
    for caseIndex in range(caseNum):
        print("Case #%d: " % (caseIndex+1),end = "")
        tmp = data.pop(0)
        num = tmp.pop(0)
        sur = tmp.pop(0)
        lmts= tmp.pop(0)
        
        scores  = tmp
        sum = 0
        for i in scores:
            if i == 0 and lmts!=0:
                continue
            
            if i > (lmts-1)*3:
                sum+=1
            elif i > (lmts-1)*3-2 and sur>0:
                sum+=1
                sur-=1
        print (sum)
        
        
    
    
    
    