#!/usr/bin/python
import math
import sys
import IPython

info = 0
debug = 0
xstracking = 0

E,R,N = 0,0,0
vs = []
max_gain = -1

xs = []

def gen_possibilities(curr_energy):
    global E,R,N,vs

    #if curr_energy <= R:
    #    return [curr_energy]

    return range(0, curr_energy+1)


def pick_and_continue(curr_energy, curr_gain, curr_idx):
    global E,R,N,vs
    global xs
    global max_gain

    assert 0 <= curr_energy <= E

    if debug:
        #print 'GLOBAL', E, R, N, vs
        print 'CURR:', curr_energy, curr_gain, curr_idx

    if debug:
        print 'POSS: %s' % gen_possibilities(curr_energy)
    for x in gen_possibilities(curr_energy):
        assert (curr_energy - x) >= 0
        _energy = min(curr_energy - x + R, E)
        _gain = curr_gain + x*vs[curr_idx]
        _idx = curr_idx + 1


        if debug:
            print 'picking: %s (depth: %s)' % (x, curr_idx)
            print 'UPDATE:', _energy, _gain, _idx

        if xstracking:
            xs.append(x)

        if _idx == N:
            if _gain > max_gain:
                max_gain = _gain
            if debug:
                print 'DONE! Gain:', _gain
                if xstracking:
                    print 'choices: %s' % str(xs)
                print
        else:
            pick_and_continue(_energy, _gain, _idx)

        if xstracking:
            xs = xs[:-1]


def solve(_E,_R,_N,_vs):
    global E,R,N,vs
    global max_gain


    E = _E
    R = _R
    N = _N
    vs = _vs
    max_gain = -1

    if E <= R:
        return E * sum(vs)

    pick_and_continue(E, 0, 0)

    if debug:
        print 'MAX GAIN: %s' % max_gain

    if N == 1:
        assert max_gain == (E * vs[0])

    return max_gain




lines = open(sys.argv[1]).read().split('\n')

test_num=int(lines[0])
idx=1
for x in range(test_num):
    curr_line = lines[idx]
    idx += 1

    E, R, N = map(int, curr_line.split(' '))

    curr_line = lines[idx]
    idx += 1
    vs = map(int, curr_line.split(' '))
    assert len(vs) == N

    ans = solve(E,R,N,vs)
    if info:
        print 'E, R, N, VS: %s %s %s %s' % (E,R,N,str(vs)),
    print 'Case #%s: %s' % (x+1, ans)
