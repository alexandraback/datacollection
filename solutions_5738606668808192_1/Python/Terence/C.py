def coinjam(n,k):
    d = [b**(n/2)+1 for b in range(2,11)]
    ds = map(str,d)
    assert((n & 1) == 0 and k < 2**(n/2-2))
    for i in range(2**(n/2-1)+1,2**(n/2-1)+2*k+1,2):
        s = bin(i)[2:]
        print ' '.join([s+s]+ds)
t = int(raw_input())
for icase in range(1,t+1):
    n,k = map(int,raw_input().split())
    print 'Case #%d:' % icase
    coinjam(n,k)