filesDir = 'C:\\codejam2012\\'
inFile = 'files\\A-small-attempt2.in'

def writeToFile(filename,content):
    f = open(filesDir + filename,'w')
    f.write(content)
    f.close()

def readFileLines(filename):
    f = open(filesDir + filename,'r')
    t = f.readlines()
    t.pop(0)
    g = []
    for l in t:
        g.append(l.replace('\n',''))
    return g

def processArray(array):
    output = ''
    curCase = 1
    n = 0
    M = []
    for line in array:
        if n == 0:
            n = int(line)
            M = []
        else:
            m = line.split(' ')
            M.append([(int(w)-1) for w in m[1:]])
            n -= 1
            if n == 0:
                curLine = 'Case #' + str(curCase) + ': ' + processGroup(M,curCase) + '\n'
                output += curLine
                curCase += 1
    return output

def procedure():
    outFile = inFile.replace('.in','.out')
    array = readFileLines(inFile)
    processedArray = processArray(array)
    writeToFile(outFile,processedArray)


def processTree(start, tree, v, curCase):
    res = 'No'
    if start == []:
        return res
    for cur in start:
        k = cur
        while True:
            if k in v:
                return 'Yes'
            else:
                if k <> []:
                    v.append(k)
                    k = tree[k]
                    res = processTree(k, tree, v, curCase)
                    break
                else:
                    continue
    return res
            
def processGroup(input, curCase):
    res = ''
    v = []
    for start in input:
        v = []
        if start <> []:
            res = processTree(start, input, v, curCase)
            if res == 'Yes':
                break
        else:
            res = 'No'
    return res

procedure()


