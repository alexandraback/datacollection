#!/usr/bin/env python
'''
      
'''

import sys
from pprint import pprint
import string


def do_one_case(csn, A, B, probs):
    probcorrect = {} 
    probcorrect[0] = 1.0
    for idx,p in enumerate(probs):
        probcorrect[idx+1] = p*probcorrect[idx]
    
#    print probcorrect

    # Keep trying 
    optimal = (B-A+1) * probcorrect[A] + (B+B-A+2)* (1 - probcorrect[A])
    # Backspacing 
    for i in range(1,A):
        temp = (B-A+1+2*i) * probcorrect[A-i] + (B+B-A+2+2*i) * (1 - probcorrect[A-i])
        if temp < optimal:
            optimal = temp
    if B+2 < optimal:
        optimal = B+2 

    print "Case #"+str(csn)+":", "%1.8f" % (optimal )

def main():
    T = int(sys.stdin.readline().strip())
    for i in range(T):
        A,B = map(int, sys.stdin.readline().strip().split())
        probs = map(float, sys.stdin.readline().strip().split())
        assert len(probs) == A
        #print W,H,T
        do_one_case(i+1, A, B, probs)


if __name__ == "__main__":
    main()
