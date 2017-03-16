def isConsonant(sequence):
    if all([letter not in "aeiou" for letter in sequence]):
        return True
    return False

#inputFile = open("test.txt", "r")
inputFile = open("A-small-attempt0.in", "r")
outputFile = open("Round1CA.txt", "w")

numCases = int(inputFile.readline().strip())

for caseIndex in range(1, numCases + 1):
    name, consecutive = inputFile.readline().strip().split(" ")
    consecutive = int(consecutive)
    socialStatus = 0

    consecutiveLocations = set()
    for letterIndex in range(len(name) - consecutive + 1):
        #print "subseq:",name[letterIndex:letterIndex + consecutive]
        if isConsonant(name[letterIndex:letterIndex + consecutive]):
            consecutiveLocations.add(letterIndex)

    #print consecutiveLocations

    for start in range(len(name)):
        for end in range(start, len(name)):
            #print start, end
            if end - start + 1 < consecutive:
                continue
            #print "valid"
            if any([start <= location <= end - consecutive + 1 for location in consecutiveLocations]):
                socialStatus += 1

    outputFile.write("Case #%d: %d\n" % (caseIndex, socialStatus))

inputFile.close()
outputFile.close()