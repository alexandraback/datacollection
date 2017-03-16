import numpy as np
import sys
a=open(sys.argv[-1]).readlines()[1:]

def solve(word):
    new = word[0]
    for letter in word[1:]:
        if letter >= new[0]:
            new = letter + new
        else:
            new += letter
    return new[:-1]

for i in range(len(a)):
    print 'Case #' + str(i + 1) + ': ' + str(solve(a[i]))
