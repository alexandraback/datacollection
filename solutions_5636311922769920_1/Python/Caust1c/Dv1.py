### Set the input and output file names
import time
import datetime
filename = 'D-large'
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
            print('skipped')
        ### i.e. infoLines == False
        else:   
            for caseNum in range(1, cases+1):
                case_K = int(lines[lineNum].split(' ')[0])  #length of original seq
                case_C = int(lines[lineNum].split(' ')[1])  #complexity level
                case_S = int(lines[lineNum].split(' ')[2])  #number of tiles cleanable
                
                ### Do the Work!
                ### TODO! 
                if case_K > case_C * case_S:
                    print('Case #%d: IMPOSSIBLE' % (caseNum))
                    output.write('Case #%d: IMPOSSIBLE\n' % (caseNum))
                else:
                    count_S = 1
                    myAns = [1] * case_S
                    n = 0
                    filled = False
                    
                    while count_S <= case_S and not filled:
                        count_C = 1
                        if count_S == 1:
                            myAns[count_S-1] = n + 1
                        while count_C <= case_C:
                            myAns[count_S-1] = myAns[count_S-1] + (n) * case_K**(count_C-1)
                            #print('L=%d  case_C=%d   count_C=%d   n=%d   count_S=%d  myAns=%d' % (lineNum, case_C, count_C, n, count_S, myAns[count_S-1]))
                            n += 1
                            count_C += 1
                        
                        #test for over the limit
                        if myAns[count_S-1] > case_K**case_C:
                            filled = True
                            #replace the overflowed item with an appropriate replacement
                            while myAns[count_S-1] > case_K**case_C:
                                myAns[count_S-1] = myAns[count_S-1] - case_K**(count_C-1)
                            #chop the list
                            myAns = myAns[:count_S]
                            
                        count_S += 1

                    print('Case #%d: %s' % (caseNum, " ".join(str(x) for x in myAns)))
                    output.write('Case #%d: %s\n' % (caseNum, " ".join(str(x) for x in myAns)))
                
                
                lineNum += 1
                

### END
