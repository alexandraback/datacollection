# B-pogo

inputFile = open('B-small-attempt0.in', 'rU')
outputFile = open('B-small-attempt0.out','w')

testCases = int(inputFile.readline())

for currentCase in xrange(1, testCases + 1):
    # BRUTE FORCE FOR FIRST PART
    X, Y = map(int, inputFile.readline().strip().split())

    moves = []
    if X < 0:
        moves.append('EW' * abs(X))
    else:
        moves.append('WE' * X)
    if Y < 0:
        moves.append('NS' * abs(Y))
    else:
        moves.append('SN' * Y)

    solution = ''.join(moves)

    outputFile.write('Case #%d: %s\n' % (currentCase, solution))

inputFile.close()
outputFile.close()
