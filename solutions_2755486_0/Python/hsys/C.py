#!/usr/bin/python

T = int(raw_input())

def printw(w) :
    for i in xrange(len(w)) :
        if w[i] != 0 :
            break
    for j in xrange(len(w)) :
        if w[-j - 1] != 0 :
            break
    print i - 500, w[i:len(w)-j]

for t in xrange(1, T + 1) :
    N = int(raw_input())
    all_attack = []
    for i in xrange(N) :
        d, n, w, e, s, dd, dp, ds = [ int(j) for j in raw_input().split() ]
        for j in xrange(n) :
            all_attack.append( (d, w, e, s) )
            d += dd
            w += dp
            e += dp
            s += ds
    all_attack.sort()
    wall = [0] * 1000
    total = 0
    last_to = 0
    for i in xrange(len(all_attack)) :
        d, w, e, s = all_attack[i]
        failed = False
        #print all_attack[i],
        for j in xrange(w, e) :
            if wall[j + 500] < s :
                failed = True
                break
        if failed :
            #print 'Yes',
            total += 1
        #else :
        #    print 'No',
        #printw(wall)

        if i == len(all_attack) - 1 or d != all_attack[i + 1][0] :
            while last_to <= i :
                dd, ww, ee, ss = all_attack[last_to]
                for j in xrange(ww, ee) :
                    if wall[j + 500] < ss :
                        wall[j + 500] = ss
                last_to += 1
    print 'Case #%d: %d' % (t, total)



