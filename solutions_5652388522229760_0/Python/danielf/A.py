def doit(N):
    view = [False]*10
    nview = 0
    k = 0
    while nview < 10:
        k += 1
        s = [ord(x) - ord('0') for x in str(k*N)]
        for i in s:
            if not view[i]:
                nview += 1
                view[i] = True
    return k*N

T = int(input())
for i in range(T):
    x = int(input())
    if x == 0: print("Case #%d: INSOMNIA" % (i+1,))
    else: print("Case #%d: %d" % (i+1, doit(x)))
