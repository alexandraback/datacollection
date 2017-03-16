import math

def find(s, ch):
    return [i for i, ltr in enumerate(s) if ltr == ch]

def getDigit(i,  q):
    return int(str(i)[len(str(i)) - q - 1]) if len(str(i)) > q else 0

def findSmallest(defaultC,  defaultJ,  cChange,  jChange,  current):
    smallest = 10000000000
    smallestC = 10000000000
    smallestJ = 10000000000
    if current == -1:
        return defaultC,  defaultJ
    if current in jChange:
        c = 0
        j = 0
        for x in range(0, 10):
            if current in cChange:
                for y in range(0, 10):
                    c,  j = findSmallest(defaultC + int(math.pow(10, current)) * y,  defaultJ + int(math.pow(10, current)) * x,  cChange,  jChange,  current - 1)
                    value = abs(c-j)
                    if value < smallest or (value == smallest and c < smallestC) or (value == smallest and c == smallestC and j < smallestJ):
                        smallest = value
                        smallestC = c
                        smallestJ =j
            else:
                c,  j = findSmallest(defaultC,  defaultJ + int(math.pow(10, current)) * x,  cChange,  jChange,  current - 1)
                value = abs(c-j)
                if value < smallest or (value == smallest and c < smallestC) or (value == smallest and c == smallestC and j < smallestJ):
                    smallest = value
                    smallestC = c
                    smallestJ =j
    elif current in cChange:
        for y in range(0, 10):
            c,  j = findSmallest(defaultC + int(math.pow(10, current)) * y,  defaultJ,  cChange,  jChange,  current - 1)
            value = abs(c-j)
            if value < smallest or (value == smallest and c < smallestC) or (value == smallest and c == smallestC and j < smallestJ):
                smallest = value
                smallestC = c
                smallestJ =j
    else:
        smallestC,  smallestJ = findSmallest(defaultC,   defaultJ,  cChange,  jChange,  current - 1)
    return smallestC,  smallestJ

def getSmallest(possibleC,  possibleJ):
    defaultC = int(possibleC.replace("?",  "0"))
    defaultJ = int(possibleJ.replace("?",  "0"))
    cChange = [len(possibleC)-1-x for x in find(possibleC,  "?")]
    jChange = [len(possibleJ)-1-x for x in find(possibleJ,  "?")]
    firstC = len(str(defaultC))- 1 if defaultC > 0 else 0
    firstJ = len(str(defaultJ))- 1 if defaultJ > 0 else 0
    cChangeOriginal = [x for x in cChange]
    jChangeOriginal = [x for x in jChange]
    return findSmallest(defaultC,  defaultJ,  cChange,  jChange,  20)
    

def main():
    cases = int(raw_input())
    for x in range(1, cases + 1):
        first,  last = raw_input().split(" ")
        c,  j = getSmallest(first,  last)
        answerC = str(c).zfill(len(first))
        answerJ = str(j).zfill(len(first))
        print("Case #%s: %s %s" % (x, answerC, answerJ))

main()
