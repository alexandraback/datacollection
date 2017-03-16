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


mul_map = [
    [0,  0,  0,  0,  0],
    [0,  1,  2,  3,  4],
    [0,  2, -1,  4, -3],
    [0,  3, -4, -1,  2],
    [0,  4,  3, -2, -1]
]


def mul(x, y):
    return mul_map[abs(x)][abs(y)] * (-1 if x * y < 0 else 1)


base = -ord('i') + 2


def solve():
    l, x = map(int, read_line().split(' '))
    num_list = [ord(char) + base for char in read_line()]
    if l * x < 3:
        return 'NO'
    unit_total = 1
    for num in num_list:
        unit_total = mul(unit_total, num)
    pow_ring = [0, 0, 0, 0]
    pow_value = 1
    for i in xrange(4):
        pow_ring[i] = mul(pow_value, unit_total)
        pow_value = pow_ring[i]
    if pow_ring[(x - 1) % 4] != -1:
        return 'NO'
    left_total = 1
    min_left_unit = x
    min_left_pos = l + 1
    index = 0
    for left_num in num_list:
        index += 1
        left_total = mul(left_total, left_num)
        if left_total == 2:
            min_left_unit = 0
            min_left_pos = index
            break
        else:
            count = 0
            for pow_value in pow_ring:
                count += 1
                if mul(pow_value, left_total) == 2:
                    min_left_unit = count
                    min_left_pos = index
                    break
    right_total = 1
    min_right_unit = x
    min_right_pos = l + 1
    index = 0
    for right_num in reversed(num_list):
        index += 1
        right_total = mul(right_total, right_num)
        if right_total == 4:
            min_right_unit = 0
            min_right_pos = index
            break
        else:
            count = 0
            for pow_value in pow_ring:
                count += 1
                if mul(right_total, pow_value) == 4:
                    min_right_unit = count
                    min_right_pos = index
                    break
    if min_left_unit + min_right_unit >= x:
        return 'NO'
    if min_left_unit + min_right_unit == x - 1:
        if min_left_pos + min_right_pos < l:
            return 'YES'
        else:
            return 'NO'
    return 'YES'


input_file = open(input_path, "r")
output_file = open(output_path, "w+")
T = int(read_line())
for case_id in xrange(1, T + 1):
    write_line("Case #%d: %s" % (case_id, solve()))
input_file.close()
output_file.close()