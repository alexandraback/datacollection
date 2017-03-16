digits = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

def reduce_count(count, dig, C):
    count[dig] = count.get(dig, 0) - C

def do_digit(count, letter, digit, mul=1):
    C = count.get(letter, 0) / mul

    for d in digits[digit]:
        reduce_count(count, d, C)

    return [str(digit) for i in xrange(C)]


def solve(S):
    count = {}

    for s in S:
        count[s] = count.get(s, 0) + 1

    res = []

    res += do_digit(count, 'Z', 0)
    res += do_digit(count, 'X', 6)
    res += do_digit(count, 'S', 7)
    res += do_digit(count, 'U', 4)
    res += do_digit(count, 'F', 5)
    res += do_digit(count, 'W', 2)
    res += do_digit(count, 'O', 1)
    res += do_digit(count, 'N', 9, 2)
    res += do_digit(count, 'I', 8)
    res += do_digit(count, 'T', 3)

    for k, v in count.items():
        assert v == 0

    return ''.join(sorted(res))


T = int(raw_input())

for i in xrange(T):
    print 'Case #%d: %s' % (i + 1, solve(raw_input()))
