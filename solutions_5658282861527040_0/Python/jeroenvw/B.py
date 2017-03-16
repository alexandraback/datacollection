#!/usr/bin/python

from __future__ import division

import sys, os, subprocess, time, ctypes

def line():
    return sys.stdin.readline().strip()

def doit():
    N = int(line())
    for i in range(N):
        print 'Case #%d:' % (i+1),
        res = go()
        print res

def go():
    A, B, K = map(int, line().split())
    return sum((a&b) < K
        for a in range(A)
            for b in range(B))

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
