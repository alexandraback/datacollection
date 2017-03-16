def inst(sorted, a):
    for i in range(len(sorted)):
        if a <= sorted[i]:
            sorted.insert(i, a)
            return
    sorted.insert(len(sorted), a)
    return


N = int(raw_input())
for i in range(N):
    D = int(raw_input())
    P = [int(a) for a in raw_input().split()]
    counter = max(P)
    share = 2
    while share < counter:
        dispatch = sum([(a-1)//share for a in P])
        counter = min(counter, dispatch+share)
        share = share+1
    print 'Case #' + str(i + 1) + ': ' + str(counter)
