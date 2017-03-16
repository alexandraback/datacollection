import sys


def seek_divisor(n):
    if n < 2:
        return None
    if n == 2:
        return None
    if n % 2 == 0:
        return 2
    i = 3
    while i * i <= n:
        if n % i == 0:
            return i
        i += 2
    return None


def jam_form(x, l):
    base = str(bin(x))[2:]
    if len(base) < l:
        base = '0' * (l - len(base)) + base

    return '1' + base + '1'


def solve_case(n, j, case_number):
    count = 0
    l = n - 2
    print("Case #%d:" % case_number)

    for i in range(0, pow(2, l)):
        coin = jam_form(i, l)
        result = [coin]
        for base in range(2, 11):
            divisor = seek_divisor(int(coin, base))
            result.append(str(divisor))
            if divisor is None:
                break
        else:
            count += 1
            print(" ".join(result))
            if count >= j:
                break


def main():
    r = sys.stdin

    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        nj = [int(x) for x in r.readline().strip().split(' ')]

        solve_case(nj[0], nj[1], case_number)


if __name__ == '__main__':
    main()
