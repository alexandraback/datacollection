import utils



if __name__ == "__main__":
    inputFile = "inputQ1"
    inputFile = "A-small-attempt1.in"
    #inputFile = "A-small-attempt0.in"
    inputFile = "A-large.in"
    #inputFile = "A-large.in.txt"
    #inputFile = "inputQ3"
    outputFile = "outputQ1"
    inputData = utils.createReadFile(inputFile)
    outputData = utils.createWriteFile(outputFile)
    cases = inputData.next()
    cases = cases.strip()
    for index in range(1, int(cases) + 1):
        print "case ", index
        rowData = inputData.next()
        rowData = rowData.strip()
        word = list(rowData)
        first = word[0]
        output = first
        print word
        for i in range(1, len(word)):
            letter = word[i]
            print letter, first
            if letter >= first:
                output = letter + output
                first = letter
            else:
                output = output + letter
            print output

        print output

        outputString = "Case #" + str(index)+ ": " + output + "\n"
        #print outputString
        outputData.write(outputString)
                
            
