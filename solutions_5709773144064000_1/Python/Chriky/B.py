import codejam as gcj

T = gcj.read_input('i')
for t in range(T):
    C, F, X = gcj.read_input('f f f')

    time, rate = 0.0, 2.0
    while True:
        wait_time = X / rate
        buy_time = (C / rate) + (X / (rate + F))
        if wait_time < buy_time:
            time += wait_time
            break
        else:
            time += (C / rate)
            rate += F

    print 'Case #%i:' % (t + 1), time