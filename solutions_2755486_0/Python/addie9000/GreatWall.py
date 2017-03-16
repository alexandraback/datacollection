#!/usr/local/bin/python
import sys


#solve case function
def solve_case(tribes, case_number):
    wall = {}
    succeed = 0
    day = 0
    while tribes:
        a_history = []
        end_tribes = []
        for tribe in tribes:
            if tribe[0] == day:
                we = tribe[2]
                ee = tribe[3]
                a = tribe[4]
                for p in range(we, ee):
                    key = "%d-%d" % (p, p + 1)
                    if (not key in wall) or wall[key] < a:
                        succeed += 1
                        a_history.append([a, we, ee])
                        break

                tribe[1] -= 1
                if tribe[1] <= 0:
                    end_tribes.append(tribe)
                    continue

                tribe[0] += tribe[5]
                tribe[2] += tribe[6]
                tribe[3] += tribe[6]
                tribe[4] += tribe[7]

        for a in a_history:
            for p in range(a[1], a[2]):
                key = "%d-%d" % (p, p + 1)
                if (not key in wall) or wall[key] < a[0]:
                    wall[key] = a[0]

        for tribe in end_tribes:
            tribes.remove(tribe)

        day += 1

    print "Case #%d: %d" % (case_number, succeed)


#main
def main():
    r = sys.stdin
    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        n = int(r.readline().strip())
        tribes = []
        for x in range(0, n):
            tribes.append(map(int, r.readline().strip().split(' ')))
        solve_case(tribes, case_number)


#invoke main
if __name__ == "__main__":
    main()
