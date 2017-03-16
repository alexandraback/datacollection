import sys


def solve_case(lines, case_number):
    soldiers = []
    for line in lines:
        soldiers.extend(line)

    uniq_soldiers = set(soldiers)
    lost_soldiers = []
    for soldier in uniq_soldiers:
        count = soldiers.count(soldier)
        if count % 2 == 1:
            lost_soldiers.append(soldier)
    lost_soldiers.sort()

    print("Case #%d: %s" % (case_number, " ".join([str(s) for s in lost_soldiers])))


def main():
    r = sys.stdin

    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        n = int(r.readline().strip())
        lines = []
        for c in range(0, n * 2 - 1):
            lines.append([int(x) for x in r.readline().strip().split(' ')])

        solve_case(lines, case_number)


if __name__ == '__main__':
    main()
