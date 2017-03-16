#!/usr/bin/env python

s = 'ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv'

ss = 'ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup'

d = {' ': ' '}
for i in range(len(s)):
    x = s[i]
    assert (x not in d or d[x] == ss[i])
    d[x] = ss[i]
d['z'] = 'q'
d['q'] = 'z'

T = int(raw_input())
for t in range(T):
    y = raw_input()
    print 'Case #%d: %s' % (t+1, ''.join(map(lambda x: d[x], y)))
