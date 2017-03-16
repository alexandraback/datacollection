def bff(config):
    counter = 1
    targetLength = len(config)
    toBff = {}
    fromBff = {}
    maxLength = -1
    for i in config:
        toBff[counter] = i
        if i in fromBff:
            fromBff[i].append(counter)
        else:
            fromBff[i] = [counter]
        counter = counter + 1
    for i in config:
        length = getBffWithI(i, toBff, fromBff)
        if length > maxLength:
            #print "Length is " + str(length)
            maxLength = length
            if maxLength == targetLength:
                return maxLength
    return maxLength

def getBffWithI(i, toBff, fromBff):
    #print toBff
    #print fromBff
    result = []
    resultDict = {}
    while(True):
        
        result.append(i)
        resultDict[i] = True
        #print result
        #print result
        if toBff[i] not in resultDict:
            i = toBff[i]
            #print "boo"
            continue
        else:
            found = False
            if i in fromBff and (len(result) == 1 or (len(result) > 1 and toBff[result[-1]] == result[-2])):
                for j in fromBff[i]:
                    if j not in resultDict:
                        i = j
                        found = True
                        break

                if found == True:
                    continue

            if result[0] in fromBff and (len(result) == 1 or (len(result) > 1 and toBff[result[-1]] == result[-2])):
                for j in fromBff[result[0]]:
                    if j not in resultDict:
                        #print "boo" + str(j)
                        #print resultDict
                        i = j
                        found = True
                        break
                if found == True:
                    continue
            
            break
            
    return len(result)

##print bff([2,3, 4, 1])
##print bff([3,3, 4, 1])
##print bff([3,3, 4, 3])
##print bff([7,8,10,10,9,2,9,6,3,3])
        
readFile = open("C-small-attempt0.in")
writeFile = open("C-small-attempt0.out", "a")

numberOfTestCases = -1
numberOfStudents = -1
caseNumber = 1
rowsAndColumns = []
for line in readFile.readlines():
    if(numberOfTestCases == -1):
        numberOfTestCases = int(line)
        continue
    if numberOfStudents == -1:
        numberOfStudents = int(line)
        #print N
        continue
    else:
        lineI = map(lambda x: int(x), line.split())
        
        writeFile.write("Case #" + str(caseNumber) + ": " + str(bff(lineI)) + "\n")
        caseNumber = caseNumber + 1

        numberOfStudents = -1
            
    

readFile.close()
writeFile.close()
