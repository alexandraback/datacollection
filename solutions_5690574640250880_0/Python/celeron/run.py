#!/usr/bin/env python

def is_valid(conf):
    if conf[0] - conf[1] > 0:
        return False
    if 1 in conf:
        return False
    return True

def next_conf(conf):
    p = len(conf) - 1
    while conf[p] == 0:
        p -= 1
    conf[p] -= 1
    p -= 1
    if p != 0:
        while conf[p] >= conf[p-1] and p != 0:
            p -= 1
    conf[p] += 1
    return conf

def print_conf(R, C, conf):
    for i in xrange(R):
        if i == 0:
            print 'c' + '.' * (conf[i] - 1) + '*' * (C - conf[i])
        else:
            print '.' * conf[i] + '*' * (C - conf[i])


with open('input') as fin:
    T = int(fin.readline())
    for i in xrange(T):
        print 'Case #%d:' % (i+1)
        R, C, M = [int(x) for x in fin.readline().split()]
        no_mine = R * C - M
        if no_mine == 0:
            print 'Impossible'
            continue
        else:
            if R == 1:
                conf = [no_mine]
            elif C == 1:
                conf = [1] * no_mine + [0] * (R - no_mine)
            elif no_mine == 1:
                conf = [1] + [0] * (R - 1)
            else:
                shortest = no_mine / R
                conf = [no_mine / R + 1] * (no_mine % R) + [no_mine / R] * (R - no_mine % R)
                impossible = False
                while not is_valid(conf):
                    if conf[1] == 0 or conf[0] > C:
                        impossible = True
                        break
                    conf = next_conf(conf)
                if impossible:
                    print 'Impossible'
                    continue
            print_conf(R, C, conf)
