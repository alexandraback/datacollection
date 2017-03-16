#!/usr/bin/env python

def main():
    input_file = "./b_input.txt"
    output_file = "./b_output.txt"
    input_f = open(input_file, "r")
    case_num = 0
    case_idx = 1
    while True:
        input_line = input_f.readline()
        if not input_line:
            break
        if case_num == 0:
            case_num = int(input_line)
            continue
        result = do_process(input_line)
        print_result(case_idx, result)
        case_idx += 1
    input_f.close()
    
def do_process(line):
    input_line = line
    if len(input_line) == 0:
        return 0
    reversed_line = input_line[::-1]
    last_status = "+"
    cnt = 0
    for item in reversed_line:
        if item == "" or item == "\n":
            continue
        if item == last_status:
            continue
        last_status = item
        cnt += 1
    return cnt

def print_result(case_idx,result):
    print "Case #%s: %d" % (str(case_idx), result)


if __name__ == '__main__':
    main()
