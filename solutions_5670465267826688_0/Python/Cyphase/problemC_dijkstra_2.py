import sys

def output(answers):
    case_num = 1
    for a in answers:
        print 'Case #%d: %s' % (case_num, a)
        case_num += 1


def get_input():
    num_cases = int(sys.stdin.readline())

    for case in range(num_cases):
        substr_len, repeat = (int(i) for i in sys.stdin.readline().split())
        substr = sys.stdin.readline().strip()

        yield (substr_len, repeat, substr)

quat_mul_table = {
    '1': {
        '1': (1, '1'),
        'i': (1, 'i'),
        'j': (1, 'j'),
        'k': (1, 'k')
    },
    'i': {
        '1': (1, 'i'),
        'i': (-1, '1'),
        'j': (1, 'k'),
        'k': (-1, 'j')
    },
    'j': {
        '1': (1, 'j'),
        'i': (-1, 'k'),
        'j': (-1, '1'),
        'k': (1, 'i')
    },
    'k': {
        '1': (1, 'k'),
        'i': (1, 'j'),
        'j': (-1, 'i'),
        'k': (-1, '1')
    }
}

def quat_mul(tu, l):
    sign, sym = quat_mul_table[tu[1]][l]
    return tu[0] * sign, sym


def solve_helper(substr_len, substr, idx, multiplier, quat):
    cur = (1, '1')
    while idx < multiplier * substr_len:
        cur = quat_mul(cur, substr[idx % substr_len])
        idx += 1
        if cur == quat:
            break

    return idx

def solve(cases):
    for substr_len, repeat, substr in cases:
        idx = 0
        idx = solve_helper(substr_len, substr, idx, 4, (+1, 'i'))
        if 4 * substr_len == idx:
            yield 'NO'
        else:
            idx = solve_helper(substr_len, substr, idx, 8, (+1, 'j'))
            if 8 * substr_len == idx:
                yield 'NO'
            else:
                idx = solve_helper(substr_len, substr, idx, 12, (+1, 'k'))
                if 12 * substr_len == idx:
                    yield 'NO'
                elif repeat <= (idx - 1) // substr_len:
                    yield 'NO'
                else:
                    cur = (1, '1')
                    remaining = (repeat - 1 - (idx - 1) // substr_len) % 4
                    while idx % substr_len != 0:
                        cur = quat_mul(cur, substr[idx % substr_len])
                        idx += 1
                    for i in range(remaining * substr_len):
                        cur = quat_mul(cur, substr[idx % substr_len])
                        idx += 1
                    if cur == (+1, '1'):
                        yield 'YES'
                    else:
                        yield 'NO'


def main():
    cases = get_input()
    answers = solve(cases)
    output(answers)

if __name__ == '__main__':
    main()
