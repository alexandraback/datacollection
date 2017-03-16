#!/usr/bin/python

from __future__ import division

import sys, os, subprocess, time, ctypes

def line():
    return sys.stdin.readline().strip()

def doit():
    #return debug()
    N = int(line())
    for i in range(N):
        print 'Case #%d:' % (i+1),
        res = go()
        print res

def debug():
    #print count(2,1,1000000)
    #return
    for A in range(1, 4):
        for B in range(1, 20):
            print A, B, domakkelijk(A,B,1000000000), count(A,B,1000000000)

def makkelijk():
    A, B, K = map(int, line().split())
    domakkelijk(A,B,K)

def domakkelijk(A,B,K):
    return sum((a&b) < K
        for a in range(A)
            for b in range(B))

cache = {}
def count(A, B, K):
    r = cache.get((A,B,K))
    if r is not None:
        return r
    '''Calc result for ranges'''
    if K<1: return 0
    res = 0
    for topbit in range(1,30):
        #print 'topbit %d' % topbit
        # topbit is set in A
        # for A, this is the highest bit set

        val = 1<<topbit
        if A-1 < val: break

        # case 1: bit set in B and K
        nrA = min(val, A-val)

        nFullB = B >> (topbit+1) # zoveel situaties waarbij B de hele range heeft
        nrB = val

        nrK = min(val, K-val)

        res += nFullB * count(nrA, nrB, nrK)

        # situation where B  has part of the range:

        Bhastopbit = bool(val & B)
        aftertopbitB = B & (val-1)
        if Bhastopbit:
            res += count(nrA, aftertopbitB, nrK)
        #print 'res after this bit: %d' % res

        # case 2: bit unset in B and thus K
        nrK = min(val, K)

        # B hele range:
        fullB = ((B >> topbit) + 1) // 2
        res += fullB * count(nrA, val, nrK)
        # B gedeelte:
        if not Bhastopbit:
            res += count(nrA, aftertopbitB, nrK)

    # Topbit 0, aka: a == 1, b is odd, k >= 2
    if not (A-1 < (1<<0)):
        # case 1
        if K>1:
            res += B >> 1
        # case 2: b is even
        res += (B+1) >> 1

    #print 'res after topbit 0: %d' % res

    # A is zero
    res += B # you always win regardless of B

    #print 'res after zero: %d' % res

    cache[(A,B,K)] = res
    return res

def go():
    A, B, K = map(int, line().split())
    return count(A,B,K)

def compileIfNeeded():
    letter, _, _ = os.path.basename(sys.argv[0]).partition('.')
    cpp = '%s.cpp' % letter
    if os.path.exists(cpp):
        print 'Compling...'
        subprocess.check_call('g++ -Wall -g -O3 -fPIC %s -shared -o lib.so' % cpp,
            shell=True)

def main():
    if len(sys.argv) > 1:
        return doit()

    compileIfNeeded()

    files = []
    for fn in os.listdir('.'):
        if fn.endswith('.in'):
            files.append((os.path.getmtime(fn), fn))
    fn = max(files)[1]

    root = fn[:-2]
    with open(fn) as fdin:
      with open(root+'result', 'wb') as fdout:
        start = time.time()
        print 'Running...'
        subprocess.check_call([__file__, 'doit'],
                stdin=fdin,
                stdout=fdout)
        print 'Done in %.3fs' % (time.time()-start)
    print 'Diffing...'
    subprocess.call(['diff', '-sdu', root+'out', root+'result'])

if __name__ == '__main__':
    main()
