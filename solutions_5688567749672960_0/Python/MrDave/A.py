
import csv
import itertools
import copy
import time
import numpy


def read_file(filename):
    f = open(filename)
    csv_r = csv.reader(f, delimiter=' ')
    T = int(csv_r.next()[0])
    test_lst = []
    for i in xrange(T):
        N = csv_r.next()[0]
        test_lst.append(int(N))
    f.close() 
    return test_lst 


def reverse_int(i):
    str_i = str(i)
    return int(''.join(reversed(str_i)))


def solve_test(N):
    if N == 1:
        return 1
    l, res = recursive_solve([N], 1)
    return res


def init():
    n_max = 10**6
    global l
    l = [None] * n_max
    rank = 1
    c = [1]
    while len(c) > 0:
        new_c = []
        for e in c:
            c1 = e + 1
            if c1 <= n_max and l[c1-1] is None:
                l[c1-1] = rank+1
                new_c.append(c1)
            c2 = reverse_int(e)
            if c2 <= n_max and l[c2-1] is None:
                l[c2-1] = rank+1
                new_c.append(c2)
        c = new_c
        rank += 1
    l[0] = 1
    
    
def main(filename):
    test_lst = read_file(filename)
    init()
    for i_test, test_case in enumerate(test_lst):
        #res = solve_test(test_case)
        res = l[test_case-1]
        print "Case #%i: %i" % (1+i_test, res)


if __name__ == '__main__':
    #main('./simple.in')
    #main('./A-large.in')
    main('./A-small-attempt0.in')

