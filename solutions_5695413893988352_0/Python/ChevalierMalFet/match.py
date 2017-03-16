'''inputF = open('test.txt', 'r')
output = open('output.txt', 'w')

# Once it's determined which is smaller, easy from there
# most significant digit where they both are determined defines which
# should be smaller.
# If none, can match perfectly,
# Otherwise,


def matchScores(score1, score2):
    problemDigit = False
    for i in range(len(score1)):
        if score1[i] != '?' and score2[i] != '?' and score1[i] != score2[i]:
            problemDigit = True
            break

    # If there's no problem digits, 
    if not problemDigit:
        answer = ''
        for i in range(len(score1)):
            if score1[i] != '?':
                answer += score1[i]
            elif score2[i] != '?':
                answer += score2[i]
            else:
                answer += '0'
        return (answer, answer)

    # Otherwise, get the problem string
    for j in range(i,  len(score1)+1):
        if j == len(score1):
            break
        if score1[i] == '?' or score2[i] == '?':
            break

    problem1 = score1[i:j]
    problem2 = score2[i:j]

    half = 5*(10**(len(problem1)-1))
    flipped = False
    first = False

    if problem1 < problem2:
        ordered = (score1, score2)
    else:
        flipped = True
        ordered = (score2, score1)

    if abs(problem1-problem2) == half:
        first = True
        ordered = (score1, score2)
    elif abs(problem1-problem2) > half:
        flipped = not flipped
        ordered = (ordered[1], ordered[0])

    
    


    
        

    


numCases = int(inputF.readline())

for i in range(numCases):
    line = inputF.readline().strip()
    lastWord = findLastWord(line)

    output.write('Case #' + str(i+1) + ': ')
    output.write(lastWord + '\n')

inputF.close()
output.close()
'''

# Stupid version
import itertools
inputF = open('B-small-attempt1.in', 'r')
output = open('B-small-attempt1.out', 'w')

def checkCompatibility(score, partialScore):
    strScore = str(score).zfill(len(partialScore))
    for i in range(len(partialScore)):
        if partialScore[i] != '?':
            if strScore[i] != partialScore[i]:
                return False
    return True

def generatePossibilities(partialScore):
    if len(partialScore) == 1:
        if partialScore[0] == '?':
            return range(10)
        else:
            return [int(partialScore[0])]

    else:
        if partialScore[0] != '?':
            return [int(partialScore[0])*(10**(len(partialScore)-1)) + i
                    for i in generatePossibilities(partialScore[1:])]
        else:
            significant = [i*(10**(len(partialScore)-1)) for i in range(10)]
            future = generatePossibilities(partialScore[1:])
            crossProduct = list(itertools.product(significant, future))
            return [sum(x) for x in crossProduct]

def matchScores(score1, score2):
    digits = len(score1)
    minDiff = 10000
    minScore1 = 10000
    minScore2 = 10000
    for i in generatePossibilities(score1):
        for j in generatePossibilities(score2):
            if abs(i-j) < minDiff:
                minDiff = abs(i-j)
                minScore1 = i
                minScore2 = j
            elif abs(i-j) == minDiff:
                if i < minScore1:
                    minScore1 = i
                    minScore2 = j
                elif i == minScore1 and j < minScore2:
                    minScore2 = j
    return (str(minScore1).zfill(len(score1)), str(minScore2).zfill(len(score2)))

numCases = int(inputF.readline())

for i in range(numCases):
    line = inputF.readline().strip().split()
    scores = matchScores(line[0], line[1])

    output.write('Case #' + str(i+1) + ': ')
    output.write(scores[0] + ' ' + scores[1] + '\n')

inputF.close()
output.close()
