'''
Created on 2013/4/13

@author: 13k
'''
def read_input(fileName):
    f = open(fileName,"r")
    data    = []
    lines   = f.readlines()
    for i in range(len(lines)):
        lines[i]= lines[i].strip()
    return lines
def refineData(rawData, keyFun):
    dataList    = []
    for i in range(0,len(rawData)):
        dataList.append(list(map(keyFun,rawData[i].split())))
    return dataList
def outWrite(f,s):
    f.write(s+'\n')
if __name__ == '__main__':
    rawData = [ 
        "6",
        "XXXT",
        "....",
        "OO..",
        "....",
        
        "XOXT",
        "XXOO",
        "OXOX",
        "XXOO",
        
        "XOX.",
        "OX..",
        "....",
        "....",
        
        "OOXX",
        "OXXX",
        "OX.T",
        "O..O",
        
        "XXXO",
        "..O.",
        ".O..",
        "T...",
        
        "OXXX",
        "XO..",
        "..O.",
        "...O"
      ]
    rawData = read_input("A-large.in")
    outF    = open('out.in','w')
    
    caseNum = int(rawData.pop(0))
    for case in range(caseNum):
        data = []
        
        for i in range(4):
            data.append(rawData.pop(0))
        #print(data)
        xCheck = False
        oCheck = False 
        for i in range(4):
            tmpR = []
            tmpL = []
            for j in range(4):
                tmpR.append(data[i][j])
                tmpL.append(data[j][i])
                
            #print(tmpR)
            #print(tmpL)
            if '.' not in tmpR and 'O' not in tmpR:
                xCheck = True
            if '.' not in tmpR and 'X' not in tmpR:
                oCheck = True
            if '.' not in tmpL and 'O' not in tmpL:
                xCheck = True
            if '.' not in tmpL and 'X' not in tmpL:
                oCheck = True
        tmpRL = data[0][0]+data[1][1]+data[2][2]+data[3][3]
        tmpLR = data[3][0]+data[2][1]+data[1][2]+data[0][3]
        #print(tmpRL)
        #print(tmpLR)
        if '.' not in tmpRL and 'O' not in tmpRL:
            xCheck = True
        if '.' not in tmpRL and 'X' not in tmpRL:
            oCheck = True
        if '.' not in tmpLR and 'O' not in tmpLR:
            xCheck = True
        if '.' not in tmpLR and 'X' not in tmpLR:
            oCheck = True
        print("Case #%d: " % (case+1),end = "")
        outF.write("Case #%d: " % (case+1))
        
        if xCheck:
            print('X won')
            outWrite(outF,'X won')
        elif oCheck:
            print('O won')
            outWrite(outF,'O won')
        elif '.' in data[0]+data[1]+data[2]+data[3]:
            print('Game has not completed')
            outWrite(outF,'Game has not completed')
        else:
            print('Draw')
            outWrite(outF,'Draw')
        if rawData != []:
            rawData.pop(0)
        
            
                
    pass







