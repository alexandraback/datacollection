'''
Created on Apr 26, 2013

@author: johnny
'''

import math

def foo (r, t):
    b = 2*r -1
    a = 2
    c = -t
    
    n = (-b + math.sqrt(b*b - 4*a*c) ) / float(2*a)
    
    n = int(math.floor(n))
    
    print n 
    return n


if __name__ == "__main__":
    input_path = 'input/p1_l.in'
    output_path = 'output/p1_l.out'
    
    input_file = open(input_path)
    
    result_list = []
    
    count = int(input_file.readline())
    for case_index in range(1,count+1):
        r, t = (float(s) for s in input_file.readline().split())
        result = foo(r,t)
        result_str = 'Case #{0}:\t{1}'.format(case_index, result)
        result_list.append(result_str)
    
    input_file.close()   
    output_str = '\n'.join(result_list)
    print output_str
    
    output_file = open(output_path,'w+')
    output_file.write(output_str)
    output_file.close
