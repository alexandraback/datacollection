#10:20

def counting_sheep(N):
    if N == 0:
        return False

    exist_digits = set()
    count = 1
    while count < 10000:
        current_value = count*N
        exist_digits = exist_digits.union(set(str(current_value)))
        if(len(exist_digits) == 10):
            return current_value
        count += 1
    return False

def counting_sheep_in():
    test_case_num = int(raw_input())
    for test_case in range(1, test_case_num+1):
        last_count = counting_sheep(int(raw_input()))
        if last_count == False:
            print 'Case #%s: INSOMNIA' % test_case
        else:
            print 'Case #%s: %s' % (test_case, last_count)


def pancakes(S):
    reverse_count = 0
    last_side = S[0]
    for current_side in S[1:]:
        if last_side == current_side:
            continue
        else:
            reverse_count += 1
            last_side = current_side
    if S[-1] == '-':
        reverse_count += 1
    return reverse_count


def pancakes_in():
    test_case_num = int(raw_input())
    for test_case in range(1, test_case_num+1):
        print 'Case #%s: %s' % (test_case, pancakes(raw_input()))


import math
def find_jamcoin(N, J):
    max_trial = int(math.pow(2, N - 2))
    jamcoin_format = '0%sb'%(N - 2)
    trial = 0
    find_jam_count_count = 0
    answer = {}
    while trial < max_trial and find_jam_count_count < J:
        jamcoin = '1%s1'%format(trial, jamcoin_format)
        result = check_if_jamcoin(jamcoin)
        if result:
            answer[jamcoin] = result
            find_jam_count_count += 1
        trial += 1
    return answer


def check_if_jamcoin(jamcoin):
    divisors = []
    for base in range(2, 11):
        result, divisor = is_prime_possible(int(jamcoin, base))
        if result:
            return False
        else:
            divisors.append(divisor)
    return divisors


up_to_200_prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199]
def is_prime_possible(i):
    for divisor in up_to_200_prime:
        if i%divisor == 0:
            return False, divisor
    return True, None


def find_jamcoin_in():
    test_case_num = int(raw_input())
    for test_case in range(1, test_case_num+1):
        N_J = raw_input().split(' ')
        N = int(N_J[0])
        J = int(N_J[1])
        answer = find_jamcoin(N ,J)
        print 'Case #%s:' % test_case
        for sol in answer:
            print sol, ' '.join([str(v) for v in answer[sol]])

find_jamcoin_in()