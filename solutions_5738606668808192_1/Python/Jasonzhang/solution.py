def is_prime(n):
    """Returns True if n is prime."""

    if n == 2:
        return 0
    if n == 3:
        return 0
    if n % 2 == 0:
        return 2
    if n % 3 == 0:
        return 3

    i = 5
    w = 2

    while i * i <= n:
        if n % i == 0:
            return i
        if i > 5000:
            return 0

        i += w
        w = 6 - w

    return 0


def digits(x, base):
    result = 0
    x_str = str(x)
    factor = 1
    length = len(x)
    for i in range(length):
        result += int(x[length - 1 - i]) * factor
        factor *= base
    return result


def add_1(jam):
    result = ''
    length = len(jam)
    carry = 1
    for i in range(length):
        if jam[length - 1 - i] == '0':
            result += str(carry)
            carry = 0
        else:
            if carry == 0:
                result += '1'
                carry = 0
            else:
                result += '0'
                carry = 1
    if carry == 1:
        result += '1'

    return result[::-1]


def generate_next_jam(jam):
    """
    :param jam: 1xxxxxxxxxxxxxxx1
    :return: next jam +2
    """
    return add_1(add_1(jam))


def get_coin_jam(N, J):
    result = {}
    jam_start = '1' + '0' * (N - 2) + '1'
    num = 0
    jam = jam_start
    while True:
        divisor = []
        for base in range(2, 11):
            d = is_prime(digits(jam, base))
            if d == 0:
                break
            else:
                divisor.append(d)
        if len(divisor) == 9:
            result[jam] = divisor
            # print jam
            num += 1
            if num == J:
                return result
        jam = generate_next_jam(jam)


f = open('C-large.in')
f1 = open('out.txt', 'wb')

test_case = f.readline().strip()
N_J = f.readline().strip()
N = int(N_J.split(' ')[0])
J = int(N_J.split(' ')[1])
r = get_coin_jam(N, J)

f1.write('Case #1:\n')
for key, value in r.items():
    f1.write(key)
    for d in value:
        f1.write(' ' + str(d))
    f1.write('\n')

f.close()
f1.close()
