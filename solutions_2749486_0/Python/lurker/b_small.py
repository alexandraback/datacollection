import sys
rl = raw_input
T = int(rl())


for case in xrange(T):
    X, Y = map(int, rl().split())
    cum = ""
    if X > 0:
        cum += "WE" * abs(X)
    elif X < 0:
        cum += "EW" * abs(X)
    if Y > 0:
        cum += "SN" * abs(Y)
    elif Y < 0:
        cum += "NS" * abs(Y)

    print "Case #%d: %s" %(case+1, cum)
