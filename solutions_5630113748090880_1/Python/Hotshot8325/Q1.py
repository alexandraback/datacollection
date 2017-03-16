#CodeJam Q1 problem
import csv

#import data from test file in the form [[[],[]],[[],[]].... with [[],[]] being one test case
with open('B-large.in') as csvfile:
    testCase = csv.reader(csvfile, delimiter = ' ', quotechar='|')
    rowNum = 0
    inputText = []
    #swapCount = []
    
    for row in testCase:
        #row = [str(i) for i in row]
        if rowNum == 0:
            numTestCases = int(row[0])
        else:
            inputText.append(row)
        rowNum = rowNum + 1

    rowRef = 0
    rowNumber = 0  
    for i in range(0,numTestCases):
        rowNumber = int(inputText[rowRef][0])
        rowRef = rowRef + 1
        checkNum = [0]*3500
        missingValue = []
        
        for j in range(0,2*rowNumber-1):
            for k in range(0,rowNumber):
                checkNum[int(inputText[rowRef][k])] +=1
            rowRef = rowRef + 1
            
        for x in range(0,2500):
            if checkNum[x]%2 != 0:
                missingValue.append(str(x))
        
        print "Case #"+str(i+1)+": " + " ".join(missingValue)