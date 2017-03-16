
import sys

for tn in range(int(sys.stdin.readline().strip())):
    [C, F, X] = map(float, sys.stdin.readline().strip().split())
    
    rate = 2.0
    buy_time = 0.0
    best = X / rate
    
    while True:
        buy_time += C/rate
        rate += F
        t = buy_time + X/rate
        if (t > best):
            break

        best = t
    
    print 'Case #%d: %.9g' % ((tn+1), best)
