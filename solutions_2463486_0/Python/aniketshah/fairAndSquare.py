def isPalindrome(number):
    numberString = str(number)
    lengthOfNumberString = len(numberString)
    
    for i in range(lengthOfNumberString/2):
        if numberString[i] != numberString[(i + 1) * -1]:
            return False
    return True

def fairAndSquare(maximumProduct = 1000):
    fairAndSquares = []
    for i in range(1, maximumProduct):
        if isPalindrome(i):
            product = i * i
            if product < maximumProduct:
                if isPalindrome(product):
                    fairAndSquares.append(product)
            else:
                break
    return fairAndSquares

def run(inputFile, outputFile = "output.txt"):
    reader = open(inputFile)
    writer = open(outputFile, 'w')
    caseCounter = 1
    fairAndSquares = fairAndSquare()
    
    for line in reader.readlines()[1:]:
        line = line.strip()
        givenRange = map(int, line.split())
        answer = len(filter(lambda x: x >= givenRange[0] and x <= givenRange[1], fairAndSquares))
        writer.write("Case #" + str(caseCounter) + ": " + str(answer) + "\n")
        caseCounter = caseCounter + 1
    print "Program completed successfully. Look at " + outputFile + " for output"
