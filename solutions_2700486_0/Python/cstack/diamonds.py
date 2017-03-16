from os import sys
from math import *
from operator import mul

diamonds_up_to_layer = [1]
size_of_layer = [1]
for i in range(1,10000):
    n = 4*i + 1
    size_of_layer.append(n)
    diamonds_up_to_layer.append(diamonds_up_to_layer[i-1] + n)

B_cache = {}

def choose(n,k):
    out = reduce(mul, (float(n-i)/(i+1) for i in range(k)), 1)
    return out

def B(k, n):
    key = str(k)+","+str(n)
    if key not in B_cache:
        B_cache[key] = choose(n,k)*0.5**n
    return B_cache[key]

def calculate_chance(min_successes, num_trials):
    return 1 - sum([B(k, num_trials) for k in range(min_successes)])

def layer(X,Y):
    return int(Y/2 + ceil(abs(X/2.0)))

num_cases = int(sys.stdin.readline())

for case in range(1,num_cases+1):

    (N,X,Y) = [int(i) for i in sys.stdin.readline().split()]

    L = layer(X,Y)
    diamonds_in_layer = N - diamonds_up_to_layer[L-1]
    if L == 0:
        if N >= 1:
            p = 1.0
        else:
            p = 0.0
    elif diamonds_in_layer >= size_of_layer[L]:
        p = 1.0
    elif diamonds_in_layer <= 0 or X == 0:
        p = 0.0
    elif diamonds_in_layer >= 2*L+Y+1:
        p = 1.0
    elif diamonds_in_layer < Y+1:
        p = 0.0
    else:
        p = calculate_chance(Y+1, diamonds_in_layer)
        
    
    print "Case #"+str(case)+":",p
