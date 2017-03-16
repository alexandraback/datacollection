import sys, operator

f = open(sys.argv[1])
T = int(f.readline())
for t in range(T):
    A, B = map(int, f.readline().split())
    probs = map(float, f.readline().split())
    output = float(B + 2)
    prob_correct = 1
    for ii in range(A + 1):
        num_backspaces = A - ii
        if num_backspaces != A:
            prob_correct *= probs[(A-num_backspaces - 1)]
        poss_output = (prob_correct * (2*num_backspaces+B+1-A) + (1-prob_correct) * (2*num_backspaces+2*(B+1)-A))
        output = min(output, poss_output)
    print "Case #%d:" % (t + 1), 
    print "%.6f" % output

