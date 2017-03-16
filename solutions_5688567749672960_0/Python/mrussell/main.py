import fileinput 
from math import log, floor, ceil

input = fileinput.input()

def flip(x): return int(str(x)[::-1])
    
def num_digits(x):
    if x == 0: return 0
    else: return 1 + num_digits(x // 10)

def largest_digit(x):
    n = num_digits(x)
    for i in range(n-1):
        x = x // 10
    return x

def smallest_digit(x): return x % 10

def should_i_flip(x, goal):
    flipped = flip(x)
    if flipped < goal and largest_digit(x) == 1:
        if smallest_digit(x) == 9: return True
        else:
            if flip(x+1) > goal and flipped > x: return True
    return False

A = [0]

def best_way(x): 
    flipped = flip(x)
    if flipped >= x or num_digits(flipped) != num_digits(x): # get to x by way of x - 1
        A.append(A[x-1] + 1)
    else: # take the best way of either flip(x) + 1 or (x-1) + 1
        c1 = A[flipped]
        c2 = A[x-1]
        A.append(min(c1, c2) + 1)

def get(x):
    l = len(A)
    if l > x: return A[x]
    else: 
        for i in range(l, x + 1):
            best_way(i)
    return A[x]

def do_case(case_num):
    N = int(next(input))
    print "N: %d" % N
    print "Case #%d: %d" % (case_num, get(N))
        
T = int(next(input))
for case_num in range(1, T+1):
    do_case(case_num)

