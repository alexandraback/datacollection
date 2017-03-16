#!/usr/local/bin/python2.7

import sys
import random
random.seed(0)

def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

def str_to_int(s, base):
    num = 0
    for i, d in enumerate(s[::-1]):
        num += int(d)*base**i
    return num



_T = readint()
for _t in range(_T):

    N, J = readarray(int)
    print 'Case #1:'
    sys.stdout.flush()

    D = set()
    count = 0

    A = '1' + '0'*(N/2 - 1) + '1'

    while count < J:
        B = '1' + ''.join([random.choice(['0', '1']) for i in range(N/2 - 2)]) + '1'
        if B in D:
            continue
        D.add(B)
        count += 1
        C = int(A)*int(B)
        facts = [str(str_to_int(B, i)) for i in range(2, 11)]
        print(str(C) + ' ' + ' '.join(facts))
        sys.stdout.flush()



