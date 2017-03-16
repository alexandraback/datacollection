'''
Created on 27/04/2013

@author: Fantoccini
'''
from multiprocessing import Manager, Pool
import sys, traceback

def f(ci, res, e, r, n, t):
    try:
        ans = [[0 for j in xrange(e + 1) ] for i in xrange(n)]
        i = n - 1
        while i >= 0:
            for j in xrange(e + 1):
                if i == n - 1:
                    ans[i][j] = t[i] * j
                else:
                    for k in xrange(j + 1):
                        m = j - k + r
                        if m > e:
                            m = e
                        if ans[i][j] < ans[i + 1][m] + t[i] * k:
                            ans[i][j] = ans[i + 1][m] + t[i] * k
            i -= 1
        res[ci] = ans[0][e]
        print ci, "Done"
    except:
        print "Exception in user code:"
        print '-' * 60
        traceback.print_exc(file=sys.stdout)
        print '-' * 60
    

if __name__ == '__main__':
    ps = [] 
    manager = Manager()
    pool = Pool(5)
    fin = open("b.in", "r")
    fout = open("b.out", "w")
    t = int (fin.readline())
    res = manager.list(range(t))
    for ci in range(t):
        e, r, n = map(int, fin.readline().split())
        tasks = map(int, fin.readline().split())
        pool.apply_async(f, (ci, res, e, r, n, tasks))
    pool.close()
    pool.join()
    for ci in range(t):
        fout.write("Case #" + str (ci + 1) + ": " + str(res[ci]) + "\n")
    fin.close()
    fout.close()
    
