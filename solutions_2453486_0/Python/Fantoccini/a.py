'''
Created on 13/04/2013

@author: Fantoccini
'''
from multiprocessing import Manager, Pool

def f(ci, res, bd):
    t = True;
    x = False
    o = False  
    for s in bd:
        if "." in s:
            t = False
            continue
        if "X" in s and "O" in s:
            continue
        if "X" in s:
            x = True
        if "O" in s:
            o = True
    if x != o:
        if x:
            res[ci] = "X won"
        else:
            res[ci] = "O won"
    else:
        if t:
            res[ci] = "Draw"
        else:
            res[ci] = "Game has not completed"
    

if __name__ == '__main__':
    ps = [] 
    manager = Manager()
    pool = Pool(5)
    fin = open("a.in", "r")
    fout = open("a.out", "w")
    t = int (fin.readline())
    res = manager.list(range(t))
    for ci in range(t):
        bd = []
        v = ["", "", "", ""]
        d1 = "";
        d2 = ""
        for i in xrange(4):
            bd.append(fin.readline().strip())
            for j in xrange(4):
                v[j] += bd[i][j]
            d1 += bd[i][i]
            d2 += bd[i][3-i]
        bd.extend(v)
        bd.append(d1)
        bd.append(d2)
        print bd
        fin.readline() 
        pool.apply_async(f, (ci, res, bd))
    pool.close()
    pool.join()
    for ci in range(t):
        fout.write("Case #" + str (ci + 1) + ": " + str(res[ci]) + "\n")
    fin.close()
    fout.close()
    
