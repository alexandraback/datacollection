T = int(raw_input())
# goto = [1, 10, 29, 138, 337, 1436, 3435, 14434, 34433]
t = [1, 9, 19, 109, 199, 1099, 1999, 10999, 19999, 109999, 199999, 1099999, 1999999, 10999999, 19999999]
s = 0
# v=.1
tt=[]
for i in t:
    s += i
    # v *= 10
    tt.append(s)
    # print s, v
for i in range(T):
    N = int(raw_input())
    Ns = str(N)
    Nt = map(int, list(Ns))
    rNs = Ns[::-1]
    rNt = map(int, list(rNs))
    cost = tt[len(Ns)-1]
    l = len(Ns)
    mincost = cost+N-10**(l-1)
    for j in range(l-1):
        add1 = int(rNs[l-j-1:])
        # print rNs[l-j-1:]
        rev = 1
        # print Ns[j+1:]
        add2 = int(Ns[j+1:])-1
        mycost = cost+add1+rev+add2
        if mycost < mincost:
            mincost = mycost
    print'Case #'+str(i+1)+': '+str(mincost)
