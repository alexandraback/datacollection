#!/usr/bin/python

from __future__ import division

import sys, os, subprocess, time, ctypes

NOTHING = ()

def line():
    return sys.stdin.readline().strip()

def doit():
    N = int(line())
    for i in range(N):
        print 'Case #%d: ' % (i+1),
        res = go()
        if res != NOTHING:
            print res

def go():
    R, C, M = map(int, line().split())
    print ''
    sys.stdout.flush()
    ctypes.CDLL('./lib.so').solve(R,C,M)
    sys.stdout.flush()
    return NOTHING

def compileIfNeeded():
    letter, _, _ = os.path.basename(sys.argv[0]).partition('.')
    cpp = '%s.cpp' % letter
    if os.path.exists(cpp):
        print 'Compling...'
        subprocess.check_call('g++ -Wall -g -O3 -fPIC %s -shared -o lib.so' % cpp,
            shell=True)

def main():
    if len(sys.argv) > 1:
        if sys.argv[1] == 'debug':
            compileIfNeeded()
            C = R = 50
            for m in range(C*R):
                print R, C, m
                ctypes.CDLL('./lib.so').solve(R,C,m)

            for C in range(1, 30):
                for R in range(1, 30):
                    if C*R > 25: break
                    for m in range(C*R):
                        print R, C, m
                        ctypes.CDLL('./lib.so').solve(R,C,m)
            return
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
    subprocess.call(['diff', '-du', root+'out', root+'result'])

if __name__ == '__main__':
    main()
