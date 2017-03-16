import numpy
import re


def count(arr, lis):
    count = 0
    for elem in arr:
        if elem in lis:
            count += 1
    return count

def get_indices(arr, lis):
    indices = []
    for i in range(len(arr)):
        if arr[i] in lis:
            indices.append(i)
    return indices

def is_less_than_eq(mat, val, minimum):
    # row:
    for i in range(len(mat)):
        row = mat[i].tolist()
        num = count(row, range(minimum, val + 1))
        if num > 0 and num != len(row):
            # check columns
            indices = get_indices(row, range(minimum, val + 1))
            for col in indices:
                column = mat[:, col].tolist()
                if count(column, range(minimum, val + 1)) != len(column):
                    return False
            # otherwise possible
        # otherwise possible
    return True

a_max = 100
def is_possible(inp):
    mat = numpy.array(inp)
    # get max/min
    maximum = 0
    minimum = a_max
    for i in range(len(mat)):
        maximum = max( max(mat[i]), maximum)
        minimum = min( min(mat[i]), minimum)
    # get bool matrix
    for i in range(minimum, maximum):  # max + 1 unnecessary
        if not is_less_than_eq(mat, i, minimum):
            return 'NO'
    # else possible
    return 'YES'

cases = int(raw_input())
for c in xrange(cases):
    x, y = map(int, raw_input().split())
    mat = []
    for i in range(x):
        row = map(int, raw_input().split())
        mat.append(row)
    print "Case #%d: %s" % ((c+1), is_possible(mat))
    
