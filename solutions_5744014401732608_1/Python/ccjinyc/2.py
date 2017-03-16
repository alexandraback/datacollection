__author__ = 'jin-yc10'

import sys
sys.stdout = open('1.out', 'w')

s = """3
5 4
2 1
4 20
""".split('\n')

s = open("B-large.in","r").read().split('\n')

# Case #1: POSSIBLE
# 01001
# 00110
# 00001
# 00101
# 00000
# Case #2: POSSIBLE
# 01
# 00
# Case #3: IMPOSSIBLE

t = int(s[0])
for i in xrange(t):
    tt = s[i+1].split()
    B = int(tt[0])
    M = int(tt[1])
    # print B, M
    if M > 2**(B-2):
        print "Case #%d: IMPOSSIBLE"%(i+1)
    else:
        # split M
        print "Case #%d: POSSIBLE"%(i+1)
        tM = M-1
        sM = []
        mat = [[0 for jj in xrange(B)]for j in xrange(B)]
        for j in xrange(B-1):
            for k in xrange(B-1):
                if k > j:
                    mat[j][k] = 1
        for l in xrange(B):
            if tM == 0:
                break
            elif tM % 2 == 1:
                mat[l+1][B-1] = 1
            tM /= 2
        mat[0][B-1] = 1
        for l in mat:
            print ''.join([str(ll)for ll in l])
