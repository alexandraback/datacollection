def cookie_nr(factory_cost, FCps, win):
    Cps = 2.0
    curr_time = 0.0
    win_time = win/Cps
    factory_win_time = float('inf')

    while True:
        win_time = curr_time + win/Cps
        factory_time = factory_cost/Cps
        factory_win_time = curr_time + factory_time + win/(Cps+FCps)
        if win_time < factory_win_time:
            return win_time
        Cps += FCps
        curr_time += factory_time

if __name__ == "__main__":
    ntests = int(raw_input())
    for i in xrange(ntests):
        params = raw_input().strip().split()
        C, F, X = (float(x) for x in params)
        print "Case #%d: %.7f" % (i+1, cookie_nr(C, F, X))
