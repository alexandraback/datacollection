#CodeJam pancake problem
import csv
import string

#import data from test file in the form [[[],[]],[[],[]].... with [[],[]] being one test case
with open('a-small-attempt0.in') as csvfile:
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

    for i in range(0,numTestCases):
        letterInput = inputText[i][0]
        lastWord = letterInput[0]
        for j in range(1,len(letterInput)):                    
            if string.uppercase.index(letterInput[j])>=string.uppercase.index(lastWord[0]):
                lastWord = letterInput[j]+lastWord
            else:
                lastWord = lastWord +letterInput[j]
        print "Case #"+str(i+1)+": "+lastWord
