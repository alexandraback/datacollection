'''
Created on 04/05/2013

@author: Fantoccini
'''
from multiprocessing import Manager, Pool
import sys, traceback

def f(I, RES, a, n, ls):
    ls.sort()
    def dfs(aa, pos):
        if aa == 1:
            return len(ls)
        if pos >= len(ls):
            return 0        
        e = ls[pos]
        if e < aa:
            return dfs(e + aa, pos + 1)
        ans = 0
        aaa = aa
        while aa <= e:
            aa += aa - 1
            ans += 1
        ans += dfs(aa + e, pos + 1)
        ans1 = 1 + dfs(aaa, pos + 1)
        if ans > ans1:
            return ans1
        return ans 
        
    try:
        RES[I] = dfs(a, 0)
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
    fin = open("a.in", "r")
    fout = open("a.out", "w")
    T = int (fin.readline())
    RES = manager.list(range(T))
    for I in range(T):
        a, n = map(int, fin.readline().split())
        ls = map(int, fin.readline().split())
        pool.apply_async(f, (I, RES, a, n, ls))
    pool.close()
    pool.join()
    for I in range(T):
        fout.write("Case #" + str (I + 1) + ": " + str(RES[I]) + "\n")
    fin.close()
    fout.close()
    
