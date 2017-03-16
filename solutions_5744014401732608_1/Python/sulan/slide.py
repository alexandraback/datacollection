import math
import sys
import collections

def print_result (case_num,result):
    print('Case #{}: {}'.format(case_num,result))

def fully_connect (matrix,n):
    for i in range(n):
        for j in range(i+1,n+1):
            matrix[i][j] = 1

def gen_m (B):
    return [[0 for j in range(B)] for i in range(B)]

FIBS = [(2,1),(3,2)]
while FIBS[-1][0] <= 50:
    FIBS.append((FIBS[-1][0]+1,FIBS[-2][1]+FIBS[-1][1]))
FIBSD = dict(FIBS)

T = int(input())
for case_num in range(1,T+1):
    B,M = map(int,input().split())
    if M > 2**(B-2):
        print_result(case_num,'IMPOSSIBLE')
        continue
    f = bin(M)[2:]
    n = len(f)
    assert n+1 <= B
    matrix = gen_m(B)
    fully_connect(matrix,n)
    if 2**(B-2) != M:
        for i,a in enumerate(f[::-1]):
            if a == '1':
                c = i+1 if i >0 else 0
                matrix[c][-1] = 1
    print_result(case_num,'POSSIBLE\n'+'\n'.join([''.join([str(b) for b in a]) for a in matrix]))
    assert(all([a == 0 for a in matrix[-1]]))
