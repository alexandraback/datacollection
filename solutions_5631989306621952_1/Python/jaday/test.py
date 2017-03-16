def append(s, c):
    if(ord(c) >= ord(s[0])):
        return c + s
    return s + c

f = open('A-large.in', 'r')
f2 = open('output', 'w')
numCases = int(f.readline())
for x in range(0, numCases):
    word = f.readline()
    lastWord = "" + word[0]
    for y in range(1, len(word)):
        lastWord = append(lastWord, word[y])
    f2.write("Case #" + str(x+1) + ": " + lastWord)