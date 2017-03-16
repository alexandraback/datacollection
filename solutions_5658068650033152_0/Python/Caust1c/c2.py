### Set the input and output file names
import time
import datetime
import math
filename = 'C-small-attempt4'
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
            print("Error")
        ### i.e. infoLines == False
        else:   
            for caseNum in range(1, cases+1):
                
                n = int(lines[lineNum].split(' ')[0])  # N
                m = int(lines[lineNum].split(' ')[1])  # M
                k = int(lines[lineNum].split(' ')[2])  # K
                ## enforce that n < m
                if n > m:
                    x = n
                    n = m
                    m = x
                ## limits are now 1<=n<=m

                print(n,m,k)
                
                diamonds = [1,5,13,25,41,61,85,113,145,181,221,265,313,365,421,481,545,613,685,761,841,925,1013]
                diamonds_circ = [0,4,8,12,16,20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88]
                ## find largest diamond small enough
                for d in range(len(diamonds)):
                    if 2*d+1 > n:
                        #print(d,2*d+1,'#1')
                        ## too wide
                        break
                    if diamonds[d] > k:
                        #print(d,diamonds[d],'#2')
                        ## too big
                        break
                ## record the one before it broke
                d = d-1
                enclosed = diamonds[d]
                circumf = diamonds_circ[d]
                height = 2*d+1
                width = 2*d+1
                print('d=',d,'enc=',enclosed,'circ=',circumf,'h=',height)
                
                if enclosed + height <= k and width + 1 < m:
                    ## grow
                    enclosed += height
                    circumf += 2
                    width +=1
                
                                
                ##grow the diamond
                shortfall = k - enclosed
                ## cost additionals = roundup(#adds / 2)
                if d == 0:
                    myAns = circumf + shortfall
                else:
                    myAns = circumf + math.ceil(shortfall / 2)
                    if k > n*m-4:
                        myAns += (k - n*m)
                
                lineNum += 1
                
                ### Output myAns
                print('Case #%d: %d\n' % (caseNum, myAns))
                output.write('Case #%d: %d\n' % (caseNum, myAns))

                

### END
