'''
Created on 2012/5/5

@author: bletchley
'''

if __name__ == '__main__':
    map = "yhesocvxduiglbkrhtnwjpfmaq"
    
    file = open("a.in")
    outfile = open("a.out","w")
    num = int(file.readline())
    for x in range(1,num+1) :
        line = file.readline().split(" ")
        numJ = int(line[0])
        scoreList = []
        minList = []
        doneList =[]
        sum = 0
        for j in range(1,numJ+1) :
            score = float(line[j])
            scoreList.append(score)
            minList.append(-1)
            doneList.append(False)
            sum+=score
        #print scoreList
        
        #print thr
        str1 = "Case #%d:" % x 
        overflag = True
        while overflag :
            left = numJ
            maxsc = 2*sum
            #print maxsc
            for j in range(0,numJ):
                if doneList[j] :
                    left -=1
                    maxsc-=scoreList[j]
            overflag = False
            thr = maxsc/left
            #print "thr",thr
            #print scoreList
            for j in range(0,numJ):
                if doneList[j] == False :
                    minList[j]= float((thr-scoreList[j])*100/sum)
                    if minList[j] < 0 :
                        minList[j] =0
                        doneList[j] = True
                        overflag = True
        for j in range(0,numJ):
            str1 += " "+str(round(minList[j],5))
        str1+="\n"
        print str1
        outfile.write(str1)
    pass