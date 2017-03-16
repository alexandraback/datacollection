import os
import sys

problem_id = 'C'

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
    n = int(read_line())
    d, h, m = map(int, read_line().split(' '))
    d1, m1 = d, m
    if h == 1:
        d, h, m = map(int, read_line().split(' '))
        d2, m2 = (d, m)
    else:
        d2, m2 = (d, m + 1)
    if d1 > d2 or (d1 == d2 and m1 > m2):
        d1, d2 = d2, d1
        m1, m2 = m2, m1
    time_a = (360.0 - d1) / m1
    time_b = (360.0 - d2 + d1) / m2
    if time_b < time_a:
        return 1
    return 0




input_file = open(input_path, "r")
output_file = open(output_path, "w+")
T = int(read_line())
for case_id in xrange(1, T + 1):
    write_line("Case #%d: %s" % (case_id, solve()))
input_file.close()
output_file.close()