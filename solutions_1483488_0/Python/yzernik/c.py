import sys
import string

def solve_c(infile, outfile):
    f = open(infile, 'r')
    r = open(outfile, 'w')
    num_cases = int(f.readline())
    for case_index in range(num_cases):
        line = str(f.readline().rstrip('\n'))
        A, B = get_inputs(line)
        case_answer = num_recycles(A, B)
        r.write("Case #" + str(case_index+1) + ": " + str(case_answer) + "\n")

def num_recycles(x, y):
    count = 0
    x_array, y_array = convert_array_int(x), convert_array_int(y)
    for i in range(x, y+1):
        i_array = convert_array_int(i)
        m = {}
        for shift in range(1, len(i_array)):
            shifted_i_array = i_array[shift:] + i_array[:shift]
            if compare_array_ints(shifted_i_array, i_array) < 0:
                if compare_array_ints(shifted_i_array, x_array) >= 0:
                    prev_cycle = int(''.join([str(n) for n in shifted_i_array]))
                    if prev_cycle not in m:
                        m[prev_cycle] = 1
                        count += 1
    return count


def compare_array_ints(x_array, y_array):
    for i in range(len(x_array)):
        if x_array[i] > y_array[i]:
            return 1
        elif x_array[i] < y_array[i]:
            return -1
    return 0

def convert_array_int(n):
    return [int(c) for c in list(str(n))]

def get_inputs(text):
    e = text.split(' ')
    return int(e[0]), int(e[1])


if __name__ == '__main__':
    infile = str(sys.argv[1])
    outfile = str(sys.argv[2])
    solve_c(infile, outfile)
