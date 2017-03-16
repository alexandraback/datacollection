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

cache = {}
for i in xrange(1, 10):
    cache[i] = i

def get_count(num):
    if num in cache:
        return cache[num]
    if num % 10 != 0:
        reverse_num = num % 10
        tmp = num / 10
        while tmp > 0:
            reverse_num *= 10
            reverse_num += tmp % 10
            tmp /= 10
        if reverse_num < num:
            cache[num] = min(get_count(reverse_num) + 1, get_count(num - 1) + 1)
            return cache[num]
    cache[num] = get_count(num - 1) + 1
    return cache[num]


def solve():
    n = int(read_line())
    return '%s' % get_count(n)


input_file = open(input_path, "r")
output_file = open(output_path, "w+")
T = int(read_line())
for case_id in xrange(1, T + 1):
    write_line("Case #%d: %s" % (case_id, solve()))
input_file.close()
output_file.close()