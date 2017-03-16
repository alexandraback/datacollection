inf = open('./input.txt', 'r')

T = int(inf.readline())


def readline():
    row = inf.readline()
    row = [float(num) for num in row.split(' ')]
    return row


def calc_time(C, F, X, CPS, SEC):
    sec_gorl = SEC + (X / CPS)
    sec_farm = calc_time(C, F, X, CPS + F, SEC + (C / CPS))
    if sec_farm < sec_gorl:
        return sec_gorl
    return sec_farm


def testcace(t):
    line = readline()
    C = line[0]
    F = line[1]
    X = line[2]
    CPS = 2.0
    SEC = 0.0

    while True:
        NOW = X / CPS
        ADDFARM = (C / CPS) + (X / (CPS + F))
        if NOW < ADDFARM:
            break
        SEC = SEC + (C / CPS)
        CPS = CPS + F

    print "Case #%d: %f" % (t, NOW + SEC)

for t in range(T):
    testcace(t + 1)
