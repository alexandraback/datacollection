'''
Created on Apr 28, 2012

@author: Fantoccini
'''
from multiprocessing import Process, Manager

def f(ci, res, m, n, nums):    
    res[ci] = m + n + 1.0
    if n > m:
        d = 2.0 + n
        if d < res[ci]:
            res[ci] = d
            print ci , ": ", res[ci]
    for i in range(int(m)):
        d = nums[int(m - i - 1)] * (n - m + 1.0 + 2.0 * i) + (1.0 - nums[int(m - i - 1)]) * (2.0 * n - m + 2.0 * i + 2.0)
        if d < res[ci]:
            res[ci] = d
            print ci , ": ", res[ci], i

if __name__ == '__main__':
    ps = [] 
    manager = Manager()
    fin = open("pp.in", "r")
    fout = open("pp.out", "w")
    t = int (fin.readline())
    res = manager.list(range(t))
    for i in range(t):
        line = fin.readline()
        line = line.strip('\n')
        nums = line.split()
        m = float(nums[0])
        n = float(nums[1])
        line = fin.readline()
        line = line.strip('\n')
        nums = line.split()
        for j in range(int(m)):
            nums[j] = float(nums[j])
            if j > 0:
                nums[j] = nums[j] * nums[j - 1]
        print nums         
        p = Process(target=f, args=(i, res, m, n, nums))
        ps.append(p)
        p.start()
    for i in range(t):
        ps[i].join()
        fout.write("Case #" + str (i + 1) + ": " + str(res[i]) + "\n")
    fin.close()
    fout.close()
    
