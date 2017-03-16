def removeFirst(letters, goAway):
    newString = letters
    for x in goAway:
        index = newString.index(x)
        newString = newString[:index] + newString[index+1:]
    return newString

order = [(0,  "Z",  ["Z",  "E",  "R",  "O"]),  (2,  "W",  ["T",  "W", "O"]), (4,  "U",  ["F",  "O",  "R",  "U"]),  (6,  "X",  ["S",  "I",  "X"]),  (8,  "G",  ["E",  "I",  "G",  "H",  "T"]),  (1,  "O",  ["N", "E",  "O"]),  (3,  "T",  ["T",  "H",  "E",  "R",  "E"]), (5,  "F",  ["F",  "E",  "I",  "V"]),  (7,  "S",  ["S",  "E",  "V",  "E",  "N"]),  (9,  "N",  ["N",  "E",  "N",  "I"])]

def getNumbers(letters):
    soFar = []
    for x,  lookFor,  contains in order:
        while lookFor in letters:
            letters = removeFirst(letters,  contains)
            soFar.append(x)
    soFar = sorted(soFar)
    return soFar

def main():
    cases = int(raw_input())
    for x in range(1, cases + 1):
        current = raw_input()
        answer = getNumbers(current)
        print("Case #%s: %s" % (x, ''.join(map(str, answer)) ))

main()
