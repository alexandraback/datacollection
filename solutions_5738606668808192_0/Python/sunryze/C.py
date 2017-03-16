'''
Created on 09.04.2016

@author: dw

Uses isprime from
http://stackoverflow.com/questions/1801391/what-is-the-best-algorithm-for-checking-if-a-number-is-prime

'''
import sys
      
def bitstream(n):
    for i in range(2**n):
        yield '{:b}'.format(i).rjust(n, '0')
 
def isprime(n):
    """Returns True if n is prime."""
    if n % 3 == 0:
        return (False, 3)

    i = 5
    w = 2

    while i * i <= n:
        if n % i == 0:
            return (False, i)

        i += w
        w = 6 - w

    return (True, None)

def factorize(ds):
    result = [0] * len(ds)
    for i, d in enumerate(ds):
        prm, f = isprime(d) 
        if prm:
            return None
        result[i] = f 
    return result


def process_case(N, J):
    result = [None] * J
    cnt = 0
    for m in bitstream(N-2):
        b = '1' + m + '1'
        ds = [int(b, base) for base in range(2, 11)]
        factors = factorize(ds)
        if factors:
            result[cnt] = [b] + factors
            cnt += 1
            if cnt == J:
                break
    return result

if __name__ == '__main__':
    N = int(sys.argv[1])
    J = int(sys.argv[2])
    print("Case #1:")
    for s in process_case(N, J):
        print(' '.join(str(n) for n in s))
    