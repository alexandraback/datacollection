'''
Created on 2012/5/5

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

def refineData(rawData, keyFun):
    dataList    = []
    for i in range(0,len(rawData)):
        dataList.append(list(map(keyFun,rawData[i].split())))
    return dataList
def weightedSort(data, weights):
    def my_key(item):
        tmp = [item[i] for i in weights]
        return tmp
    data.sort(key = my_key,reverse = True)
    return data
    data.sort(key = my_key,reverse = True)
    return data
if __name__ == '__main__':
    rawData = [ 
            "3",
            "3",
            "1 2",
            "1 3",
            "0",
            "5",
            "2 2 3",
            "1 4",
            "1 5",
            "1 5",
            "0",
            "3",
            "2 2 3",
            "1 3",
            "0"
          ]
    rawData = read_input("A-small-attempt3.in")
    data    = refineData(rawData,int)
    #print(data)
    caseNum = int(data.pop(0)[0])
    
    for caseIndex in range(caseNum):
        print("Case #%d: " % (caseIndex+1),end = "")
        classesN= data.pop(0)[0]
        pathes  = []
        for i in range(classesN):
            pathes.append(data.pop(0)[1:])
        #print(pathes)
        inhTree = {}
        for i in range(1,classesN+1):
            inhTree[i]  = []
        
        for i in range(len(pathes)):
            for j in range(len(pathes[i])):
                inhTree[pathes[i][j]].append(i+1)
        #print(inhTree)
        trigger = False
        for i in inhTree:
            checkLt     = []
            checkedLt   = []
            checkLt.extend(inhTree[i])
            checkedLt.extend(checkLt)
            while(len(checkLt)!=0):
                checkNode   = checkLt.pop()
                tmp         = inhTree[checkNode][:]
                
                for i in tmp:
                    if i in checkedLt:
                        trigger = True
                checkLt.extend(tmp)
                checkedLt.extend(tmp)
                if trigger:
                    break
            if trigger:
                break
        
        if trigger:
            print("Yes")
        else:
            print("No")

















