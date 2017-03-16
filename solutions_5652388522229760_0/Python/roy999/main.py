from itertools import count


def process(input_file, out):
    t = int(input_file.readline())

    for i in range(1, t + 1):
        result = solve(int(input_file.readline().strip()))
        out.write("Case #%i: %s\n" % (i, result))


def solve(n):
    if n == 0:
        return 'INSOMNIA'
    else:
        digits = set(map(str, range(10)))
        for number in map(str, count(n, n)):
            for digit in number:
                digits.discard(digit)

            if not digits:
                return number
