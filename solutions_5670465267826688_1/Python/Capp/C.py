#!/usr/bin/env python

from sys import stdin, stderr

def stoo(s):
    if   s == 'i': return 1
    elif s == 'j': return 2
    elif s == 'k': return 3
    elif s == '1': return 0
    elif s[0] == '-': return stoo(s[1:]) + 4
    raise "Error: stoo"

otos = ['1', 'i', 'j', 'k', '-1', '-i', '-j', '-k']

multi = [0 for i in range(64)]
def multi_val(v1, v2): return multi[v1*8 + v2]
def multi_s(s1, s2):   return multi_val(stoo(s1), stoo(s2))

for i in range(4):
    multi[i]   = i
    multi[i*8] = i
multi[011] = 4
multi[022] = 4
multi[033] = 4
multi[012] = 3
multi[023] = 1
multi[031] = 2
multi[021] = multi[012] + 4
multi[032] = multi[023] + 4
multi[013] = multi[031] + 4

for i in range(4):
    for j in range(4):
        multi[(i+4)*8+(j+0)] = (multi_val(i, j) + 4) % 8
        multi[(i+0)*8+(j+4)] = (multi_val(i, j) + 4) % 8
        multi[(i+4)*8+(j+4)] = multi_val(i, j)
        pass
    pass

# print otos[multi_s('1', '-1')]
# print otos[multi_s('i', '-k')]
# print otos[multi_s('-k', 'i')]

T = int(stdin.readline())
for t in range(T):
    L, X = [int(c) for c in stdin.readline().split()]
    m = stdin.readline().strip()
    ret = True

    print >>stderr, "Debug:", t, L, X, m

    dset = set()
    plist = [[0, 0] for i in range(8)]
    val = 0
    for i, c in enumerate(m):
        val = multi_val(val, stoo(c))
        if not val in dset:
            dset.add(val)
            plist[val][0] = i
            pass
        plist[val][1] = i
        pass
    cycle = val
    lastval = stoo("1")
    for i in range(X%4): lastval = multi_val(lastval, cycle)
    #print >>stderr, dset,
    #print >>stderr, otos[cycle],
    #print >>stderr, plist,
    #print >>stderr, otos[lastval]

    for i in range(min(X, 8)):
        for d in dset.copy():
            d2 = multi_val(d, cycle)
            if not d2 in dset:
                dset.add(d2)
                plist[d2][0] = plist[d][0] + L
                pass
            plist[d2][1] = plist[d][1] + L
            pass
        pass

    if not stoo("i") in dset: ret = False # "i"
    if not stoo("k") in dset: ret = False # "ij"
    if lastval != stoo("-1"): ret = False # "ijk"
    if plist[stoo("i")][0] > plist[stoo("k")][1]: ret = False

    print "Case #%d:" % (t+1),
    if ret: print "YES"
    else:   print "NO"
