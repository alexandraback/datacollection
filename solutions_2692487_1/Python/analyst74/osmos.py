__author__ = 'Bill'

import sys, time, math

def parse_case(file):
    a, n = map(int, file.readline().split())
    sizes = map(int, file.readline().split())

    return a, n, list(sizes)

def process_case(case):
    a, n, sizes = case
    res = 0
    sizes.sort()

    print('---')
    print (a, n)
    print(sizes)
    # special case where armin's mote is size 1
    if a == 1:
        return n

    increments = []
    inc_tas = []
    ta = a
    for i in range(n):
        inc = []
        while ta <= sizes[i]:
            inc.append(ta - 1)
            ta += ta - 1
        increments.append(inc)
        inc_tas.append(ta)
        ta += sizes[i]

    print(inc_tas)
    print(increments)

    all_res = []
    for i in range(n+1):
        inc_step_sum = sum([len(inc) for inc in increments[:i]])
        all_res.append(n - i + inc_step_sum)


    return min(all_res)

def get_sum(a, sizes, increments):
    return a + sum(sizes) + sum([sum(inc) for inc in increments])

if __name__ == '__main__':
    t0 = time.clock()

    if len(sys.argv) > 1:
        filename = sys.argv[1]
    else:
        filename = "sample.in"

    input_file = open(filename, "r")
    output_file = open(filename.replace('in','out'), "w")
    case_count = int(input_file.readline())
    for i in range(case_count):
        result = process_case(parse_case(input_file))
        output_line = 'Case #%d: %s\n' % (i+1, result)
        print(output_line)
        output_file.writelines(output_line)

    input_file.close()
    output_file.close()

    print('Total Time: %s' % str(time.clock() - t0))