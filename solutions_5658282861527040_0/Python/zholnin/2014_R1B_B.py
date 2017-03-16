import sys # standard Python library
import itertools # standard Python library
#from PerfectAllocation import PerfectAllocation # http://pastebin.com/5sv1quf0
from operator import itemgetter # standard Python library
import bisect # standard Python library
import math # standard Python library
import copy # standard Python library
from fractions import gcd # standard Python library
from utilities import *  # this is helper file which can be found at http://pastebin.com/5gkyim8x
# from blist import blist # add-on library which can be downloaded from https://pypi.python.org/pypi/blist/


sys.setrecursionlimit(1000) #1000 is default
Prep = []


def preprocess():
    return None
    
def readinput(Input):
    A, B, K = Input.readints()
    
    
    return A, B, K

def solve(Problem, Prep):
    @memoize
    def Dive(A, B, K):
        if len(A) == 0:
            return 1
        count = 0
        if K[0] == "1":
            if A[0] == "1" and B[0] == "1":
                count += Dive(A[1:], B[1:], K[1:])  # choose 111
                count += Dive("1" * (len(A)-1), B[1:], "1" * (len(K)-1)) #chose 011
                count += Dive(A[1:], "1" * (len(B) - 1), "1" * (len(K)-1)) #chose 101
                count += Dive("1" * (len(A)-1), "1" * (len(B)-1), "1" * (len(K)-1)) #chose 000

            if A[0] == "0" and B[0] == "1":
                count += Dive(A[1:], B[1:], "1" * (len(K)-1)) #chose 011
                count += Dive(A[1:], "1" * (len(B)-1), "1" * (len(K)-1)) #chose 000
            
            if A[0] == "1" and B[0] == "0":
                count += Dive(A[1:], B[1:], "1" * (len(K)-1)) #chose 101
                count += Dive("1" * (len(A)-1), B[1:], "1" * (len(K)-1)) #chose 000
            
            if A[0] == "0" and B[0] == "0":
                count += Dive(A[1:], B[1:], "1" * (len(K)-1)) #chose 000

        if K[0] == "0":
            if A[0] == "0" and B[0] == "0":
                count += Dive(A[1:], B[1:], K[1:])  # choose 000
            if A[0] == "0" and B[0] == "1":
                count += Dive(A[1:], "1" * (len(B)-1), K[1:])  # choose 000
                count += Dive(A[1:], B[1:], K[1:])  # choose 010
            if A[0] == "1" and B[0] == "0":
                count += Dive("1" * (len(A)-1), B[1:], K[1:])  # choose 000
                count += Dive(A[1:], B[1:], K[1:])  # choose 100
            if A[0] == "1" and B[0] == "1":
                count += Dive("1" * (len(A)-1), "1" * (len(B)-1), K[1:])  # choose 000
                count += Dive(A[1:], "1" * (len(B)-1), K[1:])  # choose 100
                count += Dive("1" * (len(B)-1), B[1:], K[1:])  # choose 010
        
        return count
    
    A, B, K = Problem
    
    K = K - 1
    A = A - 1
    B = B - 1

    A = bin(A)[2:]
    B = bin(B)[2:]
    K = bin(K)[2:]
    
    L = max(len(A), len(B), len(K))
    
    A = "0" * (L - len(A)) + A
    B = "0" * (L - len(B)) + B
    K = "0" * (L - len(K)) + K
    
    return Dive(A, B, K)


if __name__ == "__main__":
    doit(preprocess, readinput, solve, MultiCore = False, Verify = False, Input = SMALL, Filename = None, Problem = "B", Attempt = 0)
