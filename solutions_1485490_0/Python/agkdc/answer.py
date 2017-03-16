import sys
import pdb
import os
sys.setrecursionlimit(5000)
sys.path.append('D:/codejam/round 1C/C')
core_no = 4

file = open('input.txt')
input = file.read()
file.close()

input = input.split("\n")

T = int(input[0])
input = input[1:]

def assembly(data, first_pos, second_pos, finish):
    #pdb.set_trace()
    if first_pos == data.first_no[data.N-1] or second_pos == data.second_no[data.M-1]:
        return finish
    first_type, second_type = data.first_type[0], data.second_type[0]
    for i in range(0,data.N):
        if first_pos >= data.first_no[i]:
            first_type = data.first_type[i+1]
        else: break
    for j in range(0,data.M):
        if second_pos >= data.second_no[j]:
            second_type = data.second_type[j+1]
        else: break
    if first_type == second_type:
        available = min(data.first_no[i]-first_pos,data.second_no[j]-second_pos)
        return assembly(data,first_pos+available, second_pos+available, finish+available)
    else:
        return max(assembly(data,data.first_no[i],second_pos,finish),assembly(data,first_pos,data.second_no[j],finish))
    
class input_data:
    def __init__(self,*args):
        self.N, self.M = args
        self.first_no, self.first_type, self.second_no, self.second_type = [],[],[],[]
    def total(self):
        for i in range(1,self.N):
            self.first_no[i] += self.first_no[i-1]
        for i in range(1,self.M):
            self.second_no[i] += self.second_no[i-1]
    pass

def main(data,starting_position):
    result = []
    for i in range(0,len(data)):
        result += [assembly(data[i],0,0,0)]
    file = open('output'+str(starting_position)+'.txt', 'w')
    for i in range(0,len(result)):
        file.write('Case #'+str(starting_position+i+1)+': '+str(result[i])+'\n')
        
        
        
        
input_data_set = []
for i in range(0,T):
    N, M = int(input[0].split(' ' )[0]), int(input[0].split(' ')[1])
    input = input[1:]
    input_data_set += [input_data(N,M)]
    for j in range(0,N):
        input_data_set[i].first_no += [int(input[0].split(' ')[2*j])]
        input_data_set[i].first_type += [int(input[0].split(' ')[2*j+1])]
    input = input[1:]
    for j in range(0,M):
        input_data_set[i].second_no += [int(input[0].split(' ')[2*j])]
        input_data_set[i].second_type += [int(input[0].split(' ')[2*j+1])]
    input = input[1:]
    input_data_set[i].total()

processes = []
if __name__ == '__main__':
    for i in range(0,core_no):
        main(input_data_set[(T/4)*i:(T/4)*(i+1)],(T/4)*i)