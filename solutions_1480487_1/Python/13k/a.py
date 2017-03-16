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
            "2 20 10",
            "2 10 0",
            "4 25 25 25 25",
            "3 24 30 21"
          ]
    rawData = read_input("A-large.in")
    data    = refineData(rawData,int)
    #print(data)
    caseNum = int(data.pop(0)[0])
    
    for caseIndex in range(caseNum):
        print("Case #%d: " % (caseIndex+1),end = "")
        tmpLt   = data.pop(0)
        nNum    = tmpLt[0]
        scores  = tmpLt[1:]
        sum     = 0
        for i in scores:
            sum += i
        totalS  = sum*2
        result  = []
        for i in scores:
            result.append(((totalS/len(scores)-i)/sum*100))
        nValue  = 0
        count   = 0
        for i in range(len(result)):
            if result[i]<0:
                nValue+=result[i]
                count+=1
        #if caseIndex==4:print(result)
        if count>0:
            for i in range(len(result)):
                if result[i]<0:
                    result[i]=0
                else:
                    result[i]+=nValue/(nNum-count)
        for i in result:
            print("%.6f " % i , end="")
                
        print()
        
