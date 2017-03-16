import os
import sys

problem_id = 'D'

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
    x, r, c = map(int, read_line().split(' '))
    min_len = min(r, c)
    max_len = max(r, c)
    if x > max_len:
        return 'RICHARD'
    if x >= min_len + 2:
        return 'RICHARD'
    if x >= 7:
        return 'RICHARD'
    if r * c % x != 0:
        return 'RICHARD'
    return 'GABRIEL'


input_file = open(input_path, "r")
output_file = open(output_path, "w+")
T = int(read_line())
for case_id in xrange(1, T + 1):
    write_line("Case #%d: %s" % (case_id, solve()))
input_file.close()
output_file.close()