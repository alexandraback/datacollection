import utils



if __name__ == "__main__":
    inputFile = "inputQ2"
    inputFile = "B-small-attempt0.in"
    #inputFile = "A-small-attempt0.in"
    #inputFile = "A-large.in"
    #inputFile = "A-large.in.txt"
    #inputFile = "inputQ3"
    outputFile = "outputQ2"
    inputData = utils.createReadFile(inputFile)
    outputData = utils.createWriteFile(outputFile)
    cases = inputData.next()
    cases = cases.strip()
    for index in range(1, int(cases) + 1):
        print "case ", index

        rowData = inputData.next()
        rowData = rowData.strip()
        N = int(rowData)
        a = [0] * 2500
        print N
        for i in range(2*N-1):
            line = inputData.next()
            line = line.strip()
            line = line.split(' ')
            print line
            for s in line:
                a[int(s)] += 1

        output = ""
        count = 0
        for i in range(len(a)):
            if a[i]%2 != 0:
                output += str(i)
                count += 1
                if count < N:
                    output += " "
        print output

        outputString = "Case #" + str(index)+ ": " + output + "\n"
        print outputString
        outputData.write(outputString)
                
            
