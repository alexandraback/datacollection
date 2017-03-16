inputFile = open('A-small-attempt0.in', 'rU')
outputFile = open('A-small-attempt0.out', 'w')

cases = int(inputFile.readline())

from string import ascii_lowercase

VOWELS = list('aeiou')

CONSONANTS = list(ascii_lowercase)
for letter in CONSONANTS:
    if letter in VOWELS:
        CONSONANTS.remove(letter)

def allConsonants(string):
    for letter in string:
        if letter in 'aeiou':
            return False
    return True


for currentCase in xrange(1, cases + 1):
    # do stuff
    # NOTE: n-values are based on substrings with n-consec consonants.
    line = inputFile.readline().strip().split()
    name, N = line[0], int(line[1])

    totalSubstrings = 0
    lengthNsubs = [] # list of substrings length N all consonants.
    allSubstrings = set() # set of tuples which link to valid substrings
    for index in xrange(0, len(name) - N + 1): # check the xrange DONE
        substring = name[index:index + N]
        if allConsonants(substring):
            lengthNsubs.append((index, index + N))
    for interval in lengthNsubs:
        a, b = interval
        for x in xrange(0, a + 1):
            for y in xrange(b, len(name) + 1):
                allSubstrings.add((x, y))

    answer = len(allSubstrings)
    print "Case #%d: %d" % (currentCase, answer)

    outputFile.write("Case #%d: %d\n" % (currentCase, answer))

    # BRUTE FORCE:
##    totalSubstrings = 0
##    allSubs = []
##    for a in xrange(0, len(name)):
##        for b in xrange(a, len(name) + 1):
##            allSubs.append(name[a:b])
##    for substring in allSubs:
##        if len(substring) < N:
##            pass
##        for index in xrange(0, len(substring) - N + 1):
##            superstring = substring[index: index + N]
##            if allConsonants(superstring):
##                totalSubstrings += 1
##                break
##    print totalSubstrings, len(allSubs)
            
        


inputFile.close()
outputFile.close()
