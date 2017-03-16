#!/usr/bin/python

from __future__ import division

import sys, os, subprocess, time, ctypes

NOTHING = ()

def line():
    return sys.stdin.readline().strip()

def doit():
    N = int(line())
    for i in range(N):
        print 'Case #%d:' % (i+1),
        res = go()
        if res != NOTHING:
            print res

def go():
    N = int(line())
    Na = map(float, line().split())
    Ke = map(float, line().split())

    return '%s %s' % (vals(Na, Ke), eerlijk(Na, Ke))

def eerlijk(Na, Ke):

    Ke = set(Ke)
    pts = 0
    for n in Na:
        heavier = [k for k in Ke if k>n]
        if heavier:
            Ke.remove(min(heavier))
        else:
            Ke.remove(min(Ke))
            pts += 1
    return pts

def vals(Na, Ke):
    '''
    for x in sorted(Na+Ke):
        print x, ('N' if x in Na else 'K')
    '''

    Ke = set(Ke)
    pts = 0
    for n in sorted(Na):
        if n > min(Ke):
            pts += 1
            Ke.remove(min(Ke))
        else:
            # cheat by playing away max
            Ke.remove(max(Ke))
    return pts

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
    subprocess.call(['diff', '-du', root+'out', root+'result'])

if __name__ == '__main__':
    main()
