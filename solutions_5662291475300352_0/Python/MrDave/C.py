
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
        N = int(csv_r.next()[0])
        hike_lst = []
        for j in xrange(N):
            di, hi, mi = [int(e) for e in csv_r.next()]
            for ii in xrange(hi):
                hike_lst.append([di, mi+ii])
        hike_lst.sort()
        test_lst.append(hike_lst)
    f.close() 
    return test_lst 


def process_hike_lst(h_lst):
    complete_one, complete_two, complete_three = [], [], []
    for d, m in h_lst:
        complete_one.append((360.0-d) / 360.0 * m)
        complete_two.append((360.0-d) / 360.0 * m + m)
        complete_three.append((360.0-d) / 360.0 * m + 2*m)
    if complete_one[0] < complete_one[1]:
        if complete_two[0] <= complete_one[1]:
            return 1
        else: 
            return 0
    elif complete_one[0] > complete_one[1]:
        if complete_two[1] <= complete_one[0]:
            return 1
        else: 
            return 0
    else:
        return 0


def solve_test(hike_lst):
    if len(hike_lst) <= 1:
        return 0
    return process_hike_lst(hike_lst)


def init():
    pass


def main(filename):
    test_lst = read_file(filename)
    init()
    for i_test, test_case in enumerate(test_lst):
        m1 = solve_test(test_case)
        print "Case #%i: %i" % (1+i_test, m1)


if __name__ == '__main__':
    main('./C-small-1-attempt0.in')
    #main('./A-large.in')
    #main('./C-small-attempt2.in')

