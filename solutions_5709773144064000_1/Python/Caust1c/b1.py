import decimal
from decimal import Decimal

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
        
        #infoLines = True                        # Toggle according to question
        infoLines = False                       # Toggle according to question
        
        ### i.e. infoLines == True
        if infoLines:
            print('unused')
        ### i.e. infoLines == False
        else:   
            for caseNum in range(1, cases+1):
                
                ### Do the Work!
                ### TODO! 
                FarmCost = Decimal(lines[lineNum].split(' ')[0])  # C
                FarmRate = Decimal(lines[lineNum].split(' ')[1])  # F
                Target = Decimal(lines[lineNum].split(' ')[2])    # X
                Rate = Decimal(2.0)
                Time = Decimal(0.0)
                CookiesInPockets = Decimal(0)
                unsolved = True

                print('Case #%d: FarmCost %f, FarmRate %f, Target %f' % (caseNum, FarmCost, FarmRate, Target))
                
                while unsolved:
                    lazyTimeRemaining = (Target - CookiesInPockets) / Rate
                    
                    # If we can be done before we save up for a farm let's just get it over with
                    if FarmCost > Target:
                        Time += lazyTimeRemaining
                        unsolved = False

                    # Can we afford a farm?
                    # --Yes we can
                    else:
                        if FarmCost <= CookiesInPockets:
                            # So would we want to buy a farm at all?
                            if lazyTimeRemaining > (Target - (CookiesInPockets - FarmCost)) / (Rate + FarmRate):
                                # buy a farm!
                                Rate += FarmRate
                                CookiesInPockets += -FarmCost

                            else:
                                # guess we should just win it then
                                Time += lazyTimeRemaining
                                unsolved = False
                        # --No we can not
                        else:
                            # wait til we can afford a farm
                            Time += (FarmCost - CookiesInPockets)/Rate
                            CookiesInPockets = FarmCost
                        
                lineNum += 1

                ### Output myAns
                print('Case #%d: %.9f' % (caseNum, Time))
                output.write('Case #%d: %.9f\n' % (caseNum, Time))

                

### END
