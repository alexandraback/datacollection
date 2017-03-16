
from math import sqrt


def is_prime(val):
    if val == 1: return False
    if val % 2 == 0: return False
    for d in range(3, int(sqrt(val)) + 1, 2):
        if val % d == 0:
            return False
    return True

def verify(val):
    #print(bin(val)[2:])
    divisors = []
    for base in range(2, 11):
        x = int(bin(val)[2:], base)
        #print(x)

        is_prime = True
        for d in range(2, int(sqrt(x)) + 1):
            if x % d == 0:
                #print(d)
                divisors.append(d)
                is_prime = False
                break
        if is_prime:
            return False, []
    return True, divisors


T = raw_input()
T = int(T)

for i in range(T):
    line = raw_input()
    N, J = line.split()
    N = int(N)
    J = int(J)

    start_val = 2 ** (N - 1) + 1
    stop_val = 2 ** N

    print("Case #%d:" % (i + 1))
    j = 0
    for val in range(start_val, stop_val, 2):
        # test val
        res, divisors = verify(val)
        if res:
            j += 1
            if j > J:
                break
            print("%s %s" % (bin(val)[2:], ' '.join([str(d) for d in divisors])))


