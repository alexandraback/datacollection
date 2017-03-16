import utils

def notExst(i, exs):
    for v in exs:
        if v == i:
            return False
    return True

def visit(cir, cur, exs, length, res):
    print 'visit', cur, exs, length
    if length == len(cir):
        for p in range(length):
            curp = length
            cur = exs[length-1-p]
            if cir[cur] == exs[0]:
                return length
            elif cir[cur] == exs[length-p-2]:
                return length
            else:
                continue
    """
    if length == len(cir) - 1:
        if cir[cur] != exs[0]:
            return length
        else:
            return length + 1
    """
    nex = cir[cur]
    for v in exs:
        if nex == v:
            print length, nex
            if nex == exs[0]:
                return length
            for i in range(len(cir)):
                print nex, cur, cir[i]
                if cir[i] == cur and notExst(i, exs):
                    if res < (length + 1):
                        res = length + 1
                        print "res3", res
                        return res
            if res < (length):
                res = length
                print "res1", res
            return res

    if nex == -1:
        print length
        if res < (length):
            res = length
            print "res2", res
        return res
    else:
        exs.append(nex)
        print cur, nex, exs, res
        res = visit(cir,nex, exs, length + 1, res)
        print 'return',res
        return res



if __name__ == "__main__":
    inputFile = "inputQ3"
    #inputFile = "B-small-attempt0.in"
    inputFile = "C-small-attempt3.in"
    #inputFile = "B-large.in"
    #inputFile = "A-large.in.txt"
    #inputFile = "inputQ3"
    outputFile = "outputQ3"
    inputData = utils.createReadFile(inputFile)
    outputData = utils.createWriteFile(outputFile)
    cases = inputData.next()
    cases = cases.strip()
    for index in range(1, int(cases) + 1):
    #for index in range(1, 6):#int(cases) + 1):
        print "case ", index
        rowData = inputData.next()
        rowData = rowData.strip()
        N = int(rowData)
        rowData = inputData.next()
        rowData = rowData.strip()
        bbf = rowData.split(' ')
        print N
        cir = [-1] * N


        
        

        for i in range(N):
            cir[i] = int(bbf[i])-1

        print bbf
        print cir
        resList = [0] * N
        for i in range(N):
            exs = [i]
            resList[i] = visit(cir, i, exs, 1, resList[i])
            print "resfff", resList[i]
        """
        from collections import OrderedDict

        d = {i:cir[i] for i in range(len(cir))}
        d = OrderedDict(sorted(d.items(), key=lambda t: t[1]))

        output = 0
        
        for pair in d.items():
        """
        large = -1
        for i in range(N):
            if large < resList[i]:
                large = resList[i]

        output = str(large)
        outputString = "Case #" + str(index)+ ": " + output + "\n"
        print outputString
        outputData.write(outputString)
                
            
