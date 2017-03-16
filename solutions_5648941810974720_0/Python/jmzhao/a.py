# -*- coding: utf-8 -*-
"""
@author: jmzhao
GCJ 2016 Round 1
"""

import sys

class IO :
    def get(reader=str) :
        return reader(input().strip())
    def gets(reader=str, delim=None) :
        return [reader(x) for x in input().strip().split(delim)]
    def tostr(raw, writer=str, delim=' ') :
        return delim.join(writer(x) for x in raw)

def prework(argv):
    '''do something according to argv,
    return a message describing what have been done.'''
    pass

def todict(s) :
    d = dict()
    for c in s :
        d[c] = d.get(c,0) + 1
    return d

l = [todict(x) for x in ("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE")]
l = [(i, l[i]) for i in (0, 2, 6, 8, 7, 5, 3, 4, 1, 9)]

def once():
    s = IO.get()
    d = todict(s)
    ans = list()
    for i, id in l :
        printerr(i)
        while all(d.get(c,0)>=id[c] for c in id) :
            ans.append(i)
            for c in id :
                d[c] -= id[c]
            printerr(*list(d.items()))
        if all(x<=0 for x in d.values()) :
            ans.sort()
            return ans
        

def show(ans) :
    return IO.tostr(ans, delim='')
    
def printerr(*v):
    print(*v, file=sys.stderr)

def main():
    TT = int(input())
    for tt in range(1,TT+1):
        printerr("coping Case %d.."%(tt))
        ans = once()
        print("Case #%d: %s"%(tt, show(ans)))

if __name__ == '__main__' :
    msg = prework(sys.argv)
    print("prework done with", msg, file=sys.stderr)
    main()
