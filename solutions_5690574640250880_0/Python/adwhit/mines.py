import sys
import math

lines = [line.strip() for line in open(sys.argv[1])]
nrounds = int(lines[0])
vals = [[int(x) for x in line.split()] for line in lines[1:]]

def fill(R,C,M):
    arr = [[False] * C  for _ in range(R)]
    if C * R - M == 1:
        win = [[True] * C for _ in range(R)]
        win[R-1][C-1] = False
        return win
    while M>0:
        if (R == 2 and M % 2 != 0) or (C == 2 and M % 2 != 0) or (C == 2 and R == 2):
            return None
        if M == C -1 and M == R -1:
            #endgame, with a square
            if M == 1 or M == 2:
                return None
            arr = fill_row(arr, M-1)
            return fill_col(arr, 1)
        else:
            if C > R:
                if M != R - 1:
                    m = min(R,M)
                    arr = fill_col(arr, m)
                    M -= m
                    C -= 1
                else:
                    m = min(C,M)
                    arr = fill_row(arr, m)
                    M -= m
                    R -= 1
            else:
                if M != C -1:
                    m = min(C,M)
                    arr = fill_row(arr, m)
                    M -= m
                    R -= 1
                else:
                    m = min(R,M)
                    arr = fill_col(arr, m)
                    M -= m
                    C -= 1
    return arr

def fill_row(arr, M):
    #print "filling rows with %d mines" % M
    ct = 0
    for i in range(len(arr)):
        for j in range(len(arr[0])):
            if not arr[i][j]:
                arr[i][j] = True
                ct += 1
                if ct == M:
                    return arr

def fill_col(arr,M):
    #print "filling cols with %d mines" % M
    ct = 0
    for j in range(len(arr[0])):
        for i in range(len(arr)):
            if not arr[i][j]:
                arr[i][j] = True
                ct += 1
                if ct == M:
                    return arr

def print_board(arr):
    if arr:
        ct = len(arr) * len(arr[0])
        for a in arr:
            for b in a:
                if b:
                    sys.stdout.write("*")
                    ct -= 1
                elif ct == 1:
                    sys.stdout.write("c")
                else:
                    sys.stdout.write(".")
                    ct -= 1
            print
    else:
        print "Impossible"

for (ix,val) in enumerate(vals):
    print "Case #%d:" % (ix+1)
    print_board(fill(*val))
            

