'''
Created on 14.04.2012

@author: Philip PEter
'''
if __name__ == '__main__':
    pass

        

def getResult(classes):
    lut = {}
    index = 1;
    for entry in classes:
        values = entry.split()
        nrParents = int(values[0])
        lut[index] = {}
        lut[index]['direct'] = set()
        lut[index]['indirect'] = set()
        lut[index]['indirect'].add(index)
        if nrParents > 0:
            for value in values[1:]:
                lut[index]['direct'].add(int(value))
        index += 1
    change = True
    while change:
        change = False
        for index in lut.keys():
            if(len(lut[index]['direct'])) > 0:
                newSet = set()
                for parent in lut[index]['direct']:
                    '''
                    if parent in newSet:
                        print "Found diamond!"
                        return "Yes"
                    '''                        
                    newSet.add(parent)
                    newSet.update(lut[parent]['indirect'])
                if len(newSet.difference(lut[index]['indirect'])) > 0:
                    change = True
                lut[index]['indirect'] = newSet
    #Find diamonds
    for index in lut.keys():
        tempSet = set()
        for parent in lut[index]['direct']:
            intersect = tempSet.intersection(lut[parent]['indirect'])
            if len(intersect) > 0:
                return "Yes"
            tempSet.update(lut[parent]['indirect'])
        
    return "No"


inputFile  = open('A-large.in', 'r')
outputFile = open('A-large.out', 'w')

nrTestCases = inputFile.readline()
nrTestCases = int(nrTestCases)
currentNr = 1
while nrTestCases > 0:
    cases = int(inputFile.readline())
    classes = []
    while cases > 0:
        classes.append(inputFile.readline())
        cases -= 1
    result = str(getResult(classes))
    
    print "\nCase #" +str(currentNr) +": " + result
    if (currentNr > 1):
        outputFile.write("\n")
    outputFile.write('Case #'+str(currentNr)+': ' + result)
    currentNr += 1
    nrTestCases -=1

inputFile.close()        
outputFile.close()     