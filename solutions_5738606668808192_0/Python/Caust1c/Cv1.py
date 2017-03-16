### Set the input and output file names
import time
import datetime
filename = 'c-mybig'
input_filename = filename + '.in'
output_filename = filename + '.out.' + datetime.datetime.fromtimestamp(time.time()).strftime('%Y%m%d-%H%M%S') + '.txt'

"""
### divisor function modified from
### http://stackoverflow.com/questions/9076336/how-do-you-implement-the-divisor-function-in-code
def two2ten_factors(n):
    #input is a base10 int
    output = [1,0,0,0,0,0,0,0,0,0,0]
    for base in range(0,11):
        rebasedN = int(str(n),base)
        sqroot,t = int(rebasedN**0.5),0
        found = 0
        for factor in range(2,sqroot+1):
           if rebasedN % factor == 0:
               found = factor
               break
        if found == 0:
            dud = True
            break
        else:
            dud = False
            output[base] = found
        #print('base %d, rebasedN %d,  factor %d' % (base,rebasedN,found))
    if dud:
        output[0] = 0
    return output
"""

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
                
                ### Do the Work!
                ### TODO!
                varN = int(lines[lineNum].split(' ')[0])
                varJ = int(lines[lineNum].split(' ')[1])

                N = 2**(varN-1) + 1 +2 ### initialise search
                maxN = 2**varN
                Nfound = 0

                #WRITE!!!
                output.write('Case #%d:\n' % (caseNum))
                               
                while (Nfound < varJ) and (N < maxN):
                        
                    #FIND IT
                    #input is a base10 int
                    out = [0,0,0,0,0,0,0,0,0]
                    base = 2
                    dud = False
                    while (not dud) and base <= 10:
                        rebasedN = int(str(int(bin(N)[2:])),base)
                        sqroot,t = int(rebasedN**0.5),0
                        found = 0
                        if rebasedN % 2 == 0:
                            found = 2
                        else:
                            factor = 3
                            while (found == 0) and factor <= sqroot+1:
                                if rebasedN % factor == 0:
                                    found = factor
                                factor = factor + 2
                        if found == 0:
                            dud = True
                        else:
                            dud = False
                            out[base-2] = found
                        base = base + 1
                    if not dud:
                        print('N: %d,   varN: %d, varJ: %d, MaxN: %d' % (N,varN,varJ,maxN))
                        print('%d %d %d %d %d %d %d %d %d %d' % (int(bin(N)[2:]),out[0],out[1],out[2],out[3],out[4],out[5],out[6],out[7],out[8]))
                        output.write('%d %d %d %d %d %d %d %d %d %d\n' % (int(bin(N)[2:]),out[0],out[1],out[2],out[3],out[4],out[5],out[6],out[7],out[8]))
                        Nfound = Nfound + 1
                    N = N + 2
                
                lineNum += 1
                
### END
