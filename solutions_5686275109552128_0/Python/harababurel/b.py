for t in range(0, input()):
    n = input()
    v = sorted(list(map(int, raw_input().split())))

    sol = max(v)

    for target in range(1, max(v) + 1):
        specialMinutes = 0

        for x in v:
            if x <= target: continue
            specialMinutes += x // target + (x % target != 0) - 1

        sol = min(sol, target + specialMinutes)
        #print "Ca sa ajung la target = %i, am costul total %i" % (target, target+specialMinutes)

    print "Case #%i: %i" % (t+1, sol)
