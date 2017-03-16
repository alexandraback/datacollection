#! /usr/bin/python -tt

f = open('out', 'w')
t = input()

cycle = [[] for i in range(2000001)]
for i in range(1, 2000001):
    si = str(i)
    length = len(si)
    for j in range(1, length):
        cyc_si = si[j:] + si[:j]
        if cyc_si[0] == '0':
            continue
        cycle[i].append(int(cyc_si))
n_pair = [0, 0, 1, 3, 6, 10, 15, 21, 28]
#print cycle[:100]

for case in range(1, t+1):
    aLine = raw_input()
    aLine = aLine.split()
    a = int(aLine[0])
    b = int(aLine[1])
    used = [True for i in range(b+1)]
    ans = 0
    for n in range(a, b+1):
        if used[n] == False:
            continue
        used[n] = False
        pairCount = 1
        for nn in cycle[n]:
            if nn >= a and nn <= b and used[nn] == True:
                used[nn] = False
                pairCount += 1
        ans += n_pair[pairCount]
        #print 'n =', n, ', paircount =', pairCount
    f.write("Case #%d: %d\n" % (case, ans))
