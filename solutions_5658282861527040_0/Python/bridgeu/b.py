import sys
r = sys.stdin.readline

T = int(r())

def calculate(A,B,K):
    Ab = bin(A)[2:]
    count = 0
    for a in range(A):
        for b in range(B):
            if (a & b) < K:
                count += 1
    return count

for i in range(T):
    A,B,K = map(int, r().split())

    result = calculate(A,B,K)
    print("Case #%d: %i" % (i+1, result))
