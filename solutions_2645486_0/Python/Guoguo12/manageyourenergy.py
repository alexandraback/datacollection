gainCalc = lambda energy, value: energy * value

def newEnergy(current, maxEnergy, regain):
    current += regain
    if current > maxEnergy:
        current = maxEnergy
    return current

def gain(start, energy, regain, activities, maxEnergy):
    max = 0
    if start == len(activities) - 1:
        return gainCalc(energy, activities[-1])
    if energy < 0:
        print 'NO ENERGY'
        return 0
    for spend in xrange(0, energy + 1):
        case = gainCalc(spend, activities[start]) + gain(start + 1, newEnergy(energy - spend, maxEnergy, regain), regain, activities, maxEnergy)
        if case > max:
            max = case
    return max

def solve(cases, inFile, outputFile):
    for c in xrange(1, cases + 1):
        outputFile.write("Case #" + str(c) + ": ")
        line1 = inFile.readline().split()
        energyStartMax = int(line1[0])
        regain = int(line1[1])
        activityCount = int(line1[2])
        activities = map(int, inFile.readline().split())
        print 'CASE', (energyStartMax, regain, activityCount, activities)
        maxGain = gain(0, energyStartMax, regain, activities, energyStartMax)
        print 'SOLVED MAX GAIN', maxGain
        outputFile.write(str(maxGain) + '\n')

inFile = open('B-small-attempt1.in')
outputFile = open('output.txt', 'w')

cases = int(inFile.readline())
print cases, ' cases read'

solve(cases, inFile, outputFile)
print 'done'

inFile.close()
outputFile.close()