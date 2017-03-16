size = 32
req = 500


def tobase(num, base):
    binstr = "{0:b}".format(num)
    res = 0
    exp = 0
    for i in range(len(binstr) - 1, -1, -1):
        if binstr[i] == '1':
            res += base**exp
        exp += 1
    return res


def divisor(n):
    if n == 2:
        return None
    if n == 3:
        return None
    if n % 2 == 0:
        return 2
    if n % 3 == 0:
        return 3

    i = 5
    w = 2

    while i * i <= n and i <= 7:
        if n % i == 0:
            return i

        i += w
        w = 6 - w

    return None


def main():
    found = 0
    print("Case #1:")
    for i in range(2**(size-1) + 1, 2**size, 2):
        divisors = []
        ok = True
        for base in range(2, 11):
            k = tobase(i, base)
            d = divisor(k)
            if d is not None:
                divisors.append(d)
            else:
                ok = False
                break
        if ok:
            print('{0:b}'.format(i), ' '.join([str(d) for d in divisors]))
            found += 1
        if found == req:
            return


if __name__ == '__main__':
    main()