# Cookie Clicker Alpha


def rate(F, n_farms):
    ' rate of cookies per second '
    return 2.0 + (F * n_farms)


def time_to_go(X, rate):
    ' at rate, how long to get X cookies '
    return X / rate


def get_cookies(C, F, X):
    time = 0
    farms = 0

    while True:
        time_to_X = time_to_go(X, rate(F, farms))
        time_with_extra_farm = time_to_go(C, rate(F, farms)) + \
                time_to_go(X, rate(F, farms + 1))
        if time_to_X <= time_with_extra_farm:
            time = time + time_to_X
            return "%0.7f" % time
            break
        time = time + time_to_go(C, rate(F, farms))
        farms = farms + 1


with open('B-small-attempt0.in.txt', 'r') as fin, open('B-small.out.txt', 'w') as fout:
    fin.readline()
    for n, line in enumerate(fin):
        output = "Case #%d: " % (n + 1)
        C, F, X = tuple(map(float, line.split()))
        output = output + get_cookies(C, F, X)
        fout.write(output + '\n')
