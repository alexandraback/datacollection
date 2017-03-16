from itertools import *

mult_table = {
    '1':{'1': (+1, '1'),  'i':(+1, 'i'),  'j':(+1, 'j'),  'k':(+1, 'k')},
    'i': {'1': (+1, 'i'),   'i':(-1, '1'),  'j':(+1, 'k'),   'k':(-1, 'j')},
    'j': {'1':  (+1, 'j'),   'i':(-1, 'k'),  'j':(-1, '1'),   'k':(+1, 'i')},
    'k':{'1': (+1, 'k'),  'i':(+1, 'j'), 'j':(-1, 'i'),  'k':(-1, '1')},
}


def sum_oper(a, b):
    sa, va = a
    sb, vb = b
    sr, vr = mult_table[va][vb]
    return (sa*sb*sr, vr)

def partial_sums(iterable, sum_oper, start):
    total = start
    for i in iterable:
        total = sum_oper(total, i)
        yield total

def find_arg_first(iterable, e, start=0):
    for i, x in enumerate(iterable[start:]):
        if x == e: return i + start
    return -1

def find_sub_string(L, elements):
    if len(elements) == 0: 
        return True
    
    e = (1, '1')
    print map(lambda x: ('' if x[0] > 0 else '-') + x[1], elements)
    print 'L', map(lambda x: ('' if x[0] > 0 else '-') + x[1], L)
    print '---------'
    
def solve(S, X):
    #X =min(X, 12)
    S = S*X
    mult_acc = list(partial_sums(S, sum_oper, start=(1, '1')))
    #    print 'S', S, '*', X
    #print 'acc', map(lambda x: ('' if x[0] > 0 else '-') + x[1], mult_acc)
    
    # find k
    if mult_acc[-1] != (-1, '1'): return 'NO'

    # find i
    arg = 0
    while arg >=0:
        arg = find_arg_first(mult_acc, (1, 'i'), start=arg)
        if arg == -1: return 'NO'
        # find j
        arg_j = find_arg_first(mult_acc, (1, 'k'), start=arg)
        if arg_j >= 0: return 'YES'
        arg += 1
    return 'NO'
        

import sys
fin = sys.stdin
#fin = open('input.txt', 'r')
#fout = open('output.txt', 'w')

T = int(fin.readline().strip())
for t in range(T):
    L, X = map(int, fin.readline().split())
    S = map(lambda c: (1, c), list(fin.readline().strip()))
    res = "%s" % solve(S, X)
    answer= "Case #%d: %s\n" % (t+1, res)
    print answer, 



