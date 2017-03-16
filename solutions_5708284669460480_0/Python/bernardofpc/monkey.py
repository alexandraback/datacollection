def words(kb, l):
    if l == 1:
        for x in kb:
            yield [x]
    else:
        for x in kb:
            for w in words(kb, l-1):
                yield [x] + w

def score(typed, target):
    acc = 0
    lt = len(target)
    typed = ''.join(typed)
    for i in range(0, len(typed) - lt + 1):
        if target == typed[i:i+lt]:
            acc += 1
    return acc

def bf(kb, target, s):
    nwords = len(kb) ** s
    curmax = 0
    sum_bnn = 0
    for w in words(kb, s):
        #print(str(w), str(target))
        sc = score(w, target)
        if sc > curmax:
            curmax = sc
        sum_bnn += sc

    #print('Max = {}, sum = {}'.format(curmax, sum_bnn))
    return float(curmax) - float(sum_bnn)/float(nwords)

import sys

T = int(sys.stdin.readline())

for icase in range(1,T+1):
    x = sys.stdin.readline()
    [k, l, s] = [int(_u) for _u in x.split()]
    kb = sys.stdin.readline().strip()
    target = sys.stdin.readline().strip()
    assert(len(kb) == k and len(target) == l)

    nsteps2 = bf(kb, target, s)
    print('Case #{}: {}'.format(icase,nsteps2))
    #if nsteps != nsteps2: print('WARNING');
    #print('Case #{}: {} {}'.format(icase,nsteps,nsteps2))
