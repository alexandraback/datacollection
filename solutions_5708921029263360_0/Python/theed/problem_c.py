# pylint: disable=missing-docstring
import sys
from collections import defaultdict


def problem(case):
    jp_map = defaultdict(int)
    js_map = defaultdict(int)
    ps_map = defaultdict(int)
    three_map = defaultdict(int)
    J, P, S, K = case

    sol = []
    while True:
        best = -1
        min_vb = 100000000000000
        for j in range(1, J + 1):
            for p in range(1, P + 1):
                for s in range(1, S + 1):
                    if three_map[(j, p, s)] == 1:
                        continue
                    min_v = max(jp_map[(j, p)], js_map[(j, s)], ps_map[(p, s)])
                    if min_v >= K:
                        continue
                    if min_v < min_vb:
                        best = (j, p, s)
                        min_vb = min_v
        if best == -1:
            break
        sol.append(best)
        three_map[best] = 1
        jp_map[(best[0], best[1])] += 1
        js_map[(best[0], best[2])] += 1
        ps_map[(best[1], best[2])] += 1

    assert len(sol) <= J * P * S, "{} {} {} {}".format(len(sol), J, P, S)
    sol = ["{} {} {}".format(*x) for x in sol]
    return str(len(sol)) + "\n" + '\n'.join(sol)


def main():
    name = sys.argv[1]
    with open(name, 'r') as input_file:
        content = input_file.read()
    lines = content.splitlines()
    num = lines[0]
    result = ''
    for run in range(int(num)):
        case = lines[1 + run].split(" ")
        case = [int(x) for x in case]
        result += 'Case #{}: {}\n'.format(1 + run, problem(case))
    with open(name.replace('in', 'sol'), 'w') as result_file:
        result_file.write(result)


def test():
    cases = {

    }
    for inp, expected in cases.items():
        actual = problem(inp)
        assert actual == expected, 'Got {}, expected {} on {}'.format(
            actual, expected, inp)


if __name__ == '__main__':
    main()
