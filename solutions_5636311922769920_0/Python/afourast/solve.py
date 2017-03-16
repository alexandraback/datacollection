def my_int(st,base):
    cnt = 0
    for i,c in enumerate(reversed(st)):
        cc = int(c)
        cnt += cc*base**i

    return cnt

def solve():

    pool = range(K)

    if float(K)/float(C) > S:
        return None 

    if K == 1:
        return [1]

    sol = []

    a=0
    # b=min(C,K)
    b=0

    # print K,C,pool

    cnt=0

    while b<K:

        a = b
        b = min(b + C, K)

        ms = pool[a:b]
        # print ms,K
        c = my_int(ms,K)
        # print 'appending %s' %c
        sol.append(c+1)
        cnt+=1

    # print len(sol)
    return sol

T = int(raw_input())

for i in range(T):
    K,C,S = map(int,raw_input().split())
    sol = solve()
    if sol is None:
        sol = 'IMPOSSIBLE'
    else:
        sol = ' '.join(map(str,sol))
    print "Case #%d: %s"%(i+1,sol)



