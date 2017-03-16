#!/usr/local/bin/python

import sys
import itertools

def convert_to_base10(l, base):
    answer = 0
    for element in l:
        answer *= base
        answer += element

    return answer

def merge(a, b):
    c = []
    for i in range(len(a)):
        c.append(a[i])
        c.append(b[i])
    return c

def solve(t):
    N, J = map(int, sys.stdin.readline().rstrip().split())
    print 'Case #{}:'.format(t)

    sublist_length = (N-2)//2
    outputs = 0
    for left in itertools.combinations(range(sublist_length), 3):
        for right in itertools.combinations(range(sublist_length), 3):
            left_arr = [1 if x in left else 0 for x in range(sublist_length)]
            right_arr = [1 if x in right else 0 for x in range(sublist_length)]
            num = [1] + merge(left_arr, right_arr) + [1]
            for base in range(2, 11):
                num_10 = convert_to_base10(num, base)
                assert num_10 % (base+1) == 0
          
            print '{} 3 4 5 6 7 8 9 10 11'.format(convert_to_base10(num, 10)) 
            outputs +=1
           
            if outputs >= J:
                return

if __name__=="__main__":
    T = int(sys.stdin.readline())
    for i in range(1, T+1):
        solve(i)
