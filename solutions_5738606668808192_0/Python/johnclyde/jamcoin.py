#!/usr/bin/env python

from sys import argv

script, N, J = argv

def integer_to_binary_string(n):
    if n == 0:
        return '0'
    binstr = ''
    x = n
    while x > 0:
        binstr = '{}{}'.format(x % 2, binstr)
        x = int(x / 2)
    return binstr

print "Case #1:"
num_zeroes = int(N) / 2 - 1
starting_point = 1
for i in range(0, num_zeroes):
    starting_point *= 2
starting_point += 1

for k in range(0, int(J)):
    disp = integer_to_binary_string(starting_point)
    disp = disp.replace('1', '11')
    disp = disp.replace('0', '00')
    starting_point += 2
    print "{} 3 4 5 6 7 8 9 10 11".format(disp)
