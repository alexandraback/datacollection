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
    trainSet= [" ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjvzq",
               " ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveupqz"]
    dic = {}
    for i in range(len(trainSet[0])):
        dic[trainSet[0][i]]  = trainSet[1][i]
    
    rawData = ["3",
               "ejp mysljylc kd kxveddknmc re jsicpdrysi",
               "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
               "de kr kd eoya kw aej tysr re ujdr lkgc jv"
               ]
    rawData = read_input("c:\\A-small-attempt1.in")
    caseNum = int(rawData.pop(0))
    """
    lis=[]
    for i in dic:
        lis.append([dic[i],i])
    lis.sort()
    print("len ", len(dic))
    for i in lis:
        print(i)
    
    """
    for i in range(caseNum):
        print("Case #%d: " % (i+1),end = "")
        text    = rawData.pop(0)
        for j in text:
            if j == "\n": continue
            print(dic[j],end="")
        print()
    
    