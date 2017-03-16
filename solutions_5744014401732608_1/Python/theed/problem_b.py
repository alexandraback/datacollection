# pylint: disable=missing-docstring
import sys
# from collections import OrderedDict


def problem(case):
    B, M = case
    if 2 ** (B - 2) < M:
        return "IMPOSSIBLE"

    plan = "POSSIBLE"
    print(M)

    ways = [1] + [0] * (B - 1)
    for n in range(B):
        if n == 0:
            last = "1" if 2 ** (B - 2) == M else "0"
            if last == "1":
                M -= 1
        elif n == B - 1:
            last = "0"
        else:
            last = str(M % 2)
            M //= 2
            print(M)
        start = "0" * min(n + 1, B - 1)
        mid = "1" * max(0, B - (n + 2))
        building = start + mid + last
        assert len(building) == B

        for i, c in enumerate(building):
            if c == '1':
                ways[i] += ways[n]

        plan += "\n" + building
    assert ways[-1] == case[1], str(case)
    return plan


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
