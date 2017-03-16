T = int(raw_input())

for i in range(T):
    (C, F, X) = [float(x) for x in raw_input().split()]
    cps = 2.0
    spend_time = 0.0

    while True:
        no_farm = X/cps
        farm = C/cps + X/(cps + F)
        if no_farm <= farm:
            spend_time += no_farm
            break
        else:
            spend_time += C/cps
            cps += F

    print 'Case #%d: %.7f' % ((i+1), spend_time)
