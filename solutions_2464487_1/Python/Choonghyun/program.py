import os
import sys
import pdb
import math

input_file = open('input.in')
input = input_file.read().split('\n')
input_file.close()

T = int(input[0])
input = input[1:]

class data:
    def __init__(self, r, t):
        self.r, self.t = r, t

def solve(target):
    r = target.r
    t = target.t
    root = (1-2*r+math.sqrt((2*r-1)*(2*r-1)+8*t))/4.0
    if float(int(root)) == root:
        return int(root)
    else:
        return int(root)

result = []
input_data = []

for i in range(T):
    input_data += [data(int(input[0].split(' ')[0]),int(input[0].split(' ')[1]))]
    input = input[1:]

result = map(solve,input_data)

output_file = open('output.txt','w')
for i in range(T):
    output_file.write('Case #'+str(i+1)+': '+str(result[i])+'\n')
output_file.close()