#!/usr/bin/env python

def get_war(naomi, ken):
    win = 0
    while len(ken):
        if naomi[0] > ken[0]:
            ken.pop(0)
            win += 1
        else:
            naomi.pop(0)
            ken.pop(0)
    return win


def get_dec(naomi, ken):
    win = 0
    while len(naomi):
        if naomi[0] < ken[0]:
            naomi.pop(0)
            ken.pop(len(ken) - 1)
        else:
            naomi.pop(0)
            ken.pop(0)
            win += 1
    return win

with open('input') as fin:
    T = int(fin.readline())
    for i in xrange(T):
        n = int(fin.readline())
        naomi = sorted([float(x) for x in fin.readline().split()])
        ken = sorted([float(x) for x in fin.readline().split()])
        print 'Case #%d: %d %d' % (i+1, get_dec(naomi[:], ken[:]), get_war(naomi[:], ken[:]))
