import numpy as np

rfile = file('TEST.in', 'r')
wfile = file('Q2small.out', 'w')
num_of_cases = int(rfile.readline().strip())
for case in range(1, num_of_cases+1):
    print case
    #Do case number 'case'
    A, B, K = map(int, (rfile.readline().strip().split(' ')))
    many = 0
    if A > B:
        temp = A
        A = B
        B = temp
    if K> A:
        K = A
    for a in range(A):
        for b in range(B):
            if a&b < K:
                many += 1

    print 'many = ',many
    #write result
    to_write = str(many)
    wfile.write('Case #'+str(case)+': '+to_write+'\n')
