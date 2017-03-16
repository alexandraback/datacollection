'''
Created on 27/04/2013

@author: Fantoccini
'''
from multiprocessing import Manager, Pool
import sys, traceback

def f(ci, res, r, t):
    try:
        ans = 0
        while (r + ans * 2 + 1) ** 2 - (r + ans * 2) ** 2 <= t:            
            t -= (r + ans * 2 + 1) ** 2 - (r + ans * 2) ** 2 
            ans += 1
        res[ci] = ans
        print ci, ans
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
    
