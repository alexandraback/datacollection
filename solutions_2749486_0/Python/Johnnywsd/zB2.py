'''
Created on May 12, 2013

@author: johnny
'''

from math import *

def foo(X,Y):
    rtn = []
    if X >=0 and Y >=0:
        rtn = ['W','E']*X + ['S','N']*Y
    elif X < 0 and Y>=0:
        rtn = ['E','W']*abs(X) + ['S','N']*Y
    elif X >= 0 and Y<0:
        rtn = ['W','E']*X + ['N','S']*abs(Y)
    elif X < 0 and Y<0:
        rtn = ['E','W']*abs(X) + ['N','S']*abs(Y)
    return ''.join(rtn)

if __name__ == "__main__":

    input_path = 'inputC/b.in'
    output_path = 'outputC/b.out'
    
    input_file = open(input_path)
    result_list = []
    
    T = int(input_file.readline())
    for case_index in range(1,T+1):
        X, Y = (int(s) for s in input_file.readline().split())
        
        result = foo(X, Y)
        print len(result)
        
        result_str = 'Case #%s: %s' % (case_index, result)
        
        result_list.append(result_str)
#         
    input_file.close()   
    output_str = '\n'.join(result_list)
    print output_str
    output_file = open(output_path,'w+')
    output_file.write(output_str)
    output_file.close