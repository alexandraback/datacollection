import codejam as gcj

T = gcj.read_input('i')
for t in range(T):
    A, N, S = gcj.read_input('i i', 'i[<]')

    best, added = N, 0
    for i, m in enumerate(S):
        remove_rest = N - i
        if added + remove_rest < best:
            best = added + remove_rest

        if m < A:   # We can eat it
            A += m  
        else:       # We can't eat it
            for i in range(N + 1):
                added += 1
                A += (A - 1)
                if m < A:
                    A += m
                    break

    print "Case #%d:" % (t + 1), min(best, added)
