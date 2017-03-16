import numpy as np
import math
import time


input_file_name = './C-small-attempt0.in'
output_file_name = './C-small.out'

mult_dict = {'11': '1', '1i':'i', '1j': 'j', '1k':'k',
             'i1': 'i', 'ii':'1', 'ij': 'k', 'ik':'j',
             'j1': 'j', 'ji':'k', 'jj': '1', 'jk':'i',
             'k1': 'k', 'ki':'j', 'kj': 'i', 'kk':'1'}

sign_dict = {'11': 1, '1i':1, '1j': 1, '1k':1,
             'i1': 1, 'ii':-1, 'ij': 1, 'ik':-1,
             'j1': 1, 'ji':-1, 'jj': -1, 'jk':1,
             'k1': 1, 'ki':1, 'kj': -1, 'kk':-1}

def get_product(string_list):
    # assume length at least 1
    current_prod = string_list[0]
    current_sign = 1
    for i in range(1, len(string_list)):
        string_bit = current_prod + string_list[i]
        current_prod = mult_dict[string_bit]
        current_sign *= sign_dict[string_bit]
    if current_sign == -1:
        return '-' + current_prod
    else:
        return current_prod

def get_running_product(string_list):
    # assume length at least 1
    out_string_list = []
    current_prod = string_list[0]
    current_sign = 1
    out_string_list.append(current_prod)
    for i in range(1, len(string_list)):
        string_bit = current_prod + string_list[i]
        current_prod = mult_dict[string_bit]
        current_sign *= sign_dict[string_bit]
        if current_sign == -1:
            out_string_list.append('-' + current_prod)
        else:
            out_string_list.append(current_prod)
    return out_string_list

def get_running_product_rev(string_list):
    # string_list should be reversed before running func
    # assume length at least 1
    out_string_list = []
    current_prod = string_list[0]
    current_sign = 1
    out_string_list.append(current_prod)
    for i in range(1, len(string_list)):
        string_bit = string_list[i] + current_prod
        current_prod = mult_dict[string_bit]
        current_sign *= sign_dict[string_bit]
        if current_sign == -1:
            out_string_list.append('-' + current_prod)
        else:
            out_string_list.append(current_prod)
    return out_string_list
    
    

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
        L = int(file_line_list[0])
        X = int(file_line_list[1])

        letter_string = input_file.readline().replace('\n', '')

        repeated_letter_string = letter_string*min(X, 25)
##        print(repeated_letter_string) ##
        string_list = [letter for letter in repeated_letter_string]
##        print(string_list) ##
        string_list_rev = string_list[::-1]

        # find cycle length
        product_string_list = get_running_product(string_list)
##        print(product_string_list) ##
        product_string_list_rev = get_running_product_rev(string_list_rev)
##        print(product_string_list_rev) ##
        for test_x in range(1, min(X, 25)):
            if product_string_list[test_x*L] == product_string_list[0]:
                cycle_length = test_x*L
                break
        else:
            cycle_length = 100000000 # arbitrary large number

##        print(cycle_length) ##
        
        # find first i index
        for letter_i, letter in enumerate(product_string_list):
            if letter == 'i':
                i_index = letter_i
                break
        else:
##            print('test1') ##
            possible = False

##        print(i_index) ##

        # find first k index
        for letter_i, letter in enumerate(product_string_list_rev):
            if letter == 'k':
                k_index = X*L - letter_i - 1
                break
        else:
##            print('test2') ##
            possible = False

##        print(k_index) ##


        if k_index - 1 <= i_index:
##            print('test3') ##
            possible = False

        # test for j
        if possible == True:
            j_length = (k_index - i_index - 1) % cycle_length
##            print(string_list[(i_index + 1):(i_index + 1 + j_length)]) ##
##            print(get_product(string_list[(i_index + 1):(i_index + 1 + j_length)])) ##
            if get_product(string_list[(i_index + 1):(i_index + 1 + j_length)]) == 'j':
                possible = True
            else:
                possible = False

        if possible == True:
            output = 'YES'
        else:
            output = 'NO'
        output_string = 'Case #' + str(case_num) + ': %s\n' % output

        output_file.write(output_string) ##
        print(output_string)
        case_num += 1
        
    output_file.close()











