### Set the input and output file names
import time
import datetime
filename = 'C-large'
input_filename = filename + '.in'
output_filename = filename + '.out.' + datetime.datetime.fromtimestamp(time.time()).strftime('%Y%m%d-%H%M%S') + '.txt'


### Open input file for reading
with open(input_filename) as f:
    lines = f.read().splitlines()

    ### Open output file for writing
    with open(output_filename, 'w') as output:

        ######################################################
        ### Initialise variables from first line of the file
        ######################################################   
        vars = lines[0].split(' ')
        cases = int(vars[0])                    # number of cases
        print(str(cases) + ' cases detected.')  # [soft validation]
        lineNum = 1                             # first case starts here
        caseNum = 0                             # for counting the num of cases
        caseSize_r = 1                          # number of rows in each case; default = 1
        caseSize_c = 1                          # number of columns in each case; default = 1
        
        #infoLines = True                        # Toggle according to question
        infoLines = False                       # Toggle according to question
        
        ### i.e. infoLines == True
        if infoLines:
            while lineNum < len(lines):
                ### A new case! Initialize some variables
                caseNum += 1                                    # case number count
                caseSize_r = int(lines[lineNum].split(' ')[0])  # case size (rows)
                caseSize_c = int(lines[lineNum].split(' ')[1])  # case size (columns)

                ### Case data saved into myArr
                myArr = [[] for x in range(caseSize_r)]
                for r in range(0, caseSize_r):
                    for c in range(0, caseSize_c):
                        myArr[r] = lines[lineNum + r + 1].split(' ')

                ### Do the Work!
                ### TODO!
                
                ### Output myArr
                print('Case #%d:' % (caseNum))
                output.write('Case #%d:\n' % (caseNum))
                for r in range(0, caseSize_r):
                    print('%s' % (' '.join(myArr[r])))
                    output.write('%s\n' % (' '.join(myArr[r])))

                ### Step
                lineNum += caseSize_r + 1
                
        ### i.e. infoLines == False
        else:   
            for caseNum in range(1, cases+1):
                
                ### Do the Work!
                rows = int(lines[lineNum].split(' ')[0])
                cols = int(lines[lineNum].split(' ')[1])
                mines  = int(lines[lineNum].split(' ')[2])
                gridsize = rows*cols
                
                ### initialise grid
                grid = [[] for x in range(rows)]

                ### Case '1 row' is always doable
                if rows == 1:
                    doable = True
                    grid[0] = ['c']
                    for x in range(0,cols-mines-1):
                        grid[0] = grid[0] + ['.']
                    for x in range(0,mines):
                        grid[0] = grid[0] + ['*']

                ### Case '1 col' is always doable
                elif cols == 1:
                    doable = True
                    for x in range(0,rows):
                        grid[x] = ['*']
                    for x in range(0,rows-mines):
                        grid[x] = ['.']
                    grid[0]=['c']
                    
                ### Case '2 rows'
                elif rows == 2:
                    if mines == 0:
                        doable = True
                        for r in range(0,rows):
                            for c in range(0,cols):
                                grid[r] = grid[r] + ['.']
                        grid[0][0] = 'c'
                    elif (gridsize - mines) == 1:
                        doable = True
                        for r in range(0,rows):
                            for c in range(0,cols):
                                grid[r] = grid[r] + ['*']
                        grid[0][0] = 'c'
                    #2 clear spaces  is impossible
                    elif (gridsize - mines) == 2:
                        doable = False
                    #odd clear spaces is impossible
                    elif (gridsize - mines) % 2 != 0:
                        doable = False
                    elif (gridsize - mines) % 2 == 0:
                        doable = True
                        grid[0]=['c']
                        fillmines = int(mines/2)
                        for x in range(0,cols-1-fillmines):
                            grid[0] = grid[0] + ['.']
                        for x in range(0,fillmines):
                            grid[0] = grid[0] + ['*']
                        for x in range(0,cols-fillmines):
                            grid[1] = grid[1] + ['.']
                        for x in range(0,fillmines):
                            grid[1] = grid[1] + ['*']
                    else:
                        print('Error in case %d' % (caseNum))
                        doable = '#Err!'

                ### Case '2 rows'
                elif cols == 2:
                    if mines == 0:
                        doable = True
                        for r in range(0,rows):
                            for c in range(0,cols):
                                grid[r] = grid[r] + ['.']
                        grid[0][0] = 'c'
                    elif (gridsize - mines) == 1:
                        doable = True
                        for r in range(0,rows):
                            for c in range(0,cols):
                                grid[r] = grid[r] + ['*']
                        grid[0][0] = 'c'
                    #2 clear spaces is impossible
                    elif (gridsize - mines) == 2:
                        doable = False
                    #odd clear spaces (with the exception of 1 mine is impossible
                    elif (gridsize - mines) % 2 != 0:
                        doable = False
                    elif (gridsize - mines) % 2 == 0:
                        doable = True
                        grid[0]=['c','.']
                        fillmines = int(mines/2)
                        for x in range(1,rows-1):
                            grid[x] = ['.','.']
                        for x in range(rows-fillmines,rows):
                            grid[x] = ['*','*']
                    else:
                        print('Error in case %d' % (caseNum))
                        doable = '#Err!'

                ### regular cases
                else:
                    #1 mine is always doable; put this exception at the top
                    if mines == 1:
                        doable = True
                        for r in range(0,rows):
                            for c in range(0,cols):
                                grid[r] = grid[r] + ['.']
                        grid[0][0] = 'c'
                        grid[rows-1][cols-1] = '*'
                    elif cols > 3 and rows == 3 and mines == 3:
                        doable = True
                        for r in range(0,rows):
                            for c in range(0,cols):
                                grid[r] = grid[r] + ['.']
                        grid[0][0] = 'c'
                        grid[0][cols-1] = '*'
                        grid[1][cols-1] = '*'
                        grid[2][cols-1] = '*'
                    elif (gridsize - mines) <= 0:
                        doable = False
                    elif (gridsize - mines) == 1:
                        doable = True
                        for r in range(0,rows):
                            for c in range(0,cols):
                                grid[r] = grid[r] + ['*']
                        grid[0][0] = 'c'
                    elif (gridsize - mines) == 2:
                        doable = False
                    elif (gridsize - mines) == 3:
                        doable = False
                    elif (gridsize - mines) == 4:
                        doable = True
                        for r in range(0,rows):
                            for c in range(0,cols):
                                grid[r] = grid[r] + ['*']
                        grid[0][0] = 'c'
                        grid[0][1] = '.'
                        grid[1][0] = '.'
                        grid[1][1] = '.'
                    elif (gridsize - mines) == 5:
                        doable = False
                    elif (gridsize - mines) == 6:
                        doable = True
                        for r in range(0,rows):
                            for c in range(0,cols):
                                grid[r] = grid[r] + ['*']
                        grid[0][0] = 'c'
                        grid[0][1] = '.'
                        grid[0][2] = '.'
                        grid[1][0] = '.'
                        grid[1][1] = '.'
                        grid[1][2] = '.'
                    elif (gridsize - mines) == 7:
                        doable = False
                    elif (gridsize - mines) == 8:
                        doable = True
                        for r in range(0,rows):
                            for c in range(0,cols):
                                grid[r] = grid[r] + ['*']
                        grid[0][0] = 'c'
                        grid[0][1] = '.'
                        grid[0][2] = '.'
                        grid[1][0] = '.'
                        grid[1][1] = '.'
                        grid[1][2] = '.'
                        grid[2][0] = '.'
                        grid[2][1] = '.'
                    elif (gridsize - mines) == 9:
                        doable = True
                        for r in range(0,rows):
                            for c in range(0,cols):
                                grid[r] = grid[r] + ['*']
                        grid[0][0] = 'c'
                        grid[0][1] = '.'
                        grid[0][2] = '.'
                        grid[1][0] = '.'
                        grid[1][1] = '.'
                        grid[1][2] = '.'
                        grid[2][0] = '.'
                        grid[2][1] = '.'
                        grid[2][2] = '.'
                    else:               # means there are at least 10 clear gridspaces
                        doable = True
                        # fill full of mines
                        for r in range(0,rows):
                            for c in range(0,cols):
                                grid[r] = grid[r] + ['*']
                        spaces = 0
                        
                        r = 1
                        c = 0
                        plantingSpaces = True
                        firstRow = True
                        while plantingSpaces:
                            if spaces  < gridsize - mines:
                                if firstRow:
                                    grid[0][c] = '.'
                                    grid[1][c] = '.'
                                    spaces +=2
                                    c +=1
                                else:
                                    grid[r][c] = '.'
                                    spaces +=1
                                    c +=1
                            if (gridsize - mines) - spaces == 3:
                                #if there is space, put it on the current line
                                if (c <= cols-3):
                                    if firstRow:
                                        grid[r+1][0] = '.'
                                        grid[r+1][1] = '.'
                                        grid[r+1][2] = '.'
                                        spaces +=3
                                        plantingSpaces = False
                                    else:
                                        grid[r][c] = '.'
                                        grid[r][c+1] = '.'
                                        grid[r][c+2] = '.'
                                        spaces +=3
                                        plantingSpaces = False
                                #otherwise put just one dot down if there is space
                                elif (c <= cols-1):
                                    if firstRow:
                                        grid[r+1][0] = '.'
                                        grid[r+1][1] = '.'
                                        grid[r+1][2] = '.'
                                        spaces +=3
                                        plantingSpaces = False
                                    else:
                                        grid[r][c] = '.'
                                        c +=1
                                        spaces +=1
                            if (gridsize - mines) - spaces == 2:
                                #if there is space, put it on the current line
                                if (c <= cols-2):
                                    if firstRow:
                                        grid[r+1][0] = '.'
                                        grid[r+1][1] = '.'
                                        spaces +=2
                                    else:
                                        grid[r][c] = '.'
                                        grid[r][c+1] = '.'
                                        spaces +=2
                                else:
                                    grid[r+1][0] = '.'
                                    grid[r+1][1] = '.'
                                    spaces +=2
                                plantingSpaces = False
                            if c == cols:
                                if firstRow:
                                    firstRow = False
                                    c = 0
                                    r = 2
                                else:
                                    c = 0
                                    r +=1
                        grid[0][0] = 'c'

                #Step
                lineNum += 1
                
                ### Output myAns
                if doable:
                    print('Case #%d (%d %d %d):' % (caseNum,rows,cols,mines))
                    for r in range(0, rows):
                        print(''.join(map(str,grid[r])))
                    output.write('Case #%d:\n' % (caseNum))
                    for r in range(0, rows):
                        output.write(''.join(map(str,grid[r])))
                        output.write('\n')
                else:
                    print('Case #%d (%d %d %d):\nImpossible' % (caseNum,rows,cols,mines))
                    output.write('Case #%d:\nImpossible\n' % (caseNum))

### END
