import math
import sys

#def print_result (case_num,result):
#    print('Case #{}:\n{}'.format(case_num,result))

small_primes = []
MAX_PRIME = 10000000
MAX_SEARCH = 2**17
sieve = [None for i in range(MAX_PRIME+1)]

def generate_small_primes ():
    global small_primes
    global sieve
    sieve[0] = sieve[1] = 1
    for i in range(len(sieve)):
        if sieve[i] is None:
            j = 2*i
            small_primes += [i]
            while j < len(sieve):
                sieve[j] = i
                j += i

def get_witness (num):
    if num < MAX_PRIME:
        return sieve[num]
    for p in small_primes:
        if num % p == 0:
            return p
    for i in range(small_primes[-1]+2,min(MAX_SEARCH,math.ceil(num**0.5)),2):
        if num % i == 0:
            return i
    return None

generate_small_primes()

T = int(input())
for case_num in range(1,T+1):
    N,J = map(int,input().split())
    j = 0
    print('Case #{}:'.format(case_num))
    for inner_num in range(2**N-2):
        num_str = '1' + ('{:0'+str(N-2)+'b}').format(inner_num) + '1'
        witnesses = []
        for base in range(2,11):
            num = int(num_str,base)
            witness = get_witness(num)
            if witness and num % witness: print('bad witness:',num,witness,file=sys.stderr)
            if witness is None:
                break
            else:
                witnesses.append(str(witness))
        if len(witnesses) == 9:
            print(num_str+' '+' '.join(witnesses))
            j += 1
            if j == J:
                break
