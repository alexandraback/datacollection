### Set the input and output file names
import time
import datetime
filename = 'B-large'
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
                ### TODO!
                pancakes = str(lines[lineNum])
                pile_size = len(pancakes)  ### note for array ref needs -1 because array starts from 0

                flips = 0
                for i in range(0, pile_size - 1):
                    ### print('pile size is %d, i is %s, i+1 is %s' % (pile_size,pancakes[i],pancakes[i+1]))
                    if pancakes[i] != pancakes[i+1]:
                        flips = flips + 1
                if pancakes[pile_size - 1] != '+':
                    flips = flips + 1
                    
                myAns = flips
                lineNum += 1
                
                ### Output myAns
                print('Case #%d: %d\n' % (caseNum, myAns))
                output.write('Case #%d: %d\n' % (caseNum, myAns))

                

### END
