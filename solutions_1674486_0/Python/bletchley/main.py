'''
Created on 2012/5/6

@author: bletchley
'''

if __name__ == '__main__':
    file = open("a.in")
    outfile = open("a.out","w")
    testcase = int(file.readline())
    testNum = 1
    for x in range(1,testcase+1) :
        pathList = []
        classnum = int(file.readline())
        index = 1
        pathTol = 0
        for r in range(0,classnum) :
            line = file.readline().split(" ")
            pathNum = int(line[0])
            pathTol += pathNum
            for i in range(1,pathNum+1):
                path = (index,int(line[i]))
                pathList.append(path)
            index +=1
        #print pathTol
        #print pathList
        map = []
        for i in range(0,classnum+1):
            map.append([])
            for j in range(0,classnum+1):
                map[i].append(False)
        
        for i in range(0,pathTol):
            start = pathList[i][0]
            fin   = pathList[i][1]
            #print start,fin
            map[start][fin]=True 
        #for i in range(1,classnum+1):
            #print map[i]
        flag = False
        for k in range(1,classnum+1) :
            for i in range(1,classnum+1):
                for j in range(1,classnum+1):
                    if map[i][k]==True and map[k][j]==True:
                        if map[i][j] : 
                            flag = True
                        map[i][j]=True
        if flag :
            ans = "Yes"
        else :
            ans = "No"
        
        outfile.write("Case #%d: "%testNum + ans + "\n")
        print "Case #%d: "%testNum + ans + "\n"
        testNum +=1
                    
                         
        