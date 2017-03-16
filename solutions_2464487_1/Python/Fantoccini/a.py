'''
Created on 27/04/2013

@author: Fantoccini
'''
from multiprocessing import Manager, Pool
import sys, traceback

def sqsum(n):
    return n * (n + 1) * (2 * n + 1) / 6

def cost(n, r):
    res = sqsum(2 * n - 1) - 8 * sqsum(n - 1)
    res += 2 * n * n * r
    res -= 2 * (n - 1) * n * r
    return res  

def f(ci, res, r, t):
    try:
        ans = 1
        add = 1
        while add > 0:
            if cost(ans + add, r) <= t:
                ans += add
                add *= 2
            else:
                add /= 2
        res[ci] = ans
    except:
        print "Exception in user code:"
        print '-' * 60
        traceback.print_exc(file=sys.stdout)
        print '-' * 60
    

if __name__ == '__main__':
    ps = [] 
    manager = Manager()
    pool = Pool(5)
    fin = open("a.in", "r")
    fout = open("a.out", "w")
    t = int (fin.readline())
    res = manager.list(range(t))
    for ci in range(t):
        rr, tt = map(int, fin.readline().split())
        pool.apply_async(f, (ci, res, rr, tt))
    pool.close()
    pool.join()
    for ci in range(t):
        fout.write("Case #" + str (ci + 1) + ": " + str(res[ci]) + "\n")
    fin.close()
    fout.close()
    
