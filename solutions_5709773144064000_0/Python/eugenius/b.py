"""
Author: Eugene Yurtsev
"""
import sys
import math

STDIN = sys.stdin
num_cases = int(STDIN.readline())

r0 = 2.0

def calculate_time(C, F, X, n_farms):
    """
    Calculates the min time required to reach the goal if n farms are purchased.

    Would be nice to find analytic solution, but the best
    """
    terms = [C/(r0 + n * F) for n in range(int(n_farms))]
    return sum(terms) + X / (r0 + n_farms * F)



    #if n_farms == 0:
        #return X/r0
    #else:
        #change =  (C-X)/(r0 + (n_farms-1) * F) + X/(r0+n_farms*F)
        #return calculate_time(C, F, X, n_farms-1) + change

def calculate_best_farm_num(C, F, X):
    """
    Calculate best numbers of farms to reach goal.

    C : cost of farm
    F : rate increase of each farm
    X : target
    """
    n_farms = X/C - r0/F
    if n_farms < 0.0:
        return 0.0
    else:
        return float(int(n_farms))

def parse_case():
    specs = STDIN.readline()
    specs = map(float, specs.split(' '))
    return specs

for case in range(num_cases):
    specs = parse_case()
    C, F, X = specs
    n = calculate_best_farm_num(C, F, X)
    min_time = calculate_time(C, F, X, n_farms=n)
    print 'Case #{}: {}'.format(case+1, min_time)
