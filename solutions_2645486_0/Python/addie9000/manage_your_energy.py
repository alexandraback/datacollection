#!/usr/local/bin/python
import sys, math


#solve case function
def solve_case(e, r, vs, case_number):
    future_lim_range = range(1, int(math.ceil(float(e) / r)) + 1)
    total = 0
    vss = zip(range(0, len(vs)), vs)
    vss.sort(reverse=True, key=lambda t: t[1])
    e_lim = {}
    for task in vss:
        key = task[0]
        if key in e_lim:
            lim = e_lim[key]
        else:
            lim = e
            for ad in future_lim_range:
                if key + ad in e_lim:
                    lim = ad * r
                    break
            for back in range(key - 1, -1, -1):
                if back in e_lim:
                    tmp_lim = r * (key - back)
                    if tmp_lim < lim:
                        lim = tmp_lim
                    break
        total += lim * task[1]
        e_lim[key] = lim

    print "Case #%d: %d" % (case_number, total)


#main
def main():
    r = sys.stdin
    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        e_r_n = map(int, r.readline().strip().split(' '))
        vs = map(int, r.readline().strip().split(' '))
        solve_case(e_r_n[0], e_r_n[1], vs, case_number)


#invoke main
if __name__ == "__main__":
    main()
