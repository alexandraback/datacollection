def paintForInner(radius):
    return (2 * radius) + 1

def solve(cases, inFile, outputFile):
    for c in xrange(1, cases + 1):
        outputFile.write("Case #" + str(c) + ": ")
        lineData = inFile.readline().split()
        radius = int(lineData[0])
        paint = int(lineData[1])
        print 'CASE:', 'RADIUS', radius, 'PAINT', paint
        rings = 0
        paintInNextRing = paintForInner(radius)
        while (paint >= paintInNextRing):
            print 'PAINT REMAINING', paint
            paint -= paintInNextRing
            paintInNextRing += 4
            rings += 1
        print 'SOLVED:', rings
        outputFile.write(str(rings) + '\n')

inFile = open('A-small-attempt0.in')
outputFile = open('output.txt', 'w')

cases = int(inFile.readline())
print cases, ' cases read'

solve(cases, inFile, outputFile)
print 'done'

inFile.close()
outputFile.close()