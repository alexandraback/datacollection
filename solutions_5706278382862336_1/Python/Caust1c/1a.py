### Set the input and output file names
import time
import datetime
from fractions import Fraction

filename = 'A-large'
input_filename = filename + '.in'
output_filename = filename + '.out.' + datetime.datetime.fromtimestamp(time.time()).strftime('%Y%m%d-%H%M%S') + '.txt'

def factoroftwo(n):
    while n % 2 == 0:
        n = n / 2
    if n == 1:
        return True
    else:
        return False
        

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
            print("error")
        ### i.e. infoLines == False
        else:   
            for caseNum in range(1, cases+1):
                
                top = int(lines[lineNum].split('/')[0])  # case size (rows)
                bot = int(lines[lineNum].split('/')[1])  # case size (columns)
                
                frac = Fraction(top,bot)
                
                n = frac.denominator
                while n % 2 == 0:
                    n = n / 2
                if n == 1:
                    possible = True
                else:
                    possible = False
                    
                
                if possible:
                    x = 0
                    while x < 45:
                        comp = Fraction(1,2**x)
                        if comp <= frac:
                            break
                        x += 1
                    myAns = x
                    print('Case #%d: %d\n' % (caseNum, myAns))
                    output.write('Case #%d: %d\n' % (caseNum, myAns))
                        
                else:
                    ### Output myAns
                    print('Case #%d: impossible\n' % (caseNum))
                    output.write('Case #%d: impossible\n' % (caseNum))
                
                lineNum += 1

### END
