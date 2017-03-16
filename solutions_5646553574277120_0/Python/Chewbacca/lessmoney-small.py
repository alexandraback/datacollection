#! /usr/bin/env python3

import sys, itertools

def list_powerset(lst):
    # the power set of the empty set has one element, the empty set
    result = [[]]
    for x in lst:
        # for every additional element in our set
        # the power set consists of the subsets that don't
        # contain this element (just take the previous power set)
        # plus the subsets that do contain the element (use list
        # comprehension to add [x] onto everything in the
        # previous power set)
        result.extend([subset + [x] for subset in result])
    return result


def minc(C,D,V,iniset):
    S = set(range(1,V+1)) - iniset
    for N in range(V):
        for A in itertools.combinations(S,N):
            #print(A)
            # continue
            res = list_powerset(set(A)|iniset)
            #print("res",res)
            ss = {}
            for subs in res:
                vv = 0
                for v in subs:
                    vv += v
                ss[vv]=1
            if set(range(1,V+1))-set(ss)==set():
                   return N
    return -1

number_of_test_cases = int(sys.stdin.readline())
for test_no in range(1, number_of_test_cases+1):
    C,D,V = map(int, sys.stdin.readline().split())
    iniset = set(map(int, sys.stdin.readline().split()))
    print("Case #{}: {}".format(test_no,minc(C,D,V,iniset)))
