import sys, re
import numpy as np



def solve(a, b, k):
    M = np.indices((a, b))
    return a * b - (M[0] & M[1] >= k).sum()

def main(filename):
    with open(filename) as f_in:
        N = int(f_in.readline())
        for i in range(1, N+1):
            A, B, K = map(int, f_in.readline().strip().split(' '))
            print( 'Case #{0}: {1}'.format(i, solve(A, B, K)))
            

if __name__ == "__main__":
    main(sys.argv[1])
