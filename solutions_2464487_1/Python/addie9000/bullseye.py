#!/usr/local/bin/python
import sys, math


def calc_litter(r, x):
    return (2 * (x * x)) - x + (2 * x * r)


#solve case function
def solve_case(r, t, case_number):
    cur_x = int(math.sqrt(t))
    delta = cur_x
    while True:
        delta /= 2
        if delta <= 0:
            delta = 1
        tmp_t = calc_litter(r, cur_x)
        if t < tmp_t:
            cur_x -= delta
        elif t > tmp_t:
            if t < calc_litter(r, (cur_x + 1)):
                break
            else:
                cur_x += delta
        else:
            break

    print "Case #%d: %d" % (case_number, cur_x)


#main
def main():
    r = sys.stdin
    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        r_t = map(int, r.readline().strip().split(' '))
        solve_case(r_t[0], r_t[1], case_number)


#invoke main
if __name__ == "__main__":
    main()