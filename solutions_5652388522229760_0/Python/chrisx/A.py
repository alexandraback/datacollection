import numpy as np

def parse(input_file, output_file):
    with open(input_file) as f:
        T = int(f.readline().split()[0])
        out = open(output_file, 'w')
        for i in range(T):
            N = int(f.readline().split()[0])
            sol = solve(N)
            line = "Case #"+str(i+1)+": "+str(sol)
            print(line)
            out.write(line+'\n')
    return


def solve(N):
    if N == 0:
        return "INSOMNIA"
    seen = set()
    for i in range(1, 1000):
        number = i*N
        seen = seen|set(str(number))
        if len(seen) == 10:
            return number
    raise ValueError(N)



dir = "./"

input_file = dir+"A-test.in"
output_file = dir+"A-test.txt"

input_file = dir+"A-small-attempt0.in"
output_file = dir+"A-small-attempt0.out"

'''
input_file = dir+"A-large-practice.in"
output_file = dir+"A-large-output-practice.txt"
'''
parse(input_file, output_file)

