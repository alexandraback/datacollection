import sys, math

f = open(sys.argv[1])
T = int(f.readline())
for t in range(T):
    X, Y = map(int, f.readline().strip().split())
    output = []
    if X >= 0: S = "WE"
    else: S = "EW"
    for ii in range(int(math.fabs(X))): output.append(S)
    if Y >= 0: S = "SN"
    else: S = "NS"
    for ii in range(int(math.fabs(Y))): output.append(S)


    print "Case #%d:" % (t + 1), "".join([elem for elem in output])
