import sys

f = open(sys.argv[1], 'r')
T = int(f.readline())
for case in range(0, T):
    (E, R, N) = [int(x) for x in f.readline().split()]
    activity = [int(x) for x in f.readline().split()]
    
    temp = [[0 for e in range(0, E+1)] for n in range(0, N)]
    
    # fill in last column
    for e in range(1, E+1):
        temp[N - 1][e] = e * activity[N -1]

    # fill in prior columns
    for n in range(N - 2, -1, -1):
        for e in range(1, E+1):
            best = -1
            for x in range(0, e+1):
                remaining_energy = min(e - x + R, E)
                val = x * activity[n] + temp[n+1][remaining_energy]
                best = max(best, val)
            temp[n][e] = best

    print "Case #%d: %d" % (case + 1, temp[0][E])
