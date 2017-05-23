#file('C-large-practice.in').read()
#
dataTable = {'a': '2', 'c': '222', 'b': '22', 'e': '33', 'd': '3', 'g': '4',
             'f': '333', 'i': '444', 'h': '44', 'k': '55', 'j': '5', 'm': '6',
             'l': '555', 'o': '666', 'n': '66', 'q': '77', 'p': '7',
             's': '7777', 'r': '777', 'u': '88', 't': '8', 'w': '9',
             'v': '888', 'y': '999', 'x': '99', 'z': '9999', ' ':'0'}

def processAllInput(text, toFile = False):
    fileName = text
    if toFile:
        text = file(fileName).read()
    finalResult = []
    numTests = int(text.split('\n')[0])
    lines = text.split('\n')
    for i in range(numTests):
        #Problem-specific code starts here############
        
        (farmcost, farmoutput, win) = map(float, lines[i+1].split())
        solution = ''

        def getProduction(num):
            return 2.0 + (num) * farmoutput
        def wouldFarmHelp(currentFarms):
            expectedProduction = getProduction(currentFarms+1)
            timeWith = (win)/expectedProduction
            timeWithout = (win-farmcost)/getProduction(currentFarms)
            return timeWith < timeWithout

        numFarmsBought = 0
        timeElapsed = 0.0
        while True:
            if wouldFarmHelp(numFarmsBought):#buy farm
                timeElapsed += farmcost/getProduction(numFarmsBought)
                numFarmsBought += 1
            else:#finish with current farms
                timeElapsed += win/getProduction(numFarmsBought)
                break

        print numFarmsBought,
        line = 'Case #{0}: {1}'.format(i+1, timeElapsed)
        
        #Problem-specific code ends here##############
        if not toFile:
            print line
        finalResult.append(line)
    if toFile:
        file(fileName.split('.')[0]+'.out', 'w').write('\n'.join(finalResult))
