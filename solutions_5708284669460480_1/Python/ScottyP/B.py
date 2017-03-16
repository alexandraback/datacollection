import numpy as np
import math
import time


input_file_name = './B-large.in'
output_file_name = './B-large.out'

    

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
        K = int(file_line_list[0])
        L = int(file_line_list[1])
        S = int(file_line_list[2])

        keyboard = input_file.readline().replace('\n', '')
        target = input_file.readline().replace('\n', '')

        # check if possible
        possible = True
        for letter in target:
            if not letter in keyboard:
                possible = False

        if possible == False:
            output = 0.0

        else:
            overlap = 0
            for i in range(1, len(target)):
                if target[:len(target) - i] == target[i:]:
                    overlap = len(target) - i
                    break
            maximum = (S - overlap)/(L - overlap)

            prob = 1.0
            for letter in target:
                prob *= float(keyboard.count(letter))/float(len(keyboard))
            expected = prob*(S-L+1)

            output = maximum - expected
                

        output_string = 'Case #' + str(case_num) + ': %0.7f\n' % output

        output_file.write(output_string) ##
        print(output_string)
        case_num += 1
        
    output_file.close()











