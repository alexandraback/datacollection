import utils
import math
import itertools

if __name__ == "__main__":
    inputFile = "inputQ3"
    #inputFile = "test"
    inputFile = "C-small-attempt3.in"
    #inputFile = "A-large.in"
    #inputFile = "A-large.in.txt"
    #inputFile = "inputQ3"
    outputFile = "outputQ3"
    inputData = utils.createReadFile(inputFile)
    outputData = utils.createWriteFile(outputFile)
    cases = inputData.next()
    cases = cases.strip()
    for index in range(1, int(cases) + 1):
        print "case ", index
        rowData = inputData.next()
        rowData = rowData.strip()
        N = int(rowData) 
        topics = []
        f = {}
        s = {}
        fake = 0
        for i in range(N):
            rowData = inputData.next()
            rowData = rowData.strip()
            topic = rowData
            topics.append(topic)

        st = []
        for t in topics:
            strs = t.split(' ')
            if strs[0] in f or strs[1] in s:
                st.append(topic)
            f[strs[0]] = 1
            s[strs[1]] = 1


        for t in st:
            strs = t.split(' ')
            if strs[0] in f and strs[1] in s:
                fake += 1

            f[strs[0]] = 1
            s[strs[1]] = 1

        sc = str(fake)

        outputString = "Case #" + str(index)+ ": " + sc + "\n"
        print outputString
        outputData.write(outputString)
                
            
