import sys
from collections import defaultdict

# N = 10
# vals = {}
# vals[(1,) * N] = (0, [])
# q = [(1,) * N]
# m = 1
# n = 0
# while q:
#     q2 = []
#     vals2 = defaultdict(set)
#     print len(q)
#     for s in q:
#         for i in xrange(1, N + 1):
#             s2 = tuple(1 - i for i in s[:i]) + s[i:]
#             n += 1
#             #print n, s2

#             if s2 not in vals:
#                 if s2 not in vals2:
#                     q2.append(s2)
#                 vals2[s2].add(i)


#     vals.update({k: (m, sorted(v)) for k, v in vals2.iteritems()})
#     m += 1
#     q = q2

def calc(s):
    n = 0
    for i in xrange(1, len(s)):
        if s[i] != s[i-1]:
            n += 1
    n += s[-1] == 0
    return n

# for s, n in sorted(vals.iteritems()):
#     print s, calc(s), n
#     assert calc(s) == n[0]

T = int(sys.stdin.readline())
for i in xrange(T):
    s = tuple(c == '+' for c in sys.stdin.readline().strip())
    print 'Case #%d: %d' % (i + 1, calc(s))
