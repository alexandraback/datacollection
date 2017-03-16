#!/usr/bin/env python

IMP = "impossible"

def f(n, parts):
    yet = {}
    curr = set()
    results = []
    for p,q in parts:
        pp,qq = p,q
        res = -1
        res2 = -1
        while pp != 0 and res != IMP:
            # if res != IMP:
            res += 1
            if res > 40:
                res = IMP
                break
            if pp >= qq:
                if res2 < 0:
                    res2 = res
                while pp >= qq:
                    pp -= qq
            pp, qq = (pp, qq/2) if qq % 2 == 0 else (pp*2, qq)

        # print p,q, ";", pp, qq
        # print "curr:", curr
        # print "yet:",yet
        # print
        results.append(res2 if res != IMP else IMP)
        curr = set()
    return results 



def testmain():
    n = 5
    parts = [(1,2), (3,4), (1,4), (2,23), (123,31488)]
    return f(n,parts)

def teststdin():
    n = int(raw_input())
    parts = []
    for _ in range(n):
        p,q = map(int,raw_input().split('/'))
        parts.append((p,q))
    return f(n, parts)

if __name__ == '__main__':
    # res = testmain()
    res = teststdin()
    for i in range(len(res)):
        print "Case #%s: %s" % (str(i+1), str(res[i]))