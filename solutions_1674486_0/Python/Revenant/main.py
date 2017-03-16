import itertools
import numpy
from numpy.linalg import linalg
import scipy
import scipy.optimize

file=open('input.txt','rt')
#out_file = open('output.txt','wt')

test_cases = int(file.readline())


def disp(aa):
    for row in aa:
        print(row)

def recurse(A, i, found):
    #disp(A)
    #disp(found)
    for j,val in enumerate(A[i]):
        if val==1:
            if found[i][j]==1:
                return True
            else:
                found[i][j] = 1
                if recurse(A, j, found):
                    return True
    return False


for test_case in range(0, test_cases):
    num_class = int(file.readline())

    A = [[0 for j in range(num_class)] for i in range(num_class)]

    for i in range(num_class):
        tokens = [int(x) for x in file.readline().split(' ')]

        tokens.pop(0)
        for j in tokens:
            A[i][j-1] = 1

    res = False
    for i in range(num_class):
        found = [[0]*num_class]*num_class
        rr = recurse(A, i, found)
        if rr:
            res = True
            break



    #res = solve(num_constants, judge_scores)
    print('Case #{0}: {1}'.format(test_case+1, 'Yes' if res else 'No' ))


#out_file.flush()
#out_file.close()