import sys

inp = map(float, (' '.join(sys.stdin.read().splitlines())).split(' '))

N = inp[0]
for T in xrange(int(N)):
    C, F, X = inp[1+T*3:4+T*3]
    
    rate = 2.0
    time = 0.0
    while True:
        pred_no_farm = time + X / rate
        pred_farm    = time + C / rate + X / (rate + F)
        if pred_no_farm <= pred_farm:
            time = pred_no_farm
            break
        else:
            time += C / rate
            rate += F

    print "Case #%d: %.7f" % (T+1, time)
