import sys

cases = sys.stdin.readlines()

for t in range(1, len(cases)):
    A, B = cases[t].split()
    recycled = 0
    length = len(A)
    A = int(A)
    B = int(B)
    # range [A, B) is nor a mistake since n < m
    for n in range(A, B):
        used = {}
        for d in range(1, length):
            mul = 10**d
            shift = n % mul
            new = n // mul + shift * 10**(length - d)
            if A <= new and n < new and new <= B and not new in used:
                used[new] = True
                recycled += 1
    print('Case #', t, ': ', recycled, sep='')
