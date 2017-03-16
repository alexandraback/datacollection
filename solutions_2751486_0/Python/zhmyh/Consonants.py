from sys import stdin

def count(n, lpos, ncons, rpos):
    nsub = lpos*(rpos+ncons-n)
    i = 0
    while ncons-i >= n:
        nsub += rpos+ncons-i-n
        i += 1
    return nsub

vowels = ['a', 'e', 'i', 'o', 'u']
T = int(stdin.readline())
t = 0

while t < T:
    t += 1
    (name, n) = stdin.readline().split()
    n = int(n)
    N = 0
    L = len(name)
    ncons = 0
    LastLeft = 0
    for i in xrange(L):
        if name[i] not in vowels:
            ncons += 1
        else:
            ncons = 0
        if ncons >= n and (i+1==L or name[i+1] in vowels):
            N += count(n, i-ncons+1-LastLeft, ncons, L-i)
            LastLeft = i-n+2
    print "Case #%d: %d" % (t, N)
