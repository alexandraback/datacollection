# -*- coding: utf-8 -*-
"""
@author: jmzhao
GCJ 2016 Round 1
"""

import sys
sys.setrecursionlimit(10000)

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

def last(s) :
    if len(s) < 2 : return s
    c, i = max((c, i) for i, c in enumerate(s))
    return c + last(s[:i]) + s[i+1:]

def once():
    '''to cope once'''
    s = IO.get()
    return last(s)

def show(ans) :
    return ans #IO.tostr(ans, delim=' ')
    
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
