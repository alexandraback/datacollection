'''
Created on 2012/4/14

@author: bletchley
'''

file = open("b.in")
outfile = open("b.out","w")
num = int(file.readline())
    
for index in range(1,num+1) :
    line = file.readline().split(" ")
    numOfDancer = int(line[0])
    numOfSurp = int(line[1])
    threhold = int(line[2])
    scoreList = []
    passCount = 0
    for i in range(0,numOfDancer) :
        scoreList.append(int(line[i+3]))
        score =  int(line[i+3])
        remind = score%3
        ave = int(score/3)
        print "ave",ave,numOfSurp
        if ave>=threhold :
            passCount+=1
        elif ave==threhold -1:
            if remind==0 and numOfSurp>0 and ave-1>=0:
                passCount+=1
                numOfSurp-=1   
            elif remind>0:
                passCount+=1 
        elif ave == threhold-2 and remind==2 and numOfSurp>0:
            passCount+=1
            numOfSurp-=1
    print numOfSurp, threhold       
    print scoreList
    print passCount  
    outfile.write("Case #%d: %d\n" % (index ,passCount))    