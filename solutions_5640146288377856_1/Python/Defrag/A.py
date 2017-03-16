with open('in.txt') as f:
    lines = f.readlines()

def getInts(line):
    return map(int, line.split())

numCases = int(lines[0])
for caseNum in xrange(numCases):
    r, c, w = getInts(lines[caseNum+1])

    answer = r * (c//w)
    if (c%w != 0):
        answer += 1
    answer += w-1
    print 'Case #{}: {}'.format(caseNum+1, answer)

