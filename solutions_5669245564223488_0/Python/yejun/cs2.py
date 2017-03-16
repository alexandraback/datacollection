import sys
from collections import defaultdict
import math
import locale

sys.setrecursionlimit(1000000)
locale.setlocale(locale.LC_ALL, '')

f = open(sys.argv[1]) if len(sys.argv)>1 else sys.stdin

total = int(f.readline().strip())

def ptr(train):
    l = set()
    list(map(l.add, train))
    s = ''
    n = []
    for i in train:
        if i != s:
           n.append(s)
        s = i
    if len(n) != len(l):
        l = [] 
    return (train[0], train[-1], tuple(l))

def conn(t1, t2):
    s1 = set(t1[2])
    s2 = set(t2[2])
    ints = list(s1 & s2)
    if len(ints) > 1:
        return ('', '', tuple())
    return (t1[0], t2[1], tuple(s1.union(s2)))

for i in range(total):
    sys.stdout.write("Case #%d: " % int(i+1))
    n = int(f.readline().strip())
    trains = sorted(f.readline().strip().split())
    trains = list(map(ptr, trains))
    singlet = defaultdict(int)
    invalid = False
    for st, en, ls in trains:
        if len(ls) == 1:
            singlet[st] += 1
        if len(ls) == 0:
            invalid = True
            break
    if invalid:
        print(0)
        continue
    base = 1
    reduced = 0
    for i in singlet.values():
        base *= math.factorial(i)
        reduced += (i-1)
    newtrains = set(trains)
    if len(newtrains) + reduced != len(trains):
        print(0)
        continue
    start_l = defaultdict(list)
    for t in newtrains:
        st, en, ls = t
        start_l[st].append(t)
    invalid = False
    for i in start_l.values():
        if len(i) > 1:
            invalid = True
    if invalid:
        print(0)
        continue
    invalid = False
    finished = False
    while not finished:
        finished = True
        t1 = None
        t2 = None
        for t in newtrains:
            st, en, ls = t
            if len(start_l[en]) > 0 and start_l[en][0] != t:
                finished = False
                t1 = t
                t2 = start_l[en][0]
                start_l[en] = []
                start_l[st] = []
                break
        if t1:
             newtrains.remove(t1)
             newtrains.remove(t2)
             nt = conn(t1, t2)
             if len(nt[2]) == 0:
                 invalid = True
                 break
             newtrains.add(nt)
             start_l[nt[0]] = [nt]
    if invalid:
        print(0)
        continue
    ts = set()
    tsl = 0
    for t in newtrains:
        st, en, ls = t
        tsl += len(ls)
        ts = ts.union(set(ls))    
    if len(ts) != tsl:
        print(0)
        continue 
    result = base*math.factorial(len(newtrains))
    print(locale.format("%d", result, grouping=True))

