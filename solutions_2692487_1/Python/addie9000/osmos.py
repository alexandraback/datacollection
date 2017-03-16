#!/usr/local/bin/python
import sys


#solve case function
def solve_case(a, ns, case_number):
    ns.sort()
    mpc_can = []
    mpc = 0
    while ns:
        n = ns.pop(0)
        if a > n:
            a += n
        else:
            if n < (a * 2 - 1):
                a += a + n - 1
                mpc += 1
            else:
                mpc_can.append(mpc + len(ns) + 1)
                if a == 1:
                    break
                while a <= n:
                    a += a - 1
                    mpc += 1
                a += n
    else:
        mpc_can.append(mpc)
    print "Case #%d: %d" % (case_number, min(mpc_can))

#main
def main():
    r = sys.stdin
    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        a_n = map(int, r.readline().strip().split(' '))
        ns = map(int, r.readline().strip().split(' '))
        solve_case(a_n[0], ns, case_number)


#invoke main
if __name__ == "__main__":
    main()
