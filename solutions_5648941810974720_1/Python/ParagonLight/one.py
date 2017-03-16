import utils

if __name__ == "__main__":
    inputFile = "inputQ1"
    #inputFile = "test"
    inputFile = "A-small-attempt0.in"
    inputFile = "A-large.in"
    #inputFile = "A-large.in.txt"
    #inputFile = "inputQ3"
    outputFile = "outputQ1"
    inputData = utils.createReadFile(inputFile)
    outputData = utils.createWriteFile(outputFile)
    cases = inputData.next()
    cases = cases.strip()
    d = {'Z':0,'E':1,'R':2,'O':3,'N':4,'T':5,'W':6,'H':7,'F':8,'U':9,'I':10,'V':11,'S':12,'X':13,'G':14}
    for index in range(1, int(cases) + 1):
        print "case ", index
        rowData = inputData.next()
        rowData = rowData.strip()
        word = [0]*15
        for i in range(len(rowData)):
            c = rowData[i]
            word[d[c]] += 1

        o = []
        if word[0] > 0:
            c = word[0]
            for i in range(c):
                o.append(0)
            word[0] -= c 
            word[1] -= c
            word[2] -= c
            word[3] -= c
        if word[6] > 0:
            print word
            c = word[6]
            for i in range(c):
                #o += '2'
                o.append(2)
            word[5] -= c
            word[6] -= c
            word[3] -= c
            print word
        if word[9] > 0:
            c = word[9]
            for i in range(c):
                #o += '4'
                o.append(4)
            word[8] -= c
            word[9] -= c
            word[3] -= c
            word[2] -= c
        if word[13] > 0:
            c = word[13]
            for i in range(c):
                #o += '6'
                o.append(6)
            word[13] -= c
            word[12] -= c
            word[10] -= c
        if word[14] > 0:
            c = word[14]
            for i in range(c):
                #o += '8'
                o.append(8)
            word[14] -= c
            word[1] -= c
            word[10] -= c
            word[7] -= c
            word[5] -= c
        if word[7] > 0:
            c = word[7]
            for i in range(c):
                #o += '3'
                o.append(3)
            word[5] -= c
            word[7] -= c
            word[2] -= c
            word[1] -= c
            word[1] -= c
        if word[3] > 0:
            c = word[3]
            for i in range(c):
                #o += '1'
                o.append(1)
            word[3] -= c
            word[4] -= c
            word[1] -= c
            print word
        if word[8] > 0:
            c = word[8]
            for i in range(c):
                #o += '5'
                o.append(5)
            word[8] -= c
            word[10] -= c
            word[11] -= c
            word[1] -= c
        if word[12] > 0:
            c = word[12]
            for i in range(c):
                #o += '7'
                o.append(7)
            word[12] -= c
            word[1] -= c
            word[11] -= c
            word[1] -= c
            word[4] -= c
        if word[1] > 0:
            c = word[1]
            for i in range(c):
                #o += '7'
                o.append(9)
            word[4] -= c
            word[10] -= c
            word[4] -= c
            word[1] -= c


        o = sorted(o)
        print o

        o = [str(c) for c in o]
        s = ''.join(o)

        print s
        outputString = "Case #" + str(index)+ ": " + s + "\n"
        #print outputString
        outputData.write(outputString)
                
            
