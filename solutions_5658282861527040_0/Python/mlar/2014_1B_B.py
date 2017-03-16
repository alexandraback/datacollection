import sys
import numpy as np

def solve_case(case_num, case_data):
    result = 'Case #' + str(case_num) + ': '

    A = case_data[0]
    B = case_data[1]
    K = case_data[2]
    n = 0


    for a in range(A):
        for b in range(B):
            if a&b < K:
                n += 1

    result += str(n)
    return result


def process_file(input_file, output_file):
    file_in = open(input_file, 'rU')
    file_out = open(output_file, 'w')

    i = 0
    num_cases = None
    case_num = 0
    case_data = None

    for row in file_in:
        
        if not num_cases:
            num_cases = int(row)

        else:
            case_num += 1
            i += 1
            case_data = [int(n) for n in (row.strip()).split(' ')]
            result = solve_case(case_num, case_data)
            file_out.write(result+'\n')
        
    file_out.close()
            

def main():
    if len(sys.argv) == 3:
        print 'Program starts'
        process_file(sys.argv[1], sys.argv[2])
        sys.exit(1)
        
    else:
        print 'Give two arguments (INPUT_FILE OUTPUT_FILE)'
        sys.exit(1)


if __name__ == '__main__':
    main()
