import os
import sys

problem_id = 'A'

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
    _, audience_num = read_line().split(' ')
    invite_count = 0
    stood_count = 0
    for shyness, count in enumerate(audience_num):
        count = int(count)
        if count > 0:
            if stood_count < shyness:
                invite_count += shyness - stood_count
                stood_count = shyness
            stood_count += count
    return str(invite_count)


input_file = open(input_path, "r")
output_file = open(output_path, "w+")
T = int(read_line())
for case_id in xrange(1, T + 1):
    write_line("Case #%d: %s" % (case_id, solve()))
input_file.close()
output_file.close()