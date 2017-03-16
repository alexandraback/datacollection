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
    rawData = ["10",
        "	1057393 1928164	"	,
"	28 93	"	,
"	1000000 2000000	"	,
"	1032073 1940559	"	,
"	1089798 1970754	"	,
"	100000 999999	"	,
"	1434814 1780702	"	,
"	1072799 1964898	"	,
"	1059864 1967119	"	
]
    rawData = read_input("c:\\C-large.in")
    data    = refineData_int(rawData)
    caseNum = data.pop(0)[0]
    
    for caseIndex in range(caseNum):
        print("Case #%d: " % (caseIndex+1),end = "")
        tmp = data.pop(0)
        minNum  = tmp[0]
        maxNum  = tmp[1]
        dic = {}
        for i in range(minNum,maxNum+1):
            strI    = str(i)
            for j in range(len(strI)):
                check   = int(strI[j:]+strI[:j])
                if minNum<=check and check<=maxNum and check!=i:
                    tmpMax  = max(i,check)
                    tmpMin  = min(i,check)
                    dic[str(tmpMin)+str(tmpMax)] = 1
        print(len(dic))
    
    
    
    