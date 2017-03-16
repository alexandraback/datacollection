import numpy as np
import math
import time


input_file_name = './B-large.in'
output_file_name = './B-large.out'
    

def possible(pancake_array, m):
    # is it possible to do pancake_list in m minutes?
    for n in range(1, m + 1):
        total_cuts = 0
        total_cut_array = (pancake_array - 1)/n
        total_cuts = np.sum(total_cut_array)
        if total_cuts + n <= m:
            return True
    

##def num_minutes(pancake_list):
##    # assumes pancake_list sorted
##    if pancake_list[-1] == 1:
##        return 1
##    if len(pancake_list) >= int(pancake_list[-1]/2):
##        if pancake_list[-1*int(pancake_list[-1]/2)] == pancake_list[-1]:
##            return pancake_list[-1]
##    new_pancake_list = pancake_list[:-1]
##    old_max = pancake_list[-1]
##    new_pancake_list.append(int(old_max/2))
##    new_pancake_list.append(old_max - int(old_max/2))
##    new_pancake_list.sort()
##    print(new_pancake_list)
##    return min(old_max, 1 + num_minutes(new_pancake_list))

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
        D = int(file_line_list[0])

        file_line = input_file.readline()
        file_line = file_line.replace('\n', '')
        pancake_list = map(int, file_line.split())
        pancake_array = np.array(pancake_list)
##        pancake_list.sort()
##
##        print(pancake_list)
##        output = num_minutes(pancake_list)
        output = 1
        while True:
            if possible(pancake_array, output):
                break
            output += 1
            
        output_string = 'Case #' + str(case_num) + ': %d\n' % output

        output_file.write(output_string) ##
        print(output_string)
        case_num += 1
        
    output_file.close()











