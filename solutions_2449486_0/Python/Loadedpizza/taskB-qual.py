# Problem B: Lawnmower

inputFile = open('B-small-attempt0.in','rU')
outputFile = open('B-small-attempt0.out','w')

# METHOD 1: BRUTE FORCE

# define left, right, up, down for each square
# check if all four are closed off
# actually sufficient to just check row, column

cases = int(inputFile.readline())
for currentCase in xrange(1, cases + 1):
    ROWS, COLS = map(int, inputFile.readline().strip().split())
    lawn = []
    for line in xrange(ROWS):
        lawn.append(map(int, inputFile.readline().strip().split()))
    #lawn is now a matrix, reference by lawn[row][col]

    possible = 'YES'
    for row in xrange(ROWS):
        for col in xrange(COLS):
            across = lawn[row]
            down = []
            for x in xrange(ROWS):
                down.append(lawn[x][col])
            alpha, beta = 0, 0
            for x in across:
                if x > lawn[row][col]:
                    alpha = 1
                    break
            for y in down:
                if y > lawn[row][col]:
                    beta = 1
                    break
            if alpha == 1 and beta == 1:
                possible = 'NO'
                break
        if possible == 'NO':
            break

##    print "Case #%d: %s" % (currentCase, possible)
    outputFile.write("Case #%d: %s\n" % (currentCase, possible))






inputFile.close()
outputFile.close()
