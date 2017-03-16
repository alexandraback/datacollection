#!/usr/bin/python

from __future__ import division

import sys, os, subprocess
from pprint import pprint

def line():
    return FD.readline().strip()

def doit():
    checktrans()
    N = int(line())
    for i in range(N):
        print 'Case #%d: %s' % (i+1, go())

# 3x transformatie
OPS = [
        1,4,7,2,
        5,0,3,6,

        2,3,4,5,
        6,7,0,1,

        3,6,1,4,
        7,2,5,0,
        ]

STATES = '1 i j k -1 -i -j -k'.split()
def checktrans():
    opnr = -8
    for op in 'ijk':
        opnr += 8

        for n, left in enumerate(STATES):
            res = STATES[OPS[opnr+n]]
            print >>sys.stderr, "%2s * %2s = %2s" % (left, op, res)

def go():
    L, X = map(int, line().split())
    chars = line()
    assert len(chars) == L
    #pprint((X, chars))
    LEN = L*X

    ops = [(ord(c) - ord('i'))*8 for c in chars]
    #pprint((X, ops))

    # Acht toestanden: 1 i j k -1 -i -j -k
    # Steeds mogelijke eindtoestanden.

    # identity reeks kan altijd verplaatst worden, vanwege assoc.

    # Dus: greedy de eerste 'i' zoeken.
    # Dan: greedy de 'j'
    # Dan: greedy de 'k'
    # Dan: check ident

    pos = 0
    for c in 'ijk':
        want = STATES.index(c)

        state = 0
        startoffset = pos%L

        lookedat = [False] * 8

        while pos < LEN:
            offset = pos%L
            if offset == startoffset:
                if lookedat[state]:
                    return 'NO' # Already checked this state once, never going to work
                lookedat[state] = True

            # Perform operation
            state = OPS[ops[offset] + state]
            pos += 1

            if state == want:
                break
        else:
            # reached end
            return 'NO'

    # Now check whether we have identity in the tail
    state = 0

    lookedat = [None] * 8

    while pos < LEN:
        offset = pos%L
        if offset == 0:
            if lookedat[state] is not None:
                # 2e keer zelfde state
                prevpos = lookedat[state]
                curpos = pos
                if state == 0:
                    # We have identity
                    step = curpos - prevpos
                    if (LEN-pos) % step == 0:
                        return 'YES' # repeat
                    else:
                        return 'NO' # repeat
                else:
                    if lookedat[0] is None:
                        return 'NO' # Not going to happen
                    else:
                        pass # let's continue looking, the 0 will occur again
            else:
                lookedat[state] = pos

        # Perform operation
        state = OPS[ops[offset] + state]
        pos += 1
    else:
        # reached end
        if state == 0:
            return 'YES' # end
        return 'NO' # end

def main():
    files = []
    for fn in os.listdir('.'):
        if fn.endswith('.in'):
            files.append((os.path.getmtime(fn), fn))
    fn = max(files)[1]

    root = fn[:-2]
    with open(fn) as fd:
        global FD
        FD = fd
        backupstdout = sys.stdout
        sys.stdout = open(root+'out', 'wb')
        doit()
        sys.stdout = backupstdout
        subprocess.call(['diff', '-sdu', root+'good', root+'out'])

if __name__ == '__main__':
    main()
