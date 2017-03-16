T = int(raw_input())

for case in range(T):
    line = raw_input().split()
    N = int(line[0])
    s_i = [int(i) for i in line[1:]]
    X = 2 * sum(s_i)
    X_actual, N_actual = X, N
    #print N, s_i, X
    a = "Case #{0}:".format(case+1)
    for i in s_i:
        if i > float(X)/N:
            X_actual -= i
            N_actual -= 1
    #print X_actual, N_actual, X, N
    for i in s_i:
        c = round(100*(2.0*X_actual/X/N_actual - i*2.0/X), 6)
        if c < 0.0:
            c = 0.0
        a += " {0:.6f}".format(c)
    print a
