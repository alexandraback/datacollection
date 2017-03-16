def cases(solver):
    n = int(raw_input())
    for case in range(n):
        print "Case #{}: {}".format(case+1, solver(raw_input()))
