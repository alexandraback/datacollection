import numpy as np
import sys
a=open(sys.argv[-1]).readlines()[1:]

first = {'Z': (0, 'ZERO'), 'W': (2, 'TWO'), 'U': (4, 'FOUR'), 'X': (6, 'SIX'), 'G': (8, 'EIGHT')}
second = {'O': (1, 'ONE'), 'T': (3, 'THREE'), 'F': (5, 'FIVE'), 'S': (7, 'SEVEN')}

def solve(problem):
    problem = list(problem)
    nums = []
    frem = False
    srem = False
    rem9 = False
    while (not frem):
        rem = 0
        for letter, word in first.iteritems():
            if letter in problem:
                rem += 1
                nums.append(word[0])
                for char in word[1]:
                    problem.remove(char)
        if rem == 0:
            frem = True

    while (not srem):
        rem = 0
        for letter, word in second.iteritems():
            if letter in problem:
                rem += 1
                nums.append(word[0])
                for char in word[1]:
                    problem.remove(char)
        if rem == 0:
            srem = True

    while (not rem9):
        rem = 0
        if 'N' in problem:
            rem += 1
            nums.append(9)
            for char in 'NINE':
                problem.remove(char)
        if rem == 0:
            rem9 = True

    return ''.join(str(num) for num in sorted(nums))


for i in range(len(a)):
    print 'Case #' + str(i + 1) + ': ' + str(solve(a[i]))
