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
        s_max, levels = sys.stdin.readline().split()
        s_max = int(s_max)
        levels = [int(d) for d in levels]

        cases.append((s_max, levels))

    return cases


def solve(cases, efficient=True):
    for s_max, levels in cases:
        if not efficient:
            candidates = [0]
            candidates.extend((
                (i+1) - sum(levels[:i+1]) for i in range(len(levels)-1)
            ))
            yield max(candidates)
        else:
            min_invites = 0
            total = 0
            for i in range(len(levels) - 1):  # no need to check last idx
                total += levels[i]
                if total < i+1:
                    min_invites = max(min_invites, (i+1)-total)
            yield min_invites


def main():
    cases = get_input()
    answers = list(solve(cases, efficient=True))
    output(answers)

if __name__ == '__main__':
    main()
