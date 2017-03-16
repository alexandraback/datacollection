'''
Created on 13/04/2013

@author: Fantoccini
'''
from multiprocessing import Manager, Pool
from math import sqrt
from math import log10
from math import floor, ceil
import sys, traceback

def f(ci, res, a, b):
    try:
        res[ci] = 0
        def getrange(aa, bb):
            r = []
            s = int(log10(aa)) + 1
            t = int(log10(bb)) + 1
            for i in xrange(s, t + 1):
                for f in ["1", "4", "5", "6", "9"]:
                    rs = f;
                    rt = f
                    if (i > 1):
                        rs = f + "0" * (i - 2) + f
                        rt = f + "9" * (i - 2) + f
                    if int(rt) < aa:
                        continue
                    if int(rs) > bb:
                        break
                    if int(rs) < aa:
                        rs = aa
                    if int(rt) > bb:
                        rt = bb
                    r.append((int(rs), int(rt)))
            return r
        
        def getsqrtrange(aa, bb):
            ra = ceil(sqrt(aa))
            rb = floor(sqrt(bb))
            return ra, rb
        
        def getp(aa, bb):
            if aa > bb:
                return
            s = int(log10(aa)) + 1
            t = int(log10(bb)) + 1
            for i in xrange(s, t + 1):
                for f in ['1', '2', '3', '4', '5', '6', '7', '8', '9']:
                    rs = f
                    rt = f
                    if (i > 1):
                        rs = f + "0" * (i - 2) + f
                        rt = f + "9" * (i - 2) + f
                    if int(rt) < aa:
                        continue
                    if int(rs) > bb:
                        break
                    if int(rs) < aa:
                        rs = aa
                    if int(rt) > bb:
                        rt = bb
                    for n in xrange(int(rs), int(rt) + 1):
                        sn = str(n)
                        if sn != sn[::-1]:
                            continue
                        nn = n * n
                        snn = str(nn)
                        if snn != snn[::-1]:
                            continue
                        res[ci] += 1
        
        l = getrange(a, b)
        for aaa, bbb in l:
            raa, rbb = getsqrtrange(aaa, bbb)
            getp(raa, rbb)
    except:
        print "Exception in user code:"
        print '-' * 60
        traceback.print_exc(file=sys.stdout)
        print '-' * 60

if __name__ == '__main__':
    ps = [] 
    manager = Manager()
    pool = Pool(5)
    fin = open("c.in", "r")
    fout = open("c.out", "w")
    t = int (fin.readline())
    res = manager.list(range(t))
    for ci in range(t):
        a, b = map(int, fin.readline().strip().split())
        pool.apply_async(f, (ci, res, a, b))
    pool.close()
    pool.join()
    for ci in range(t):
        fout.write("Case #" + str (ci + 1) + ": " + str(res[ci]) + "\n")
    fin.close()
    fout.close()
    
