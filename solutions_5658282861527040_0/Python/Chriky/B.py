import codejam as gcj

T = gcj.read_input('i')
for t in range(T):
    A, B, K = gcj.read_input('i i i')
    digits = bin(K)[2:]
    total = 0
    for a in range(A):
        for b in range(B):
            if a & b < K:
                total += 1

    print 'Case #%i:' % (t + 1), total