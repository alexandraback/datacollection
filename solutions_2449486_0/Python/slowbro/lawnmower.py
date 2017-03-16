import sys
import numpy as np

def solve(B):
    B = np.array(B)
    N, M = B.shape
    max_of_rows = np.max(B, axis=1) #N of them
    max_of_cols = np.max(B, axis=0) #M of them

    for ii in range(N):
        for jj in range(M):
            if (B[ii,jj] < max_of_rows[ii]) and (B[ii,jj] < max_of_cols[jj]):
                return 'NO'
    return 'YES'

if __name__ == '__main__':
    fh = open(sys.argv[1])
    T = int(fh.readline().strip())
    for ii in range(1, T+1):
        N, M = [int(v) for v in fh.readline().strip().split()]
        B = []
        for jj in range(N):
            B.append([int(v) for v in fh.readline().strip().split()])
        output = solve(B)
        print "Case #{}: {}".format(ii, output)

