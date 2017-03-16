'''
Created on 13/04/2013

@author: Fantoccini
'''
from multiprocessing import Manager, Pool
from math import sqrt

def f(ci, res, a, b):
    res[ci] = 0
    i = a - 1
    for i in xrange(a, b + 1):
        r = int(sqrt(i))
        if i != r ** 2:
            continue
        if str(i) != str(i)[::-1]:
            continue
        if str(r) != str(r)[::-1]:
            continue
        res[ci] += 1

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
    
