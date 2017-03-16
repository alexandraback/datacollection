attempt_list = ['C-test','C-small-attempt0','C-large']
attempt = attempt_list[1]

import time
time.clock()


def check_if_maybe_prime(x):
    for i in [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73]:
        if x%i == 0:
            return [False, i]
    return [True, 0]

def solve(n, j):
    min_jamcoin = int(str(10**(n-1)+1), 2)
    max_jamcoin = int(str('1'*n),2)
    jamcoins_found = 0
    result = ''
    for i in range(min_jamcoin, max_jamcoin+1, 2):
        jamcoin_item = bin(i)[2:]
        for base_num in range(2, 11):
            num_in_base = int(bin(i)[2:], base_num)
            is_maybe_prime, divisor = check_if_maybe_prime(num_in_base)
            if is_maybe_prime == True:
                break
            jamcoin_item += ' ' + str(divisor)
        if is_maybe_prime == False:
            result += jamcoin_item +'\n'
            jamcoins_found += 1
            if jamcoins_found == j:
                return result


def main():
    fin = open(attempt + '.in', 'r')
    fout = open(attempt + '.out','w')

    numcases = int(fin.readline())

    for casenum in range(1,numcases+1):
        n, j = map(int, fin.readline().split())
        fout.write('Case #' + repr(casenum) + ': \n' + str(solve(n, j)) + '\n')

    fin.close()
    fout.close()

main()
print(time.clock())