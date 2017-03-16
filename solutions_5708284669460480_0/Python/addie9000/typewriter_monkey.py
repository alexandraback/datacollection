import sys
import itertools
import re


# Super brute force. Let's solve small first!!
def solve_case(s, keyboard, target, case_number):
    key_list = list(keyboard)
    all_patterns = list(itertools.product(*[key_list] * s))
    max_bananas = 0
    all_bananas = 0
    for typed in all_patterns:
        bananas = len(re.findall(r'(?=(%s))' % target, "".join(typed)))
        if bananas > max_bananas:
            max_bananas = bananas
        all_bananas += bananas

    print "Case #%d: %f" % (case_number, (max_bananas - float(all_bananas) / len(all_patterns)))


def main():
    r = sys.stdin

    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        kls = map(int, r.readline().strip().split(' '))
        keyboard = r.readline().strip()
        target = r.readline().strip()

        solve_case(int(kls[2]), keyboard, target, case_number)


if __name__ == '__main__':
    main()
