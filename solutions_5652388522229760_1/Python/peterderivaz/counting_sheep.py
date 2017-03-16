def go(n):
    if n==0:
        return 'INSOMNIA'
    S=set()
    y = 0
    while len(S)<10:
        y += n
        for c in str(y):
            S.add(c)
    return y
        
T=input()
for t in range(1,T+1):
    print "Case #{}: {}".format(t,go(input()))
