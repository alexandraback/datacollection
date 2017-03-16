import sys


def count_possible_fake(l):
    l.sort()
    count = 0
    prev = None
    for w in l:
        if w == prev:
            count += 1
        prev = w
    return count


def solve_case(fs, ss, case_number):
    ufs = set()
    uss = set()

    remove_idxs = []
    for idx, both in enumerate(zip(fs, ss)):
        f = both[0]
        s = both[1]
        if fs.count(f) == 1 or ss.count(s) == 1:
            ufs.add(f)
            uss.add(s)
            remove_idxs.append(idx)

    remove_idxs.sort(reverse=True)
    for idx in remove_idxs:
        fs.pop(idx)
        ss.pop(idx)

    fs.extend(list(ufs))
    ss.extend(list(uss))
    print("Case #%d: %d" % (case_number, min(count_possible_fake(fs), count_possible_fake(ss))))


def main():
    r = sys.stdin

    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        n = int(r.readline().strip())
        fs = []
        ss = []
        for i in range(0, n):
            both = r.readline().strip().split(' ')
            fs.append(both[0])
            ss.append(both[1])

        solve_case(fs, ss, case_number)


if __name__ == '__main__':
    main()
