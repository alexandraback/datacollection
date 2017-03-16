INPATH = r"C:\Users\Gil\Documents\jam\input.txt"
OUTPATH = r"C:\Users\Gil\Documents\jam\output.txt"

from fractions import Fraction
import math
import itertools

def getSmallStr(string):
    newStr = string[0]
    for i in string[1:]:
        if i == newStr[-1]:
            continue
        newStr += i

    return newStr

def solveGame(data):
    num = data[0][0]
    parts = data[1]

    count = 0
    smallStrings = [getSmallStr(string) for string in parts]

    middles = set()
    starts = set()
    ends = set()

    for string in smallStrings:
        starts.add(string[0])
        ends.add(string[-1])
        if len(string) > 2:
            for letter in set(string[1:-1]):
                if string.count(letter) > 1:
                    return "0"
                if letter in middles:
                    return "0"
                middles.add(letter)

    for letter in middles:
        if letter in starts or letter in ends:
            return "0"
    
    doubles = [string[0] + string[-1] for string in smallStrings]
    diffs = [string for string in doubles if (string[0] != string[-1])]
    idents = [string for string in doubles if (string[0] == string[-1])]

    starts = "".join([string[0] for string in diffs])
    for start in set(starts):
        if starts.count(start) > 1:
            return "0"
    
    ends = "".join([string[-1] for string in diffs])
    for end in set(ends):
        if ends.count(end) > 1:
            return "0"        

    starts = set(starts)
    ends = set(ends)

    inter = starts.intersection(ends)

    diffs = set(diffs)
    
    while(len(inter) > 0):
        for diff in diffs:
            changed = False
            if diff[0] in inter:
                for diff2 in diffs:
                    if diff[0] == diff2[-1]:
                        if diff == diff2:
                            return "0"
                        diffs.remove(diff)
                        diffs.remove(diff2)
                        diffs.add(diff2+diff)
                        inter.remove(diff[0])
                        changed = True
                        break
            elif diff[-1] in inter:
                for diff2 in diffs:
                    if diff[-1] == diff2[0]:
                        if diff == diff2:
                            return "0"
                        diffs.remove(diff)
                        diffs.remove(diff2)
                        diffs.add(diff+diff2)
                        inter.remove(diff[-1])
                        changed = True
                        break
            if changed == True:
                break

    starts = "".join([string[0] for string in diffs])
    for start in set(starts):
        if starts.count(start) > 1:
            return "0"
    
    ends = "".join([string[-1] for string in diffs])
    for end in set(ends):
        if ends.count(end) > 1:
            return "0"        

    starts = set(starts)
    ends = set(ends)


    identLetters = [string[0] for string in idents]
    optionIdents = 1

    for x in identLetters:
        if x not in diffs and x not in starts and x not in ends:
            diffs.add(x)
            identLetters.remove(x)
    
    optionDiffs = math.factorial(len(diffs))

##    print idents
    
##    print identLetters
    for identLetter in set(identLetters):
##        print identLetter, identLetters.count(identLetter)
        optionIdents *= math.factorial(identLetters.count(identLetter))

##    print optionDiffs, optionIdents
##    raw_input()
    count = optionIdents * optionDiffs
        
    return str(count)


data = open(INPATH,"r").readlines()
data = [x.replace("\n","") for x in data]
data = [[i for i in x.split(" ") ] for x in data]

numOfGames = int(data[0][0])

output = ""
curLine = 1

for i in range(numOfGames):
    if i%10 == 0:
        print i
        
    firstRow = data[curLine:curLine+1][0]
    numberOfRows = 2 # int(firstRow[0]) + int(firstRow[1]) + 1
    output += "Case #%s: " % (i+1)
    output += solveGame(data[curLine:curLine+numberOfRows])
    output += "\n"
    curLine += numberOfRows

output = output.rstrip("\n")

print output

open(OUTPATH,"w").write(output)

##    perms = itertools.permutations(doubles)
##    permStrings = ["".join(perm) for perm in perms]
##    smallPerms = [getSmallStr(string) for string in permStrings]
##
##    for perm in smallPerms:
##        good = True
##        for letter in set(perm):
##            if perm.count(letter) != 1:
##                good = False
##                break
##        if good:
##            count += 1
##    middles = set()
##    letters = set()
##    for part in parts:
##        for letter in part:
##            letters.add(letter)
##
##    for part in parts:
##        for letter in part:            
##            if letter != part[0] and letter != part[-1]:
##                if letter in middles:
##                    return "0"
##                middles.add(letter)

    
    

    #smallParts = [part[0]+part[-1] for part in parts]
    
