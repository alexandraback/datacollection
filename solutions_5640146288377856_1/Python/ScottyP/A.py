import numpy as np
import math
import time


input_file_name = './A-large.in'
output_file_name = './A-large.out'
    

if __name__ == '__main__':

    input_file = open(input_file_name, 'r')
    output_file = open(output_file_name, 'w')

    # get info from input file
    file_line = input_file.readline()
    file_line = file_line.replace('\n', '')
    num_cases = int(file_line)

    case_num = 1
    while True:
        file_line = input_file.readline()
        if file_line == '' or file_line == '\n':
            input_file.close()
            break
        file_line = file_line.replace('\n', '')
        file_line_list = file_line.split()
        R = int(file_line_list[0])
        C = int(file_line_list[1])
        W = int(file_line_list[2])

        output = (C/W)*R
        if C - W*(C/W) > 0:
            output += W
        else:
            output += W - 1
        output_string = 'Case #' + str(case_num) + ': %d\n' % output

        output_file.write(output_string) ##
        print(output_string)
        case_num += 1
        
    output_file.close()











