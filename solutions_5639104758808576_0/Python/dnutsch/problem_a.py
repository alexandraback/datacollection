#1/usr/bin/python

f = open('A-small-attempt0.in','r');
out = open('A-small.out','w');
N = int(f.readline().strip())

for n in xrange(0,N):
    smax,S = f.readline().strip().split(' ')
    s= [int(c) for c in S]
    total = 0
    cumulative = []
    for i in xrange(0,len(s)):
        total += s[i]
        cumulative.append(total)

    max_toadd = 0
    for i in range(len(s)-1, 0, -1):
        toadd = i - cumulative[i-1]
        max_toadd = max(toadd, max_toadd)

    out.write( "Case #{}: {}\n".format(n+1,max_toadd))

f.close()
out.close()

