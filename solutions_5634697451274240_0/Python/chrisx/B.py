import numpy as np

def parse(input_file, output_file):
    with open(input_file) as f:
        T = int(f.readline().split()[0])
        out = open(output_file, 'w')
        for i in range(T):
            s = f.readline().split()[0]
            sol = solve(s)
            line = "Case #"+str(i+1)+": "+str(sol)
            print(line)
            out.write(line+'\n')
    return


def solve(s):
    last = 'x'
    first = s[0]
    length = 0
    for char in s:
        if char != last:
            length += 1
            last = char
    if first == '+':
        if length % 2 == 0:
            return length
        else:
            return length - 1
    elif first == '-':
        if length % 2 == 0:
            return length - 1
        else:
            return length
    else:
        raise ValueError
            



dir = "./"

input_file = dir+"B-test.in"
output_file = dir+"B-test.txt"

input_file = dir+"B-small-attempt0.in"
output_file = dir+"B-small-attempt0.out"

'''
input_file = dir+"A-large.in"
output_file = dir+"A-large.out"
'''
parse(input_file, output_file)


