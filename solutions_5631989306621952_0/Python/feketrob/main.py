__author__ = 'Roberto'
import math

def finish(index, solution):

    print solution

    file_out.write("Case #{0}: {1}\n".format(index+1, solution))

def solve_test(index, test_case):

    print "Case: [{0}]".format(test_case)

    result = test_case[0]

    for c in test_case[1:]:
        if c >= result[0]:
            result = c + result
        else:
            result += c


    finish(index, result)


task = "A"
level = 1
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

    solve_test(i, test_cases[i])

file_out.close()