from codejam.utils.codejamrunner import CodeJamRunner
import codejam.utils.graphing as graphing
import networkx as nx
from decimal import *
import codejam.utils.polynomials as pol

class Dynam(object):pass

def calc_steps_needed(next_m, size):

    n = 0
    new_size = size

    if new_size <= 1:
        return 1000000, new_size
    
    while new_size <= next_m:
        #print 'size: %s , target: %s ' % (new_size, next_m)
        n+= 1
        new_size += (new_size -1)

    return n, new_size

def solver(data):

    others = sorted(data.others)
    operations = []
    operation_count = 0
    size = data.start_size

    while others:
        next_m = others[0]
        others = others[1:]

        if next_m < size:
            size += next_m
        else:
            operations.append(operation_count + len(others) + 1)
            ops, size = calc_steps_needed(next_m, size)
            size+= next_m
            operation_count += ops
            
            if operation_count > operations[-1]:
                break

    operations.append(operation_count)
    
    return min(operations)
    

def data_builder(f):

    data = Dynam()

    data.start_size, data.oth_count = f.get_ints()
    data.others = f.get_ints()

    return data


cjr = CodeJamRunner()
cjr.run(data_builder, solver, problem_name = "A", problem_size='large')
