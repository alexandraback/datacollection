'''
Created on Apr 28, 2012

@author: Fantoccini
'''
from multiprocessing import Process, Manager

def f(ci, res, n, lvl1):    
    res[ci] = 0
    lvl = [0 for i in range(n)]
    scnt = 0
    while lvl1:
        s2, s1, l = lvl1[0]
        if s2 <= scnt:
            lvl1.pop(0)
            scnt = scnt + 2 - lvl[l]
            lvl[l] = 2            
            res[ci] = res[ci] + 1
            continue
        k = 0
        m = -1
        for i in range(len(lvl1)):
            s2, s1, l = lvl1[-(i+1)]
            if lvl[l] == 0 and s1 <= scnt and s2 - s1 > m:
                k = -(i+1)
                m = s2 - s1
        if k < 0:
            s2, s1, l = lvl1[k]
            scnt = scnt + 1
            lvl[l] = 1            
            res[ci] = res[ci] + 1
            continue
        res[ci] = "Too Bad"
        break

if __name__ == '__main__':
    ps = [] 
    manager = Manager()
    fin = open("kr.in", "r")
    fout = open("kr2.out", "w")
    t = int (fin.readline())
    res = manager.list(range(t))
    for i in range(t):
        n = int (fin.readline())
        lvl1 = []
        for j in range(n):
            line = fin.readline()
            line = line.strip('\n')    
            nums = line.split()
            lvl1.append((int(nums[1]), int(nums[0]), j))            
        lvl1.sort()
        p = Process(target=f, args=(i, res, n, lvl1))
        ps.append(p)
        p.start()
    for i in range(t):
        ps[i].join()
        fout.write("Case #" + str (i + 1) + ": " + str(res[i]) + "\n")
    fin.close()
    fout.close()
    
