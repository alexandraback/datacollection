import os
import sys

sys.path.append(os.path.dirname(os.path.abspath(__file__)))

input_file = open("input.in")
input_data = input_file.read()
input_file.close()
input = input_data.split('\n')

T = int(input[0])
input = input[1:]

class task:
    def __init__(self, E, R, N, v):
        self.E = E
        self.R = R
        self.N = N
        self.v = v

result = []
input_data = []

for case in range(T):
    input_data += [task(int(input[0].split(' ')[0]),int(input[0].split(' ')[1]),int(input[0].split(' ')[2]),map(lambda x:int(x),input[1].split(' ')))]
    input = input[2:]
    
def solve(cal, energy, index, gain):
    maximum = gain
    if index == cal.N:
        return gain+cal.v[index-1]*energy
    for use in range(min(max(0,energy+cal.R-cal.E),energy),energy+1):
        maximum = max(solve(cal,energy-use+cal.R,index+1,gain+cal.v[index-1]*use), maximum)
    return maximum

result = map(lambda x:solve(x,x.E,1,0),input_data)
    
output_data = ''
for case in range(T):
    output_data += 'Case #'+str(case+1)+': '+str(result[case])+'\n'
    
output_file = open("output.txt",'w')
output_file.write(output_data)
output_file.close()