from math import *

fin = open('brattlelg.in','r')
fout = open('OUTPUTFILE.txt','w')

T = int((fin.readline()).strip())   # T is the number of test cases

for test in range(T):
    # Write the main program here for each test case
    # test = test number
    # result = the result for the test case
    
    linein = fin.readline().strip().split()
    R,C,W = int(linein[0]),int(linein[1]),int(linein[2])

    # smallcase R = 1
    result = int(C/W)*(R-1) + int((C-1)/W) + W;
    
    output_str = 'Case #' + str(test+1) + ': ' + str(result) + '\n'
    fout.write(output_str)
    
fin.close()
fout.close()
