# IO file paths
file_in = "B-small-attempt0.in"
file_out = "B-small-attempt0.out"

import math

# Solves the deceitful war problem
def Solve(A, B, K):
    count = 0
    for i in range(0, A):
        for j in range(0, B):
            r = int(i & j)
            if r < K:
                count = count + 1
    return count

# Reads the input data and runs the test cases
def Run():
    fin = open(file_in, 'r')
    fout = open(file_out, 'w')

    lines = []
    for l in fin:
        lines.append(l)

    i = 0
    T = int(lines[0])
    i = i + 1
    for t in range(0, T):
        ABK = lines[i].rstrip().split(' ')
        i = i + 1
        A, B, K = int(ABK[0]), int(ABK[1]), int(ABK[2])
        result = str(Solve(A, B, K))
        fout.write("Case #" + str(t + 1) + ": " + result + '\n')
        
    fin.close()
    fout.close()
    

def main():
    Run()

if __name__ == "__main__":
    main()
