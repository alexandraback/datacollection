def parse_input(N):
    height_lines = list()
    for i in range(2 * N - 1):
        height_lines.append(map(int, raw_input().split(' ')))
    return height_lines

def find_min_heights(height_lines, n):
    min_heights = list()
    for l in height_lines:
        if not min_heights:
            min_heights = [l]
        elif l[n] == min_heights[0][n]:
            min_heights.append(l)
        elif l[n] < min_heights[0][n]:
            min_heights = [l]
    return min_heights

import copy
def run(N):
    height_lines = parse_input(N)
    #print height_lines

    remaining_height_lines = copy.deepcopy(height_lines)
    missing_height_line = ""

    for n in range(N):
        min_heights = find_min_heights(remaining_height_lines, n)
        if len(min_heights) == 1:
            missing_height_line += str(min_heights[0][n]) + ' '
            remaining_height_lines.remove(min_heights[0])
        elif len(min_heights) == 2:
            total = [x for x in min_heights[0]] + [x for x in min_heights[1]]
            for hl in height_lines:
                total.remove(hl[n])
            missing_height_line += str(total[0]) + ' '
            remaining_height_lines.remove(min_heights[0])
            remaining_height_lines.remove(min_heights[1])
        else:
            return "ERROR"

    return missing_height_line


# raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(raw_input())  # read a line with a single integer
for i in xrange(1, t + 1):
    N = int(raw_input())
    result = run(N)
    print "Case #{}: {}".format(i, result)
    # check out .format's specification for more formatting options
