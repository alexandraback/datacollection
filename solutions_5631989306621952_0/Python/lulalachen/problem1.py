problems = int(raw_input())  # read a line with a single integer
for problem in xrange(1, problems + 1):
    line = raw_input()
    maxChar = line[0]
    currentString = []
    currentString.insert(0, maxChar)
    for character in line[1:]:
        if character >= maxChar:
            currentString.insert(0, character)
            maxChar = character
        else:
            currentString.append(character)
    print "Case #{}: {}".format(problem, ''.join(map(str, currentString)))
