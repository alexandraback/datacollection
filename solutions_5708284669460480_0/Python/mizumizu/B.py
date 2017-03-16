import sys
import collections
import math
import itertools

        
def rl():
    return tuple(map(int, raw_input().strip().split()))

def dup_perms(seq, rep):
    for p in itertools.product(seq, repeat=rep):
        yield p
        
def solve(KLS, keys, target):
    #print '====== ' + str(locals())
    L = KLS[1]
    S = KLS[2]
    ins = []
    ss = [''.join(s) for s in dup_perms(keys, S)]
    for s in ss:
        ii = 0
        for i in xrange(S-L+1):
            if s[i:i+L] == target:
                ii += 1
        if ii > 0:
            ins.append(ii)
    #print ins
    max_ins = 0
    exp = 0.0
    for ii in ins:
        exp += ii / float(len(ss))
        if ii > max_ins:
            max_ins = ii
    return max_ins-exp

if __name__ == '__main__':
    for case in range(int(raw_input())):
        print 'Case #%d: %f' % (case+1, solve(rl(), raw_input().strip(), raw_input().strip()))