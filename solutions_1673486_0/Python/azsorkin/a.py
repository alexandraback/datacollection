#! /usr/bin/env python3

##########
## Adam Sorkin
## google codejam round one-a. 
## 27 Apr 2012
##########

# ./a.py < input_file > output_file

import itertools

def main():
    "             "

    T = int(input()) # number of test cases
    for i in range(1, T+1):
        A, B = map( int, input().split() )
        p = [float(num) for num in input().split() ]
        
        result = foo(A,B,p)

        print("Case #{0}: {1}".format(i, result) )
        
    return

def foo(A,B, p):
    
    E = [ (B-A) + 2*k +1 + ( B+1) *(1- product( p[:A-k] ) ) for k in range(A+1)]
    E.append(2+B)
    return min(E)

def product(listy):
    t = 1
    for l in listy:
        t *= l
    return t

if __name__ == "__main__":
    main()
