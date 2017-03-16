__author__ = 'jin-yc10'

import sys
sys.stdout = open('1.out', 'w')

s = """4
2 3 3 1
1 2 3 2
1 1 3 2
1 2 3 1
""".split('\n')

s = open("C-small-attempt1.in","r").read().split('\n')

# Case #1: 1
# 1 1 1
# Case #2: 4
# 1 1 2
# 1 2 3
# 1 2 1
# 1 1 1
# Case #3: 2
# 1 1 2
# 1 1 1
# Case #4: 2
# 1 1 3
# 1 2 1

t = int(s[0])
for i in xrange(t):
    tt = [int(x) for x in s[i+1].split()]
    J = tt[0]
    P = tt[1]
    S = tt[2]
    K = tt[3]
    # print J,P,S,K
    a = [J,P,S]
    pick = [1,1,1]
    p1 = -1
    p2 = -1
    p3 = -1 # => modified
    m = max(a)
    if not K > m:
        mi = [ii for ii, jj in enumerate(a) if jj == m]
        pick[mi[0]] = 0
        if mi[0] == 0:
            p1 = 1
            p2 = 2
            p3 = 0
        elif mi[0] == 1:
            p1 = 0
            p2 = 2
            p3 = 1
        elif mi[0] == 2:
            p1 = 0
            p2 = 1
            p3 = 2
        res = a[p1]*a[p2]*K
        rest = 0
        res_array = []
        # print "Case #%d: %d"%(i+1,res)
        # print a, "K=", K
        d1 = {}
        d2 = {}
        for j in xrange(a[p1]):
            for k in xrange(a[p2]):
                cnt = 0
                for l in xrange(a[p3]):
                    if (j+1,l+1) not in d1:
                        d1[(j+1,l+1)] = 0
                    if (k+1,l+1) not in d2:
                        d2[(k+1,l+1)] = 0
                    if d1[(j+1,l+1)] < K and d2[(k+1,l+1)] < K:
                        d1[(j+1,l+1)] += 1
                        d2[(k+1,l+1)] += 1
                        res_array += [ "%d %d %d" % (j+1, k+1, l+1) ]
                        cnt += 1
                        rest += 1
                    if cnt == K:
                        break
        # print d1
        # print d2
        print "Case #%d: %d"%(i+1,rest)
        for resA in res_array:
            print resA
    else:
        print "Case #%d: %d"%(i+1,J*P*S)
        # full
        for j in xrange(J):
            for k in xrange(P):
                for l in xrange(S):
                    print j+1,k+1,l+1

