#!/usr/bin/env python
import math

def main():
    input_file = "./c_input.txt"
    output_file = "./c_output.txt"
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
    (N, J) = line.split(" ")
    start_num = 2 ** (long(N)-1)
    end_num = start_num * 2
    answer = []
    for current_num in xrange(start_num, end_num):
        if current_num % 2 == 0:
            continue
        bi_list = []
        remain = current_num
        for n in range(long(N)):
            bi_list.append(remain % 2)
            remain /= 2
        extracted = []
        dividors = []
        dividors.append("".join([str(x) for x in bi_list[::-1]]))
        for base_num in range(2, 11):
            extract = 0
            factor = 1
            for b in bi_list:
                extract += b * factor
                factor *= base_num
            dividor = get_dividor(extract)
            if dividor == 0 or dividor == 1:
                break
            extracted.append(str(extract))
            dividors.append(str(dividor))
        if(dividors is not None and len(dividors) == 10):
            answer.append(dividors)
            i = 0
            for d in dividors:
                if i == 0:
                    i += 1
                    continue
                e = extracted[i - 1]
                q = long(extracted[i - 1]) / long(d)
                #print "Test", "i",i, "d",d, "e",e, "q",q, "re", q * long(d), long(e) == (long(q) * long(d))
                i += 1
            print "Answer", dividors
            if len(answer) == long(J):
                return answer
    return None

cached = {}
def get_dividor(target):
    if target in cached:
        return cached[target]
    if target == 0 or target == 1:
        return 0
    if target % 2 == 0 and target % 4 != 0:
        return 2
    sqrt = math.floor(math.sqrt(target))
    p = 3
    while p <= sqrt:
        if target % p == 0:
            cached[target] = long(p)
            return long(p)
        p += 2
    return 0

def print_result(case_idx,result):
    print "Case #%s:" % str(case_idx)
    for r in result:
        print " ".join(r)

if __name__ == '__main__':
    main()
