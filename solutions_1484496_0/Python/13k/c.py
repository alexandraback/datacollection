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
            "4",
            "2",
            "0 1",
            "0 2",
            "3",
            "2 2",
            "0 0",
            "4 4",
            "1",
            "1 1",
            "5",
            "0 5",
            "0 1",
            "1 1",
            "4 7",
            "5 6"
          ]
    rawData = read_input("B-large-practice.in")
    data    = refineData(rawData,int)
    #print(data)
    caseNum = int(data.pop(0)[0])
    
    for caseIndex in range(caseNum):
        print("Case #%d: " % (caseIndex+1),end = "")
