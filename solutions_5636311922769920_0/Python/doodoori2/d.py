#!/usr/bin/env python
import math

def main():
    input_file = "./d_input.txt"
    output_file = "./d_output.txt"
    input_f = open(input_file, "r")
    case_num = 0
    case_idx = 1
    while True:
        input_line = input_f.readline()
        if not input_line:
            break
        if case_num == 0:
            case_num = long(input_line)
            continue
        result = do_process(input_line)
        if result is None:
            continue
        print_result(case_idx, result)
        case_idx += 1
    input_f.close()

def do_process(line):
    if len(line) == 0:
        return
    (K, C, S) = line.split(" ")
    K = int(K)
    C = int(C)
    S = int(S)
    minS = int(math.ceil(K/float(C)))
    if S < minS:
        return "IMPOSSIBLE"
    answerList = []
    for s in range(minS):
        cList = [(x + s*C) if x + s*C < K else K-1 for x in range(C)]
        ci = C - 1
        s_now = 0
        debug_str = ""
        for c_step in cList:
            s_now +=  c_step * (K ** ci)
            ci -= 1
        s_now += 1
        answerList.append(str(s_now))
    return " ".join(answerList)

def print_result(case_idx,result):
    print "Case #%s: %s" % (str(case_idx), result)

if __name__ == '__main__':
    main()
