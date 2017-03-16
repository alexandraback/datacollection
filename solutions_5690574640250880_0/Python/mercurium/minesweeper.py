import string

file_name = 'C-small-attempt0.in'

minesInput = open(file_name, 'r')
data = string.split(minesInput.read().strip(), '\n')
numCases = int(data[0])

for case in range(1,numCases+1):
    print "Case #" + str(case) + ":"
    row, col, numMines = [int(x) for x in string.split(data[case],' ')]

    if row*col - numMines >= row * 2:
        answer = ['*'] * numMines + ['.'] * (row*col-1 - numMines) + ['c']
        for r in range(row):
            rowPrint = string.join([str(x) for x in answer[col*r: col*(r+1)] ], '')
            print rowPrint
        continue

    elif row*col - numMines >= col * 2:
        answer = [[ '*' for c in range( col)] for r in range(row) ]
        for i in range(row*col-numMines):
            r, c = i /col, i%col
            answer[r][c] = '.'
        answer[0][0] = 'c'
        answer = [string.join(ans,'') for ans in answer]
        for ans in answer:
            print ans
        continue

    else:
        factor = 0
        numFree = row*col - numMines
        for i in range(2,max(col, row)):
            if numFree % i == 0 and numFree != i and numFree/i < max(col,row):
                factor = i
                break
        if factor == 0:
            print "Impossible"
            continue
        factor = max(factor, numFree/factor)
        if factor < col:
            answer = ['c' + '.' * (factor-1) + '*' * (col-factor) ] + \
                     ['.' * factor + '*' * (col - factor) for i in range(1,numFree/factor)] + \
                     ['*' * col for i in range(numFree/factor, row)]
            for ans in answer:
                print ans

