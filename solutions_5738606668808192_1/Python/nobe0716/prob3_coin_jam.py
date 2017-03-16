import math
f_in = open('1.in')
f_out = open("1.out", "w")

prime_set = set()

for i in range(2, 10000):
    is_prime = True
    for j in range(2, int(math.sqrt(i)) + 1):
        if i % j == 0:
            is_prime = False
            break
    if is_prime:
        prime_set.add(i)


def get_divisor(num, base):
    for i in prime_set:
        if num % i == 0:
            return i
    return num


def to_base(_s, base):
    _s = _s[::-1]
    l = len(_s)
    r = 0
    for i in range(l):
        r += int(_s[i]) * pow(base, i)
    return r


def is_jam_coin(coin_str):
    if coin_str[0] != '1' or coin_str[len(coin_str) - 1] != '1':
        return [False, []]

    divisors = []
    is_prime = False
    for base in range(2, 11):
        val = to_base(coin_str, base)
        divisor = get_divisor(val, base)
        if val == divisor:
            is_prime = True
            break
        divisors.append(divisor)

    return [not is_prime, divisors]

for t in range(1, int(f_in.readline()) + 1):
    n, j = [int(x) for x in f_in.readline().strip().split()]
    c = 0
    print("Case #%d:" % t)
    f_out.write("Case #%d:\n" % t)
    for v in range(pow(2, n - 1), pow(2, n)):
        s = bin(v)[2:]

        coin_info = is_jam_coin(s)
        if coin_info[0]:
            # print(s)
            # print(coin_info[1])
            c += 1
            print("%s %s" % (s, " ".join(map(str, coin_info[1]))))
            f_out.write("%s %s\n" % (s, " ".join(map(str, coin_info[1]))))

        if c == j:
            break
f_out.close()

