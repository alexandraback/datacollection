def dataParser(fileDir):
    inputfile = open(fileDir,'rU')
    nbrOfCases = int(inputfile.readline())
    cases = [None for i in range(nbrOfCases)]
    for i in range(nbrOfCases):
        cases[i] = inputfile.readline()
        cases[i] = cases[i][0:len(cases[i])-1]
    inputfile.close()
    return cases

def minFlips(x,target,cache):
    if x.count('+')==len(x):
        return 0 if target=='+' else 1
    elif x.count('-')==len(x):
        return 0 if target=='-' else 1
    elif (x,target) in cache:
        return cache[(x,target)]
    else:
        notTarget = '+' if target=='-' else '-'
        firstNotTarget = next(i for i in range(len(x)-1,-1,-1) if x[i]!=target)
        output = float('inf')
        for i in range(0,firstNotTarget):
            if x[i]==notTarget:
                continue
            else:
                remain = x[i+1:firstNotTarget+1]
                flips = minFlips(x[0:i+1],notTarget,cache)+minFlips(remain[::-1],notTarget,cache)+1
                output = min(output,flips)
        output = min(output,minFlips(x[0:firstNotTarget+1],notTarget,cache)+1)
        cache[(x,target)] = output
        return output

cases = dataParser('test.txt')
outputFile = open('out.txt','w')
for i in range(len(cases)):
    cache = dict()
    rslt = minFlips(cases[i],'+',cache)
    outputFile.write('Case #' + str(i + 1) + ': '+str(rslt)+'\n')
outputFile.close()