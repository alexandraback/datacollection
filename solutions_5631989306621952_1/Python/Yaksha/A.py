FILENAME = "A-large"




def solveString(s):
    letters = list(set(s))
    letters.sort()
    letters = letters[::-1]

    word = s[0]
    for char in s[1:]:
        thisCharIndex = letters.index(char)
        leftCharIndex = letters.index(word[0])
        if thisCharIndex > leftCharIndex:
            word = word + char
        else:
            word = char + word

    return word



with open(FILENAME + ".in") as infile:
    with open(FILENAME + ".out", 'w') as outfile:
        numCases = int(infile.readline())

        for i in range(numCases):
            inputVal = infile.readline().strip()
            outfile.write("Case #%d: %s\n" % (i + 1, solveString(inputVal)))



