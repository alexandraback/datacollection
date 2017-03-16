from sys import *
from heapq import *
from time import time
from multiprocessing import Pool
from collections import *
import itertools
from copy import deepcopy
from bisect import *
setrecursionlimit(10000)
from math import *
from time import sleep
import os
import sys
import re

def readint():
    return int(fi.readline())

def readints():
    return [int(X) for X in fi.readline().split()]

def readfloats():
    return [float(X) for X in fi.readline().split()]

def readstr():
    return fi.readline().rstrip()

def read_case():
    N = readint()
    S = readstr().split()
    return (N, S)

modp = 1000000007
fac = [1]
for I in range(1,101):
    fac.append((fac[-1] * I) % modp)

def il(S):
        ib = len(S)
        ie = -1
        for I in range(len(S)):
            if S[I] != S[0]:
                ib = I
                break
        for I in range(len(S)-1,-1,-1):
            if S[I] != S[-1]:
                ie = I
                break
        IL = set(S[ib:1+ie])
        return IL

def solve_case(N, S):
    IL = set()
    for X in S:
        TIL = il(X)
        if len(TIL & IL) > 0: return 0
        IL = IL | TIL
        if X[0] == X[-1] and len(TIL) > 0: return 0
    for X in S:
        if X[0] in IL: return 0
        if X[-1] in IL: return 0
    inE = dict()
    outE = dict()
    loop = defaultdict(lambda: 0)
    for X in S:
        if X[0] == X[-1]:
            loop[X[0]] += 1
        else:
            if X[0] in inE: return 0
            if X[-1] in outE: return 0
            inE[X[0]] = X[-1]
            outE[X[-1]] = X[0]
    print S
    print inE
    print outE
    print loop
    done = set()
    all = set(inE)| set(outE) | set(loop)
    cc = 0
    w = 1
    while len(done) < len(all):
        start = min(all - done)
        next = start
        while True:
            done.add(next)
            w = (w * fac[loop[next]]) % modp
            if next not in outE: break
            next = outE[next]
            if next in done: return 0
        next = start
        while next in inE:
            next = inE[next]
            if next in done: return 0
            w = (w * fac[loop[next]]) % modp
            done.add(next)
        cc += 1
    w = (w * fac[cc]) % modp
    return w

def print_solution(case):
    val = solve_case(*case[1])
    msg = "Case #{}: {}".format(case[0], val)
    print msg
    return msg

t0 = time()
# Initialisation here
t1 = time()
print "Intialisation took %f seconds" % (t1 - t0)

if __name__ == '__main__':
    fni = "%s-%s-%s.in" % (argv[1], argv[2], argv[3])
    fno = "%s-%s-%s.out" % (argv[1], argv[2], argv[3])

    if not os.path.isfile(fni):
        sys.stdout.write('Waiting for input file {}...'.format(fni))
        while not os.path.isfile(fni):
            sys.stdout.flush()
            sleep(1)
            sys.stdout.write(".")
        sleep(1)
        print ''
    fi = open(fni, 'r')

    numcases = readint()
    cases = [(I, read_case()) for I in range(1,1+numcases)]

    mt = False
    if mt:
        print "Running multi-threaded"
        p = Pool(8)
        output = p.map(print_solution, cases)
    else:
        print "Running single-threaded"
        output = map(print_solution, cases)
    print "Elapsed time %f seconds " % (time() - t1)

    if os.path.isfile(fno):
        print 'Verifying against existing results'
        fo = open(fno, 'r')
        oc = re.split('(Case #[0-9]+:\s*)', fo.read())[1:]
        refout = [(A+B).rstrip() for (A,B) in zip(oc[::2], oc[1::2])]
        diffs = 0
        for C in range(numcases):
           if refout[C] != output[C]:
               print '-'*20
               print 'Input {}\nReference Output {}\nGenerated Output {}'.format(cases[C][1], refout[C], output[C])
               print '-'*20
               diffs += 1
        print '{} diffs found'.format(diffs)
    else:
        fo = open(fno, 'w')
        fo.write('\n'.join(output))
        print '{} cases written'.format(len(output))

