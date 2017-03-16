__author__ = 'Roberto'
import math

def finish(index, solution):

    print solution

    file_out.write("Case #{0}: {1}\n".format(index+1, solution))

def find_tail_rec(n, ids):

    inverse_BFFs = [i + 1 for i in xrange(len(ids)) if ids[i] == n and i+1 != ids[n-1]]
    max_tail = []
    max_length = 0

    for n1 in inverse_BFFs:
        tail = find_tail_rec(n1, ids)
        if max_length < len(tail):
            max_tail = tail[:]
            max_length = len(max_tail)

    max_tail.append(n)
    return max_tail

def find_tail(n, ids):

    max_tail = find_tail_rec(n, ids)
    print "Max tail of {0}: {1}".format(n, max_tail)

    return len(max_tail)

def solve_test(index, test_case):

    print "Case: [{0}]".format(test_case)

    N = int(test_case[0])
    ids = map(int, test_case[1].split(" "))
    circles = []
    visited = []

    for i in xrange(1, N + 1):

        if i not in visited:

            currenc_route = []
            current_node = i
            while current_node not in visited:
                currenc_route.append(current_node)
                visited.append(current_node)
                current_node = ids[current_node-1]

            if current_node in currenc_route:
                current_circle = currenc_route[currenc_route.index(current_node):]
                print "Current circle: {0}".format(current_circle)
                circles.append(current_circle)

    print "Circles {0}".format(circles)
    visited.sort()
    print "Visited {0}".format(visited)

    solution1 = max([len(c) for c in circles])

    two_length_circles = [c for c in circles if len(c) == 2]
    solution2 = 0
    for c in two_length_circles:
        tail_len1 = find_tail(c[0], ids)
        tail_len2 = find_tail(c[1], ids)
        solution2 += tail_len1 + tail_len2

    finish(index, max(solution1, solution2))


task = "C"
level = 2
attempts = 0

if level == 0:
    file_name = "sample.in"
elif level == 1:
    file_name = "{0}-small-attempt{1}.in".format(task, attempts)
else:
    file_name = "{0}-large.in".format(task)



file_out_name = file_name.replace("in", "out")
file_out = open(file_out_name, 'w')

with open(file_name, 'r') as file:
    content = file.read()

lines = content.split('\n')
number_of_lines = int(lines[0])

test_cases = lines[1:]

for i in xrange(0, number_of_lines):

    solve_test(i, test_cases[2*i: 2*(i+1)])

file_out.close()