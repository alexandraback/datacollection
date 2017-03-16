'''
Created on 04/05/2013

@author: Fantoccini
'''
from multiprocessing import Manager, Pool
import sys, traceback

def f(I, RES, n, x, y):
    def c(nn, kk):
        fn = 1
        fk = 1
        fnk = 1
        for i in xrange(nn):
            fn *= i + 1
            if i < kk:
                fk *= i + 1
            if i < nn - kk:
                fnk *= i + 1
        return fn / fk / fnk
    try:
        if x < 0:
            x = -x
        ans = 0.0
        cnt = 0
        a = 1        
        while a <= n:
            n -= a
            cnt += 2
            a += 4
        if x + y < cnt:
            ans = 1.0
        elif x + y == cnt:
            if n > cnt:
                y -= n - cnt
                n -= 2 * (n - cnt)
            if y < n:
                base = 2 ** n
                nb = base
                while y >= 0:
                    nb -= c(n, y)
                    y -= 1
                ans = float(nb) / float(base)
        RES[I] = ans
        print I, "Done"
    except:
        print "Exception in user code:"
        print '-' * 60
        traceback.print_exc(file=sys.stdout)
        print '-' * 60
    

if __name__ == '__main__':
    ps = [] 
    manager = Manager()
    pool = Pool(4)
    fin = open("b.in", "r")
    fout = open("b.out", "w")
    T = int (fin.readline())
    RES = manager.list(range(T))
    for I in range(T):
        n, x, y = map(int, fin.readline().split())
        pool.apply_async(f, (I, RES, n, x, y))
    pool.close()
    pool.join()
    for I in range(T):
        fout.write("Case #" + str (I + 1) + ": " + str(RES[I]) + "\n")
    fin.close()
    fout.close()
    
