def print_case_result(case_num, result):
    print "Case #" + str(case_num) +": " + str(result)


def fetch_all_nums(n):
    return set(map(int, str(n)))

def is_over(number_set):
    return len(number_set) == 10

def calc_last(input_n):
    if input_n == 0:
        return "INSOMNIA"
    cur = 1
    number_set = set()
    while not is_over(number_set):
        number_set |= fetch_all_nums(cur*input_n)
        cur += 1
    return (cur-1) * input_n




if __name__ == '__main__':
    testcase_num = int(raw_input())
    for case_num in range(1, testcase_num+1):
        input_n = int(raw_input())
        result = calc_last(input_n)
        print_case_result(case_num, result)
