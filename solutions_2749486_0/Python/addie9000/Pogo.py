#!/usr/local/bin/python
import sys, string


#solve case function
def solve_case(goal, case_number):
    pos = [0, 0]
    move_history = ""

    diff_x = goal[0] - pos[0]
    if diff_x > 0:
        move_history += "WE" * abs(diff_x)
    elif diff_x < 0:
        move_history += "EW" * abs(diff_x)

    diff_y = goal[1] - pos[1]
    if diff_y > 0:
        move_history += "SN" * abs(diff_y)
    elif diff_y < 0:
        move_history += "NS" * abs(diff_y)

    print "Case #%d: %s" % (case_number, move_history)


#main
def main():
    r = sys.stdin
    if len(sys.argv) > 1:
        r = open(sys.argv[1], 'r')

    total_cases = r.readline()
    for case_number in range(1, int(total_cases) + 1):
        goal = map(int, r.readline().strip().split(' '))
        solve_case(goal, case_number)


#invoke main
if __name__ == "__main__":
    main()
