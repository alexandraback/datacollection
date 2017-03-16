import itertools

def f(A,B,K):
    # brute force
    s = 0
    for a in range(A):
        for b in range(B):
            if a & b < K:
                s += 1
    return s

T = int(input())
for i in range(T):
    A,B,K = map(int,input().split())
    print('Case #{}: {}'.format(i+1, f(A,B,K)))