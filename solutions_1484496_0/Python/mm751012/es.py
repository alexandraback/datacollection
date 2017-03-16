import sys

rl = lambda: sys.stdin.readline().strip()

for case in range(int(rl())):
    tmp = map(int, rl().split())
    N = tmp[0]
    S = tmp[1:]
    print "Case #%d:" % (case+1)
    
    subs = [None]*(2**N)
    sums = [0]*(2**N)
    f = False
    for i in xrange(2**N):
        bin = ('0'*N + format(i, 'b'))[-N:]
        subs[i] = []
        for j in range(N):
            if bin[j]=='1':
                subs[i].append(S[j])
        sums[i] = sum(subs[i])
        for j in range(i):
            if sums[i]==sums[j]:
                print ' '.join(map(str,subs[i]))
                print ' '.join(map(str,subs[j]))
                f = True
                break
        if f:
            break
        
    
    if not f:
        print 'Impossible'