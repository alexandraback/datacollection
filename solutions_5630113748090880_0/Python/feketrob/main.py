__author__ = 'Roberto'
import math

def finish(index, solution):

    print solution

    file_out.write("Case #{0}: {1}\n".format(index+1, solution))

def solve_test(index, test_case):

    print "Case: [{0}]".format(test_case)

    N = int(test_case[0])
    nums = {}

    result = []

    for line in test_case[1:]:

        numbers = map(int, line.split(" "))
        for n in numbers:
            if not nums.has_key(n):
                nums[n] = 0
            nums[n] += 1

    for k, v in nums.iteritems():
        if v % 2 != 0:
            result.append(k)

    result.sort()

    finish(index, " ".join(map(str, result)))


task = "B"
level = 1
attempts = 1

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

    N = int(test_cases[0])
    test_case = test_cases[:2*N]
    test_cases = test_cases[2*N:]

    solve_test(i, test_case)

file_out.close()