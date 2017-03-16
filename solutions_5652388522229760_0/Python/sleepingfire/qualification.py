import sys, os

def main(n):
    if n == 0:
        return "INSOMNIA"

    digits = set()
    num = 0
    while len(digits) < 10:
        num += n
        digits |= get_digits(num)
    return num

def get_digits(n):
    if n == 0:
        return set([0])

    digits = set()
    while n > 0:
        digits.add(n % 10)
        n //= 10
    return digits


if __name__ == "__main__":
    in_path = "test.in" if len(sys.argv) == 1 else sys.argv[1]
    in_file = open(in_path, 'r')
    T = int(in_file.readline().rstrip())

    for case_idx in range(T):
        n = int(in_file.readline().rstrip())
        res = main(n)
        print("Case #{}: {}".format(case_idx + 1, res))
