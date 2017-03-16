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
        Smax = int(file_line_list[0])
        shy_string = file_line_list[1]

        shy_list = [int(num) for num in shy_string] 

        output = 0 # number added
        total = 0
        for i in range(Smax + 1):
            while total < i:
                total += 1
                output += 1
            total += shy_list[i]
           
        output_string = 'Case #' + str(case_num) + ': %d\n' % output

        output_file.write(output_string) ##
        print(output_string)
        case_num += 1
        
    output_file.close()











