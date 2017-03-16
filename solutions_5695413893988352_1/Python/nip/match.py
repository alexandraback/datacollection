#! /usr/bin/env python

from sys import stdin
import sys

def maximise(s):
    return "".join('9' if c == '?' else c for c in s)

def minimise(s):
    return "".join('0' if c == '?' else c for c in s)

def answer(C, J):
    posC = C.find('?')
    posJ = J.find('?')
    pos = min(posC, posJ)
    if posC == -1:
        pos = posJ
    if posJ == -1:
        pos = posC
    if pos == -1:
        return C, J
    mindiff = 10**20
    if C[pos] == '?' and J[pos] != '?':
        other = J[pos]
        if other != '0':
            Cjb = C[:pos] + str(int(other)-1) + maximise(C[pos+1:])
            Jjb = J[:pos] + other + minimise(J[pos+1:])
            diff = abs(int(Cjb) - int(Jjb))
            if diff < mindiff:
                mindiff = diff
                Cans = Cjb
                Jans = Jjb
        CjB = minimise(C)
        JjB = maximise(J)
        diff = abs(int(CjB) - int(JjB))
        if diff < mindiff:
            mindiff = diff
            Cans = CjB
            Jans = JjB
        Ceq, Jeq = answer(C[:pos] + other + C[pos+1:], J[:pos] + other + J[pos+1:])
        diff = abs(int(Ceq) - int(Jeq))
        if diff < mindiff:
            mindiff = diff
            Cans = Ceq
            Jans = Jeq
        if other != '9':
            Ccb = C[:pos] + str(int(other)+1) + minimise(C[pos+1:])
            Jcb = J[:pos] + other + maximise(J[pos+1:])
            diff = abs(int(Ccb) - int(Jcb))
            if diff < mindiff:
                mindiff = diff
                Cans = Ccb
                Jans = Jcb
        CcB = maximise(C)
        JcB = minimise(J)
        diff = abs(int(CcB) - int(JcB))
        if diff < mindiff:
            mindiff = diff
            Cans = CcB
            Jans = JcB
        return Cans, Jans
    if C[pos] != '?' and J[pos] == '?':
        other = C[pos]
        if other != '0':
            Ccb = C[:pos] + other + minimise(C[pos+1:])
            Jcb = J[:pos] + str(int(other)-1) + maximise(J[pos+1:])
            diff = abs(int(Ccb) - int(Jcb))
            if diff < mindiff:
                mindiff = diff
                Cans = Ccb
                Jans = Jcb
        CjB = minimise(C)
        JjB = maximise(J)
        diff = abs(int(CjB) - int(JjB))
        if diff < mindiff:
            mindiff = diff
            Cans = CjB
            Jans = JjB
        Ceq, Jeq = answer(C[:pos] + other + C[pos+1:],
                          J[:pos] + other + J[pos+1:])
        diff = abs(int(Ceq) - int(Jeq))
        if diff < mindiff:
            mindiff = diff
            Cans = Ceq
            Jans = Jeq
        if other != '9':
            Cjb = C[:pos] + other + maximise(C[pos+1:])
            Jjb = J[:pos] + str(int(other)+1) + minimise(J[pos+1:])
            diff = abs(int(Cjb) - int(Jjb))
            if diff < mindiff:
                mindiff = diff
                Cans = Cjb
                Jans = Jjb
        CcB = maximise(C)
        JcB = minimise(J)
        diff = abs(int(CcB) - int(JcB))
        if diff < mindiff:
            mindiff = diff
            Cans = CcB
            Jans = JcB
        return Cans, Jans
    Cans, Jans = answer(C[:pos] + '0' + C[pos+1:],
                        J[:pos] + '0' + J[pos+1:])
    mindiff = abs(int(Cans) - int(Jans))
    CjB = minimise(C)
    JjB = maximise(J)
    diff = abs(int(CjB) - int(JjB))
    if diff < mindiff:
        mindiff = diff
        Cans = CjB
        Jans = JjB
    Cjb = C[:pos] + '0' + maximise(C[pos+1:])
    Jjb = J[:pos] + '1' + minimise(J[pos+1:])
    diff = abs(int(Cjb) - int(Jjb))
    if diff < mindiff:
        mindiff = diff
        Cans = Cjb
        Jans = Jjb
    Ccb = C[:pos] + '1' + minimise(C[pos+1:])
    Jcb = J[:pos] + '0' + maximise(J[pos+1:])
    diff = abs(int(Ccb) - int(Jcb))
    if diff < mindiff:
        mindiff = diff
        Cans = Ccb
        Jans = Jcb
    CcB = maximise(C)
    JcB = minimise(J)
    diff = abs(int(CcB) - int(JcB))
    if diff < mindiff:
        mindiff = diff
        Cans = CcB
        Jans = JcB

    return Cans, Jans

ntest = input()

for test in xrange(ntest):
    C, J = stdin.readline().strip().split()
    ansC, ansJ = answer(C, J)
    print "Case #{}: {} {}".format(test + 1, ansC, ansJ)

