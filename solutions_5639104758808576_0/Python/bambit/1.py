inp = open('1.test')

T = int(inp.readline().rstrip())
for t in range(1,T+1):
    smax, sv = inp.readline().rstrip().split()
    s = map(int, sv)
    psums = s[:]
    psums[0] = 0
    for i in range(1, len(s)):
        psums[i] = psums[i-1] + s[i-1]

    print 'Case #%d: %d' % (t, max(i-psums[i] for i in range(len(s))))
