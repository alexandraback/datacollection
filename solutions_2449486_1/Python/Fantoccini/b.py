'''
Created on 13/04/2013

@author: Fantoccini
'''
from multiprocessing import Manager, Pool
from copy import deepcopy

def f(ci, res, n, m, lawn):
    res[ci] = "YES"
    nl = [[100 for j in xrange(m)] for i in xrange(n)]
    for i in xrange(n):
        mm = max(lawn[i])
        for j in xrange(m):
            if (nl[i][j] > mm):
                nl[i][j] = mm
    for j in xrange(m):
        mm = 0
        for i in xrange(n):
            if mm < lawn[i][j]:
                mm = lawn[i][j]
        for i in xrange(n):
            if (nl[i][j] > mm):
                nl[i][j] = mm
    for i in xrange(n):
        for j in xrange(m):
            if lawn[i][j] != nl[i][j]:
                res[ci] = "NO"
                return
    

if __name__ == '__main__':
    ps = [] 
    manager = Manager()
    pool = Pool(5)
    fin = open("b.in", "r")
    fout = open("b.out", "w")
    t = int (fin.readline())
    res = manager.list(range(t))
    for ci in range(t):
        line = fin.readline().strip().split()
        n = int(line[0])
        m = int(line[1])
        lawn = []
        for i in xrange(n):
            lawn.append(map(int, fin.readline().strip().split()))
        pool.apply_async(f, (ci, res, n, m, lawn))
    pool.close()
    pool.join()
    for ci in range(t):
        fout.write("Case #" + str (ci + 1) + ": " + str(res[ci]) + "\n")
    fin.close()
    fout.close()
    
