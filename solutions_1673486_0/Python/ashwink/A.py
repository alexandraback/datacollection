import sys

f = open(sys.argv[1], 'r')
T = int(f.readline())
for case in range(0, T):
    (A, B) = [int(x) for x in f.readline().split()]
    p_list = [float(x) for x in f.readline().split()]
    E = 0

    # give up immediately is one option
    E = 1 + (B + 1)

    # to support this q will denote the odds of the first
    # n characters being typed correctly
    q = 1
    for p in p_list:
        q *= p

    # here, q denotes the odds that everything so far
    # has been typed correctly

    # keep typing and hope for the best is another option
    E = min(E, q * (B - A + 1) + (1 - q) * (B - A + 1 + (B + 1)))

    for backspace in range(1, A + 1):
        q = 1
        for i in range(A - backspace):
            q *= p_list[i]
        E = min(E, q * (B - A + backspace * 2 + 1) + (1 - q) * (B - A + backspace * 2 + 1 + (B + 1)))   

    print "Case #%d: %6f" % (case + 1, E)
