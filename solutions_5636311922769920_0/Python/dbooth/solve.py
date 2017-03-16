#python 2.7

import sys
import math
import string

def solve(K, C, S):
    required_checks = list()

    if (C == 1):
        required_checks = list(range(1,K+1))
    else:
        bits_to_check = K
        if (K%2) == 1:
            required_checks.append((K**C))
            bits_to_check -= 1

        check_len = K**(C-1)
        next_secondary_bit_check = 2
        next_primary_bit_check = 1
        while (bits_to_check > 0):
            required_checks.append((next_primary_bit_check-1) * check_len + next_secondary_bit_check)
            bits_to_check -= 2
            next_primary_bit_check += 2
            next_secondary_bit_check += 2
        
    if (len(required_checks) > S):
        print ("IMPOSSIBLE" + str(required_checks))
        return "IMPOSSIBLE"
    print (required_checks)
    ret_str = ""
    for check in required_checks:
        ret_str += str(check) + " "
    return ret_str.strip()

def main():
    if (not len(sys.argv) == 3):
        print("Need exactly twos args: input filename and output filename")
        return
    input_data = open(sys.argv[1], 'r').read()
    output_file = open(sys.argv[2], 'w')
    split_input = input_data.split("\n")
    case_count = int(split_input[0])
    for i in range(0,case_count):
        K, C, S = split_input[i+1].split(" ")
        res = solve(int(K), int(C), int(S))
        output_file.write("Case #" + str(i+1) + ": " + str(res) + "\n")
    
if __name__ == "__main__":
    main()
