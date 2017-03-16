# -*- coding: utf-8 -*-
"""
@author: jmzhao
GCJ 2016 Round 1
"""

import sys
import math

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

def sign(x) :
    return 1 if x>0 else -1 if x<0 else 0
    
def mindiff(acc, s1, s2) :
    if min(len(s1), len(s2)) == 0 :
        return acc, s1, s2
    acc *= 10
    c1, s1 = s1[0], s1[1:]
    c2, s2 = s2[0], s2[1:]
    if c1!='?' :
        if c2!='?' : # all digits
            acc += int(c1) - int(c2)
            acc, s1, s2 = mindiff(acc, s1, s2)
            return acc, c1+s1, c2+s2
        else : # c1 digit
            if acc < 0 :
                acc += int(c1) - 0
                acc, s1, s2 = mindiff(acc, s1, s2)
                return acc, c1+s1, '0'+s2
            elif acc > 0 :
                acc += int(c1) - 9
                acc, s1, s2 = mindiff(acc, s1, s2)
                return acc, c1+s1, '9'+s2
            else :
                x, (acc, s1, s2) = min(((x, mindiff(x, s1, s2)) for x in (-1,0,1) if int(c1)+x >=0 and int(c1)+x<=9), key=lambda a : abs(a[1][0]))
                return acc, c1+s1, str(int(c1)-sign(x))+s2
    else :
        if c2!='?' : # c2 digit
            if acc < 0 :
                acc += 9 - int(c2)
                acc, s1, s2 = mindiff(acc, s1, s2)
                return acc, '9'+s1, c2+s2
            elif acc > 0 :
                acc += 0 - int(c2)
                acc, s1, s2 = mindiff(acc, s1, s2)
                return acc, '0'+s1, c2+s2
            else :
                x, (acc, s1, s2) = min(((x, mindiff(x, s1, s2)) for x in (-1,0,1) if int(c2)+x >=0 and int(c2)+x<=9), key=lambda a : abs(a[1][0]))
                return acc, str(int(c2)+sign(x))+s1, c2+s2
        else :
            if acc < 0 :
                acc += 9 - 0
                acc, s1, s2 = mindiff(acc, s1, s2)
                return acc, '9'+s1, '0'+s2
            elif acc > 0 :
                acc += 0 - 9
                acc, s1, s2 = mindiff(acc, s1, s2)
                return acc, '0'+s1, '9'+s2
            else :
                x, (acc, s1, s2) = min(((x, mindiff(x, s1, s2)) for x in (0,-1,1)), key=lambda a : abs(a[1][0]))
                return acc, ('1' if x>0 else '0')+s1, ('1' if x<0 else '0')+s2         

def allpos(s) :
    if len(s)==0 :
        yield ''
    else :
        if s[0]!='?' :
            for sub in allpos(s[1:]) :
                yield s[0]+sub
        else :
            for c in '0123456789' :
                for sub in allpos(s[1:]) :
                    yield c+sub
                
def mindiff2(s1,s2) :
    return min(((int(a)-int(b), a, b) for a in allpos(s1) for b in allpos(s2)), key=lambda t : abs(t[0]))    
    
def once():
    '''to cope once'''
    s1, s2 = IO.gets()
    acc, s1, s2 = mindiff2(s1, s2)
    return s1, s2

def show(ans) :
    return IO.tostr(ans, writer=str, delim=' ')
    
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
