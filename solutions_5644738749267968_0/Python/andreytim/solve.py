#!/usr/bin/python

import sys

def binary_search(lo, hi, arr, n):
    while (lo < hi):
        mid = (lo + hi) / 2
        if arr[mid] > n:
            hi = mid
        else:
            lo = mid + 1
    return lo

def sim_war(naomi, ken):
    while naomi:
        nblock = naomi[0]
        k_idx = binary_search(0, len(ken), ken, nblock)
        if k_idx < len(ken):
            ken.pop(k_idx)
            naomi.pop(0)
        else: break
    return len(naomi)

def sim_dwar(naomi, ken):
    nscore = 0
    while naomi:
        if naomi[0] < ken[0]:
            naomi.pop(0)
            ken.pop()
        else:
            naomi.pop(0)
            ken.pop(0)
            nscore += 1
    return nscore

def solve_test_case(naomi, ken):
    return '%d %d' % (sim_dwar(sorted(naomi), sorted(ken)), 
            sim_war(sorted(naomi), sorted(ken)))

def main():
    f = open(sys.argv[1], 'r')
    T = int(f.readline().strip())
    for i in range(1, T+1):
        N = int(f.readline().strip())
        naomi = map(lambda l: float(l), f.readline().strip().split(' '))
        ken = map(lambda l: float(l), f.readline().strip().split(' '))
        print 'Case #%d: %s' % (i, solve_test_case(naomi, ken))

if __name__ == '__main__':
    main()
