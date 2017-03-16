#!/usr/local/bin/python
import sys


def split_by_v(word):
    word = word.replace('a', '+')
    word = word.replace('i', '+')
    word = word.replace('u', '+')
    word = word.replace('e', '+')
    word = word.replace('o', '+')
    s_list = word.split('+')
    while "" in s_list:
        s_list.remove("")
    return s_list


#solve case function
def solve_case(l, n, case_number):
    n_value = 0
    for s in range(0, len(l)):
        sl = l[s:]
        for e in range(len(sl), 0, -1):
            sel = sl[:e]
            sel_c_l = map(len, split_by_v(sel))
            if sel_c_l:
                if max(sel_c_l) >= n:
                    n_value += 1

    print "Case #%d: %d" % (case_number, n_value)


#main
def main():
    r = sys.stdin
    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        l_n = r.readline().strip().split(' ')
        solve_case(l_n[0], int(l_n[1]), case_number)


#invoke main
if __name__ == "__main__":
    main()
