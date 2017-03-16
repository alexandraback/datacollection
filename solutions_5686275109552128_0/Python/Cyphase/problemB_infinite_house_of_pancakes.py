import sys


def output(answers):
    case_num = 1
    for a in answers:
        print 'Case #%d: %s' % (case_num, a)
        case_num += 1


def get_input():
    num_cases = int(sys.stdin.readline())
    cases = []

    for case in range(num_cases):
        num_diners = int(sys.stdin.readline())
        stacks = [int(i) for i in sys.stdin.readline().split()]

        cases.append((num_diners, stacks))

    return cases


def memoize(func):
    def wrapper(x, m={}):
        tx = tuple(x)
        if tx not in m:
            m[tx] = func(x)
        return m[tx]
    return wrapper


@memoize
def recurse(stacks):
    """Assumes stacks is pre-sorted in reverse order; large to small."""
    min_minutes = stacks[0]

    if min_minutes in (3, 2, 1):
        return min_minutes
    else:
        next_min = min_minutes
        for idx in range(1, stacks[0]//2 + 1):  # idx to split on
            new_stacks = stacks[:]
            new_stacks[0] = new_stacks[0] - idx
            new_stacks.append(idx)
            new_stacks.sort(reverse=True)

            next_min = min(next_min, recurse(new_stacks)+1)

        return min(min_minutes, next_min)


def solve(cases):
    for num_diners, stacks in cases:
        stacks.sort(reverse=True)
        yield recurse(stacks)


def main():
    cases = get_input()
    answers = solve(cases)
    output(answers)

if __name__ == '__main__':
    main()
