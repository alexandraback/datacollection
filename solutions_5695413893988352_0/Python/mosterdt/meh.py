#!/usr/bin/env python2

def case(T):
    a, b = raw_input().split()
    poss_a = [a]
    poss_b = [b]

    
    while poss_a[0].find("?") != -1:
        at = poss_a.pop(0)
        for x in extend(at):
            poss_a.append(x)
    while poss_b[0].find("?") != -1:
        bt = poss_b.pop(0)
        for x in extend(bt):
            poss_b.append(x)
    minprev = 99999
    for i in poss_a:
        for j in poss_b:
            val = abs(int(i) -int(j))
            if val < minprev or \
            val == minprev and int(i) < int(new_a) or \
            val == minprev and int(j) < int(new_b):
                new_a = i
                new_b = j
                minprev = val
                #print new_a, new_b, minprev
    #print "a", a
    #print "b", b
    return "{} {}".format(new_a, new_b)


def extend(a):
    ind = a.find("?")
    ans = []
    if ind >= 0:
        for i in xrange(10):
            ans.append(a.replace("?", str(i), 1))
    return ans




if __name__=="__main__":
    for i in xrange(int(raw_input())):
        print "Case #{}: {}".format(i+1, case(i))
