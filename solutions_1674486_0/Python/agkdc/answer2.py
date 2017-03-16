import sys
import pdb
import os
from multiprocessing import Process
sys.path.append('D:/codejam/round 1C/A')
core_no = 4

file = open('input.txt')
input = file.read()
file.close()

input = input.split("\n")

T = int(input[0])
input = input[1:]

class node:
    def set_parent(self,*args):
        self.M = args[0]
        self.parent = []
        self.ancestor = []
    pass

class input_data:
    def __init__(self, *args):
        self.N = args[0]
        self.nodes = []
        for i in range(0,self.N):
            self.nodes += [node()]
    pass
    
def find_diamond(data):
    for i in range(0,data.N):
        if data.nodes[i].M > 1:
            for repeat in range(0,data.N):
                for j in range(0,data.N):
                    if not j in data.nodes[i].ancestor:
                        for k in range(0,len(data.nodes[i].ancestor)):
                            if j in data.nodes[data.nodes[i].ancestor[k]].parent:
                                data.nodes[i].ancestor += [j]  
            for j in range(0,len(data.nodes[i].ancestor)):
                count = 0
                for k in range(0,len(data.nodes[i].ancestor)):
                    if data.nodes[i].ancestor[j] in data.nodes[data.nodes[i].ancestor[k]].parent: count += 1
                if count > 1: return True
    return False

def main(data,starting_position):
    result = []
    for i in range(0,len(data)):
        if find_diamond(data[i]): result += ['Yes']
        else: result += ['No']
    file = open('output'+str(starting_position)+'.txt', 'w')
    for i in range(0,len(result)):
        file.write('Case #'+str(starting_position+i+1)+': '+result[i]+'\n')
        
        
        
parents = []        
input_data_set = []
for i in range(0,T):
    input_data_set += [input_data(int(input[0]))]
    input = input[1:]
    for j in range(0,input_data_set[i].N):
        M = int(input[0].split(' ')[0])
        parents = []
        for k in range(0,M):
            parents += [int(input[0].split(' ')[k+1])-1]
        input_data_set[i].nodes[j].set_parent(M)
        input_data_set[i].nodes[j].parent = parents
        input_data_set[i].nodes[j].ancestor += [j]
        input = input[1:]

processes = []
if __name__ == '__main__':
    for i in range(0,core_no-1):
        processes += [Process(target=main,args=(input_data_set[(T/4)*i:(T/4)*(i+1)],(T/4)*i,))]
        processes[i].start()
        processes[i].join()
    
    processes += [Process(target=main,args=(input_data_set[(T/4)*3:],(T/4)*3,))]
    processes[3].start()
    processes[3].join()