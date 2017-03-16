import utils
import math

if __name__ == "__main__":
    inputFile = "inputQ2"
    #inputFile = "test"
    inputFile = "B-small-attempt1.in"
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

        print rowData
        strs = rowData.split(' ')
        c = []
        for i in range(len(strs[0])):
            c.append(strs[0][i])
        j = []
        print strs
        for i in range(len(strs[1])):
            j.append(strs[1][i])
        
        mm = 10000
        ccc = '10000'
        jjj = '10000'
        
        for cc in range(10 ** len(c)):
            cs = str(cc)
            for k in range(len(c) - len(cs)):
                cs = '0' + cs
            flag = True
            for csi in range(len(cs)):
                if c[csi] != '?' and c[csi] != cs[csi]:
                    flag = False
                    break
            if not flag:
                continue
            for jj in range(10 ** len(c)):
                js = str(jj)
                for k in range(len(c) - len(js)):
                    js = '0' + js
                flag = True
                for jsi in range(len(js)):
                    if j[jsi] != '?' and j[jsi] != js[jsi]:
                        flag = False
                        break
                if not flag:
                    continue
                m = abs(cc-jj) 
                if m < mm:
                    ccc= cs
                    jjj = js
                    mm = m

        sc = ccc+ ' ' + jjj

        print sc
        outputString = "Case #" + str(index)+ ": " + sc + "\n"
        #print outputString
        outputData.write(outputString)
                
            
