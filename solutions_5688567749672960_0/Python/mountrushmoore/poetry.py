#!/usr/local/bin/python

import math

def solve(goal):
    if (goal <= 20):
        return goal
    n = 10
    steps = 10
    n_digits = len(str(n))
    goal_digits = len(str(goal))
    while (n_digits != goal_digits):
        steps += int(int(math.ceil(float(n_digits) / 2.0)) * "9")
        steps += 1
        if (n_digits % 2 == 0):
            adjust = 0
        else:
            adjust = 1
        steps += int(int(math.ceil(float(n_digits) / 2.0) - adjust) * "9")
        n = n * 10
        print(str(steps) + " steps to get to " + str(n))
        n_digits = len(str(n))

        
    if (n_digits % 2 != 0):
        if (n == goal): return steps
        middle_index = int(math.ceil(float(n_digits) / 2.0)) - 1
        if int(str(goal)[middle_index+1:]) == 0:
            steps += 1
            goal -= 1
        middle_digit = int(str(goal)[middle_index])
        print("Middle digit is " + str(middle_digit))
        steps += middle_digit * int(math.pow(10, middle_index))
        n += middle_digit * int(math.pow(10, middle_index))
        print(str(steps) + " steps to get to " + str(n))
        
        first_half_n = str(n)[:middle_index]
        first_half_goal = str(goal)[:middle_index]
        print("First halves: " + first_half_n + ", " + first_half_goal)

        if (first_half_n != first_half_goal):
            while (str(goal)[:middle_index] != str(n)[middle_index+1:][::-1]):
                n += 1
                steps += 1
            print(str(steps) + " steps to get to " + str(n))

            n = int(str(n)[::-1])
            steps += 1

        while (str(goal)[middle_index+1:] != str(n)[middle_index+1:]):
            n += 1
            steps += 1
        print(str(steps) + " steps to get to " + str(n))
    else:
        if (n == goal): return steps
        middle_index = n_digits / 2
        if int(str(goal)[middle_index:]) == 0:
            steps += 1
            goal -= 1
        first_half_n = str(n)[:middle_index]
        first_half_goal = str(goal)[:middle_index]
        print("First halves: " + first_half_n + ", " + first_half_goal)

        if (first_half_n != first_half_goal):
            while (str(goal)[:middle_index] != str(n)[middle_index:][::-1]):
                n += 1
                steps += 1
            print(str(steps) + " steps to get to " + str(n))

            n = int(str(n)[::-1])
            steps += 1

        while (str(goal)[middle_index:] != str(n)[middle_index:]):
            n += 1
            steps += 1
        print(str(steps) + " steps to get to " + str(n))


    assert n == goal
    return steps


def main():

    infile = open("input.txt")
    outfile = open("output.txt", 'w')

    one = infile.readline()
    testCases = int(one)
    print(str(testCases) + " test cases")

    case = 1

    while (case <= testCases):
        goal = int(infile.readline().strip())
        print ("*** Trying to make: " + str(goal))
        steps = solve(goal)

        print("*** Case #" + str(case) + ": " + str(steps))
        outfile.write("Case #" + str(case) + ": " + str(steps) + "\n")
        case += 1

    outfile.close()
    infile.close()


main()
