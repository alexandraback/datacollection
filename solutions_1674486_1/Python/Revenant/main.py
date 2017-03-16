import itertools
import numpy
from numpy.linalg import linalg
import scipy
import scipy.optimize

file=open('input.txt','rt')
#out_file = open('output.txt','wt')

test_cases = int(file.readline())
indent = ''
def recurse(i, found, parents, flag):
    global indent
    #print(indent,'recurse({1},{2})'.format(0,i, parents))
    indent+='   '
    my_parents = parents[i]
    if found[i]:
        return my_parents

    #print(indent,'for parent={0} in {1}:'.format('x', my_parents))
    for parent in list(my_parents):
        grand_parents = recurse(parent, found, parents, flag)
        #print(indent,'   if not {0} in parents[{2}]={1} parents[{2}]+={0}'.format(grand_parents, my_parents,i))
        #if flag[0]:
        #    return
        for grand_pa in grand_parents:
            if grand_pa in my_parents:
                flag[0] = True
                #return
            parents[i].add(grand_pa)

    found[i] = True
    indent=indent[:-3]
    return my_parents


for test_case in range(0, test_cases):
    num_class = int(file.readline())

    parents = [set() for i in range(num_class)]

    for i in range(num_class):
        tokens = [int(x) for x in file.readline().split(' ')]

        tokens.pop(0)
        for t in tokens:
            parents[i].add(t-1)

    res = False

    flag = [False]
    found = [False for yyy in range(num_class)]
    for i in range(num_class):
        recurse(i, found, parents, flag)
        if flag[0]:
            break

    #res = solve(num_constants, judge_scores)
    print('Case #{0}: {1}'.format(test_case+1, 'Yes' if flag[0] else 'No' ))


#out_file.flush()
#out_file.close()