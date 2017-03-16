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

def agree(l1, l2) :
    b = [a==b for a,b in zip(l1,l2) if a!=0 and b!=0]
    return len(b)==0 or all(b)

def once():
    '''to cope once'''
    n = IO.get(int)
    lines = [IO.gets(int) for _ in range(2*n-1)]
    lines.sort()
    g = [[0 for i in range(n)] for j in range(n)]
    rowi = 0; coli = 1;
    for i in range(n) :
        g[i][0] = lines[0][i]
    def search(rowi, coli, j, missing) :
#        printerr("=>"*j, j, rowi, coli)
        if j == 2*n-1 :
#            printerr(IO.tostr(g,delim='\n'))
#            printerr('-------------')
            for i in range(n) :
                for j in range(n) :
                    if g[i][j] == 0 :
                        return
            if missing is None :
                missing = ('row', rowi) if rowi < n else (('col', coli) if coli < n else 
                printerr("unknow case:", rowi, coli)
                )
            return missing
        line = lines[j]
        if rowi < n and agree(line, g[rowi]) :
#            printerr("=>"*j, "row", rowi, line)
            oldg = [g[rowi][i] for i in range(n)]
            for i in range(n) :
                g[rowi][i] = line[i]
            res = search(rowi+1, coli, j+1, missing)
            if res is None :
                for i in range(n) :
                    g[rowi][i] = oldg[i]
            else :
                return res
        if coli < n and agree(line, [g[i][coli] for i in range(n)]) :
#            printerr("=>"*j, "col", coli, line)
            oldg = [g[i][coli] for i in range(n)]
            for i in range(n) :
                g[i][coli] = line[i]
            res = search(rowi, coli+1, j+1, missing)
            if res is None :
                for i in range(n) :
                    g[i][coli] = oldg[i]
            else :
                return res
        if missing is not None :
            return 
        if rowi+1<n and agree(line, g[rowi+1]) :
#            printerr("=>"*j, "row", rowi, line, "missing")
            res = search(rowi+1, coli, j, ('row', rowi))
            if res is not None :
                return res
        if coli+1<n and agree(line, [g[i][coli+1] for i in range(n)]) :
#            printerr("=>"*j, "col", coli, line, "missing")
            res = search(rowi, coli+1, j, ('col', coli))
            if res is not None :
                return res
#        print("unknow case:", IO.tostr(lines,delim='\n'), "=====", IO.tostr(g,delim='\n'), sep='\n',file=sys.stderr)
    missing = search(0, 1, 1, None)
    
    d, i = missing
    return g[i] if d == 'row' else [g[_][i] for _ in range(n)]

def show(ans) :
    return IO.tostr(ans, delim=' ')
    
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
