#!/usr/bin/env python
import sys


# <-  N -->
# 100111101
# N J
# 2->10 non prime


def get_primes(limit):
    primes = [2]
    a = [True for i in xrange(limit)]
    a[0] = False
    a[1] = False
    current = 3
    while current < limit:
        mark_off = current ** 2
        while mark_off < limit:
            a[mark_off] = False
            mark_off += current
        primes.append(current)
        current += 2
        while current < limit and not a[current]:
            current += 2
    return primes


first_primes = get_primes(10**6)

def find_divisor(num, n_first_primes):
    for i in xrange(0, n_first_primes+1):
        if num % first_primes[i] == 0:
            return first_primes[i]


def check_divisors(base_num, n_first_primes):
    divisors = []
    for base in xrange(2,11):
        divisor = find_divisor(int(bin(base_num)[2:], base), n_first_primes)
        if not divisor:
            return None
        divisors.append(divisor)
    return divisors


def get_solution(digit_count, results_to_find, max_trials=10**6, n_first_primes=1000):
    results = []
    trial_count = 0
    max_base_num = 2**(digit_count-2)
    base_num = 0
    while len(results) < results_to_find and trial_count < max_trials and base_num < max_base_num:
        # test '1' + '11000001' + '1' - base num = middle number
        test_num = 2**(digit_count-1) + base_num * 2 + 1
        divisors = check_divisors(test_num, n_first_primes)
        if divisors:
            results.append((bin(test_num)[2:], divisors))
        trial_count += 1
        base_num +=1
    return results


def print_solution(solution_results):
    for result in solution_results:
        print '{} {}'.format(result[0], ' '.join(map(str, result[1])))


def solve_and_print(digit_count, results_to_find):
    solution_results = get_solution(digit_count, results_to_find)
    print_solution(solution_results)





if __name__ == '__main__':
    pass
    case_count = int(sys.stdin.readline())
    for i in xrange(1, case_count+1):
        print 'Case #{}:'.format(case_count)
        digit_count, results_to_find = map(int, sys.stdin.readline().strip().split())
        solve_and_print(digit_count, results_to_find)

