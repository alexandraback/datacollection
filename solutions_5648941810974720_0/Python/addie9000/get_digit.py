import sys


def solve_case(s, case_number):
    slist = list(s)
    digit = []
    while 'Z' in slist:
        digit.append(0)
        slist.remove('Z')
        slist.remove('E')
        slist.remove('R')
        slist.remove('O')
    while 'W' in slist:
        digit.append(2)
        slist.remove('T')
        slist.remove('W')
        slist.remove('O')
    while 'U' in slist:
        digit.append(4)
        slist.remove('F')
        slist.remove('O')
        slist.remove('U')
        slist.remove('R')
    while 'O' in slist:
        digit.append(1)
        slist.remove('O')
        slist.remove('N')
        slist.remove('E')
    while 'F' in slist:
        digit.append(5)
        slist.remove('F')
        slist.remove('I')
        slist.remove('V')
        slist.remove('E')
    while 'X' in slist:
        digit.append(6)
        slist.remove('S')
        slist.remove('I')
        slist.remove('X')
    while 'S' in slist:
        digit.append(7)
        slist.remove('S')
        slist.remove('E')
        slist.remove('V')
        slist.remove('E')
        slist.remove('N')
    while 'G' in slist:
        digit.append(8)
        slist.remove('E')
        slist.remove('I')
        slist.remove('G')
        slist.remove('H')
        slist.remove('T')
    while 'T' in slist:
        digit.append(3)
        slist.remove('T')
        slist.remove('H')
        slist.remove('R')
        slist.remove('E')
        slist.remove('E')
    while 'N' in slist:
        digit.append(9)
        slist.remove('N')
        slist.remove('I')
        slist.remove('N')
        slist.remove('E')
    digit.sort()
    print("Case #%d: %s" % (case_number, "".join(map(str, digit))))


def main():
    r = sys.stdin

    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        s = r.readline().strip()

        solve_case(s, case_number)


if __name__ == '__main__':
    main()