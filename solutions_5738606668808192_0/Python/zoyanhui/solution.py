import random
import math

def print_case_result(case_num, results):
    print "Case #" + str(case_num) +":"
    for result in results:
        print result[0],
        for divisor in result[1:]:
            print divisor,
        print 

def print_case_each_result(case_num, result):
    # print "Case #" + str(case_num) +":"
    # for result in results:
    print result[0],
    for divisor in result[1:]:
        print divisor,
    print 

def check_prime_random(num):
    for i in range(15):
        r = random.randint(2, int(math.sqrt(num)) + 1)
        if num % r == 0:
            return r
    return None

def check_prime(num):
    if num <= 3:
        return None
    for i in range(2, 4):
        if num % i == 0:
            return i
    i = 5
    while i*i <= num:
        if num % i == 0:
            return i
        if num % (i+2) == 0:
            return i+2
        i += 6
    return None

def fetch_num(N, checked):
    max_mid_val = pow(2, N-2) - 1    
    for r in range(max_mid_val + 1):
        yield ("1{0:{fill}"+str(N-2)+"b}1").format(r, fill='0')

def fetch_num_random(N, checked):
    max_mid_val = pow(2, N-2) - 1    
    r = random.randint(0, max_mid_val)
    while r in checked:
        r = random.randint(0, max_mid_val)
    checked.add(r)
    yield ("1{0:{fill}"+str(N-2)+"b}1").format(r, fill='0')

def fetch_all_base_nums(strnum):
    num_ser = map(int, str(strnum))
    for base in range(2, 11):
        val = 0
        for n in num_ser:
            val = val*base + n
        yield val


def find_coinjam(N, J):
    # result = []
    checked = set()
    i = 0
    for strnum in fetch_num(N, checked):     
        rets = []
        for base_num in fetch_all_base_nums(strnum):
            ret = check_prime(base_num)
            if ret is None:
                break
            rets.append(ret)
        if len(rets) == 9:
            each_result = [int(strnum)] + rets
            yield each_result
            # result.append(each_result)
            i += 1
            if i == J:
                break
    # return result


if __name__ == '__main__':
    testcase_num = int(raw_input())
    for case_num in range(1, testcase_num+1):
        N, J = map(int, raw_input().strip().split())
        # result = find_coinjam(N, J)
        print "Case #" + str(case_num) +":"
        for result in find_coinjam(N, J):            
            print_case_each_result(case_num, result)
