import sys

f = open(sys.argv[1])
T = int(f.readline())
for t in range(T):
    A, B = map(int, f.readline().split())
    p = map(float, f.readline().split())
    partial = [reduce(lambda x, y: x * y, p[:i + 1]) for i in range(len(p))]
    costs = []
    for i in range(A):
        delete_presses = i
        complete_presses = B - (A - i)
        presses = delete_presses + complete_presses + 1
        j = A - 1 - i
        costs += [partial[j] * presses + (1 - partial[j]) * (B + 1 + presses)]
    print "Case #%d:" % (t + 1), min(costs + [B + 2])
