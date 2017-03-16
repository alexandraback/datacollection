import os
import sys

problem_id = 'B'

sys.setrecursionlimit(10**9)
input_path = '%s.in' % problem_id
output_path = '%s.out' % problem_id


def read_line():
    line = ''
    while len(line) == 0:
        line = input_file.readline().strip()
    return line


def write_line(line):
    print line
    return output_file.write(line + os.linesep)


def solve():
    d = int(read_line())
    non_empty_plates = map(int, read_line().split(' '))
    max_plate = max(non_empty_plates)
    total_time = max_plate
    for eat_time in xrange(max_plate, 0 , -1):
        wait_time = 0
        for plate_vol in non_empty_plates:
            if plate_vol > eat_time:
                wait_time += plate_vol / eat_time
                if plate_vol % eat_time == 0:
                    wait_time -= 1
        if total_time > wait_time + eat_time:
            total_time = wait_time + eat_time
    return str(total_time)


input_file = open(input_path, "r")
output_file = open(output_path, "w+")
T = int(read_line())
for case_id in xrange(1, T + 1):
    write_line("Case #%d: %s" % (case_id, solve()))
input_file.close()
output_file.close()