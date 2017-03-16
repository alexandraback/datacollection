inputF = open('A-small-attempt0.in', 'r')
output = open('A-small-attempt0.out', 'w')

def findLastWord(line):
    if len(line) <= 1:
        return line
    maxChar = max(line)
    maxIndex = line.rfind(maxChar)
    return maxChar + findLastWord(line[0:maxIndex]) + line[maxIndex+1:]



numCases = int(inputF.readline())

for i in range(numCases):
    line = inputF.readline().strip()
    lastWord = findLastWord(line)

    output.write('Case #' + str(i+1) + ': ')
    output.write(lastWord + '\n')

inputF.close()
output.close()
