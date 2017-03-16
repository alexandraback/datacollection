
from math import sqrt


prime_set = []


def is_prime(x):
    if x == 1: return False
    if x == 2: return True
    if x % 2 == 0: return False
    i = 3
    s = int(sqrt(x)) + 1
    while i < s:
        if x % i == 0:
            return False
        i += 2
    return True

def find_all_prime_leq(n):
    global prime_set
    prime_set = []
    i = 2
    while i <= n:
        if is_prime(i):
            prime_set.append(i)
        i += 1
    #print(len(prime_set))

def verify(bval):
    divisors = []
    base = 2
    while base <= 10:
        x = int(bval, base)
        #print("%s under base %d is %d" % (bval, base, x))

        is_prime = True
        for p in prime_set:
            if x % p == 0:
                is_prime = False
                divisors.append(p)
                #print("%d can be divided by %d under base %d" % (x, p, base))
                break

        if is_prime:
            #print("%d is a prime under base %d" % (x, base))
            return False, []
        
        base += 1

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

    find_all_prime_leq(10000)

    print("Case #%d:" % (i + 1))
    j = 0
    i = start_val
    while i < stop_val:
        # test val
        bval = bin(i)[2:]
        res, divisors = verify(bval)
        if res:
            j += 1
            if j > J:
                break
            print("%s %s" % (bval, ' '.join([str(d) for d in divisors])))
        i += 2


