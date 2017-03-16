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

def maxloop(b) :
    v = [0 for x in b]
    ans = 0
    for i in range(len(b)) :
        l = [i]
        c = 0; j = i; oj = None
        while v[j] == 0 :
            v[j] = 1
            oj, j = j, b[j]
            if j in l : 
                ans = max(ans, len(l) - l.index(j))
                break
            l.append(j)
        
    return ans

def once():
    '''to cope once'''
    n = IO.get(int)
    b = IO.gets(int)
    b = [x-1 for x in b]
    core = [(i,bi) for i,bi in enumerate(b) if b[bi] == i and i < bi]
    adj = [list() for i in range(len(b))]
    for i,bi in enumerate(b) :
        adj[bi].append(i)
    def longest(i, j) : # longest reverse path from i, fobiding j
        l = list(longest(n, i) for n in adj[i] if n != j)
        return 0 if len(l)==0 else 1 + max(l)
    ans = sum(2 + longest(i, j) + longest(j, i) for i,j in core)
    return max(ans, maxloop(b))
    
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
