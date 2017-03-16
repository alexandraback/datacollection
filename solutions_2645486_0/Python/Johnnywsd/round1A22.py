'''
Created on Apr 26, 2013

@author: johnny
'''

import math


result = 0
result_list=[]

def foo (E,E_left,R,index,v_list,max_aux):
    global result
    global result_list
    if index == len(v_list) or E_left +R <0:
        if max_aux > result:
            result = max_aux
#             print result_list
        else:
            pass
    else:
        tmp = E_left
        E_left +=R
        if E_left > E:
            E_left = E
            
        for i in range(E_left+1):
#             result_list.append(i)
            foo(E,E_left-i,R,index+1, v_list, max_aux+ v_list[index]*i)
#             result_list.pop()
        E_left = tmp

if __name__ == "__main__":
    result = 0
    input_path = 'input/p2.in'
    output_path = 'output/p2.out'
    
    input_file = open(input_path)
    
    result_list = []
    
    count = int(input_file.readline())
    for case_index in range(1,count+1):
        E, R, N = (int(s) for s in input_file.readline().split())
        v_list = list((int(s) for s in input_file.readline().split()))
        
        
        print E,R,N
        print v_list
        foo(E,E-R,R,0,v_list,0)
        print result
        
        
        result_str = 'Case #{0}:\t{1}'.format(case_index, result)
        result_list.append(result_str)
        result = 0
    
    input_file.close()   
    output_str = '\n'.join(result_list)
    print output_str
    
    output_file = open(output_path,'w+')
    output_file.write(output_str)
    output_file.close
