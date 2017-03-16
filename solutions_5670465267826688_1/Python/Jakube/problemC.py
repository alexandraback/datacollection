from math import ceil

def read_number(f):
    return int(f.readline().strip())


def read_list(f):
    return map(int, f.readline().split())


def sign(x): return 1 if x > 0 else -1


def calc(inp1, inp2):
    table = {(1, 1): 1, (1, 2): 2, (1, 3): 3, (1, 4): 4,
             (2, 1): 2, (2, 2): -1, (2, 3): 4, (2, 4): -3,
             (3, 1): 3, (3, 2): -4, (3, 3): -1, (3, 4): 2,
             (4, 1): 4, (4, 2): 3, (4, 3): -2, (4, 4): -1}

    return table[(abs(inp1), abs(inp2))] * sign(inp1 * inp2)


def reduce(inp_list):
    current = 1
    for value in inp_list:
        current = calc(current, value)
    return current


def string_to_list(string, times=1):
    return ['ijk'.index(v) + 2 for v in string] * times


def func(inp, X):
    if X <= 4:
        inp_list = string_to_list(inp, X)
    else:
        inp_list = string_to_list(inp, 4)

    current = 1
    while inp_list:
        value = inp_list.pop(0)
        current = calc(current, value)
        if current == 2:  # we found i
            break
    else:
        return "NO"

    if X > 4:
        inp_list += string_to_list(inp, min(4, X - 4))

    current = 1
    while inp_list:
        value = inp_list.pop(0)
        current = calc(current, value)
        if current == 3:  # we found j
            break
    else:
        return "NO"

    if X > 8:
        l = string_to_list(inp)
        value = reduce(l)
        inp_list += [value] * (X % 4)

    current = 1
    while inp_list:
        value = inp_list.pop(0)
        current = calc(current, value)
    if current == 4:  # rest is k
        return "YES"
    else:
        return "NO"


def main():
    with open('C-large.in', 'r') as f:
        test_cases = read_number(f)

        for test_case in range(test_cases):
            L, X = read_list(f)
            inp = f.readline().strip()
            output = func(inp, X)
            print('Case #{}: {}'.format(test_case + 1, output))

if __name__ == '__main__':
    main()
