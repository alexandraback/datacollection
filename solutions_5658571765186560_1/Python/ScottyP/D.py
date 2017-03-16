import numpy as np
import math
import time


input_file_name = './D-large.in'
output_file_name = './D-large.out'
    

if __name__ == '__main__':

    input_file = open(input_file_name, 'r')
    output_file = open(output_file_name, 'w')

    # get info from input file
    file_line = input_file.readline()
    file_line = file_line.replace('\n', '')
    num_cases = int(file_line)

    case_num = 1
    while True:
        possible = True
        file_line = input_file.readline()
        if file_line == '' or file_line == '\n':
            input_file.close()
            break
        file_line = file_line.replace('\n', '')
        file_line_list = file_line.split()
        X = int(file_line_list[0])
        R = int(file_line_list[1])
        C = int(file_line_list[2])

        #make it so R < C
        min_R_C = min(R, C)
        max_R_C = max(R, C)
        R = min_R_C
        C = max_R_C

        if X > C:
##            print('test 1') ##
            possible = False
        elif ((R*C) % X) != 0:
##            print('test 2') ##
            possible = False
        elif X >= 7:
##            print('test 3') ##
            possible = False
        elif ((X + 1)/2) > R:
##            print('test 4') ##
            possible = False
        elif R == 3 and X == 6:
            possible = False
        elif R == 2 and X == 4:
            possible = False
            
        if possible == True:
            output = 'GABRIEL'
        else:
            output = 'RICHARD'
        output_string = 'Case #' + str(case_num) + ': %s\n' % output

        output_file.write(output_string) ##
        print(output_string)
        case_num += 1
        
    output_file.close()











