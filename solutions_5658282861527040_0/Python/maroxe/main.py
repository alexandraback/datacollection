import sys

def to_bin(i):
    return map(lambda x: True if x == '1' else False, bin(i)[2:].zfill(30))

def process(A, B, K, pA=False, pB=False, pK=False, i=0):
    if i >= 30: return 1 if (pA and pB and pK) else 0
    r = 0
    if K[i] or pK: # ki = 1
        if (A[i] or pA) and (B[i] or pB):
            r += process(A, B, K, pA, pB, pK, i+1)
    # ki = 0     
    # 0 0
    r += process(A, B, K, pA or A[i], pB or B[i], K[i] or pK, i+1)
    #  1 0
    if A[i] or pA:
        r += process(A, B, K, pA, pB or B[i], K[i] or pK, i+1)
    # 0 1
    if B[i] or pB:
        r += process(A, B, K, pA or A[i], pB, K[i] or pK, i+1)
    return r

def resolve(A, B, K):
    A, B, K = map(to_bin, (A, B, K))
    return process(A, B, K)

input_file = sys.stdin
output_file = open('output', 'w')

T = int(input_file.readline())

for i in range(1, T + 1):
    
    A, B, K = map(int, input_file.readline().split())
    sol = 'Case #%d: %s\n' % (i, resolve(A, B, K))
    
    print sol
    output_file.write(sol)


    

