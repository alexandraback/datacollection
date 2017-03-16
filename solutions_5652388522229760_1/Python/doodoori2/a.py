#!/usr/bin/env python

def main():
    input_file = "./a_input.txt"
    output_file = "./a_output.txt"
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
    input_num = int(line)
    test_cnt = 1
    target_num = input_num
    target_set = set()
    last_len = 0
    while True:
        splited = set(list(str(target_num)))
        number_only = filter(lambda x: x != "" and x != "\n", splited)
        target_set = target_set.union(number_only)
        current_len = len(target_set)
        if current_len == 10:
            return target_num
        target_num += input_num
        if target_num == 0:
            return "INSOMNIA"

def print_result(case_idx,result):
    print "Case #%s: %s" % (str(case_idx), result)



if __name__ == '__main__':
    main()
