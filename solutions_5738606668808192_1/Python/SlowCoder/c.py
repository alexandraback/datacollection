
import math


def divisor(number):

    # j = int(math.sqrt(number))
    j = 1048576

    for i in range(2, j + 1):
        if number % i == 0:
            return i

    return 1


def jc(num_str):

    if num_str[0] != '1' or num_str[len(num_str) - 1] != '1':
        return None

    divisors = []

    for b in range(2, 11):
        num = int(num_str, b)
        d = divisor(num)
        if d == 1:
            return None
        else:
            divisors.append(d)

    return divisors


def gen():

    count = 0

    for n in range(2147483649, 4294967296):
        n_bin = bin(n)[2:]
        divisors = jc(n_bin)

        if divisors is not None:
            print(str(n_bin) + ' ' + ' '.join([str(x) for x in divisors]))

            count += 1
            if (count >= 500):
                return

gen()
