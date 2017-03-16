import sys
import os
import math

# in = sys.stdin
fin = open('A-large.in')
# fout = sys.stdout
fout = open('out_1', 'w')


def solve(test):
    result = test[0]
    for s in test[1:]:
    	result = s + result if (s + result) > (result + s) else result + s
    return result 

if __name__ == '__main__':
    count = int(fin.readline().strip())

    for i in range(count):
        result = solve(fin.readline().strip())
        fout.write('Case #%s: %s\n' % (i + 1, result))


