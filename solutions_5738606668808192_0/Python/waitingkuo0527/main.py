import math

import math
primes = [2] 
N = 10000
for num in range(3,int(math.sqrt(N)),2):
    if all(num%i!=0 for i in range(2,int(math.sqrt(num))+1)):
        primes.append(num)

def _convert(s, base):
    result = 0
    cur = 1
    for ch in reversed(s):
        if ch == '1':
            result += cur
        cur *= base

    return result

def convert(N, i, base):
    return _convert(bin(i)[2:], base) * base + base ** (N-1) + 1

def to_bin(N, x):

    x = bin(x)[2:]
    if len(x) < N - 2:
        x = ''.join('0' for _ in range(N-2-len(x))) + x

    return '1%s1' % x

def solve(N, J):
    """ solve the problem """

    j = 0
    for i in range(2**(N-2)):
        all_found = True
        factors = []
        for base in range(2, 11):
            num = convert(N, i, base)
            #print (i, '1'+bin(i)[2:]+'1', base, num)

            found = False
            for p in primes:
                if num % p == 0:
                    found = True
                    factors.append(p)
                    break

            if not found: 
                all_found = False
                break

        if all_found:
            print(to_bin(N, i), ' '.join(str(s) for s in factors))
            j += 1
            if j == J: break
        

def parse():
    """ parse input """

    N, J = [int(i) for i in input().split()]

    return N, J


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        print('Case #%d:' % t)
        solve(*params)


if __name__ == '__main__':

    main()
