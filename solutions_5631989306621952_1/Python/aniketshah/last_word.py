def lastWord(inputText):
    finalWord = ""
    for letter in inputText:
        #print letter
        if finalWord is not "":
            if letter < finalWord[0]:
                finalWord = finalWord + letter
            else:
                finalWord = letter + finalWord
        else:
            finalWord = finalWord + letter
            
    return finalWord

#print lastWord("CABCBBABC")

readFile = open("A-large.in")
writeFile = open("A-large.out", "a")

numberOfTestCases = -1
caseNumber = 1
for line in readFile.readlines():
    if(numberOfTestCases == -1):
        numberOfTestCases = int(line)
        continue

    writeFile.write("Case #" + str(caseNumber) + ": " + lastWord(line))
    caseNumber = caseNumber + 1

readFile.close()
writeFile.close()
