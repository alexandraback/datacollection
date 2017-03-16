import math
from decimal import *
getcontext().prec = 30

def solution(parsed_line):
    r = int(parsed_line[0])
    t = int(parsed_line[1])

    s = Decimal(1 - 4*r + 8*t + 4*r**2).sqrt()
    
    e1 = (1 - 2 * r + s) / 4
    
    return int(e1)
    
def parse_input(f, process_f):
    data = open(f).read().split("\n")
    result = []
    for i in data[1:-1]:
        result.append(i.split(' '))
    return result

process_input = lambda l: [[int(j) for j in i.split()] for i in l]
process_output = lambda l: str(l)

f = 'A-small-attempt0.in'
fout = open('output.txt', 'w')
parsed_input = parse_input(f, process_input)

for line in range(len(parsed_input)):
    s = "Case #" + str(line + 1) + ": " + process_output(solution(parsed_input[line])) + "\n"
    fout.write(s)

fout.close()
