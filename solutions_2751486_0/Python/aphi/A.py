import sys


def solve(word, n):
    
    wordlen = len(word)
    consonants = 'bcdfghjklmnpqrstvwxyz'
    cSet = set()
    for c in consonants:
        cSet.add(c)
    
    
    
    
    score = 0
    
    start = 0
    starts = []
    for start in range(wordlen + 1 - n):#word[:1-n]:

        if all(word[i] in cSet for i in range(start, start+n)):
            starts.append(start)
            
    
    j = 0
    for start in range(wordlen + 1 - n):
        if j == len(starts):
            break
            
        dist = starts[j] - start
        
        if not dist:
            j += 1 # next start
            
        score += wordlen-start-n-dist+1

    
    return score



fp = open(sys.argv[1], "r")
fpOut = open("output_%s.txt"%sys.argv[1], "w")

lines = fp.readlines()
numCases = int(lines.pop(0).strip())

for c in range(1, numCases+1):
    
    word, n = lines.pop(0).strip().split(" ")
    n = int(n)
    
    result = solve(word, n)
    
    outString = "Case #%d: %d\n"%(c, result)
    print outString,
    fpOut.write(outString)
    
fpOut.close()
