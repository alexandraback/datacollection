'''
Created on 2012-4-14

@author: zhiqiang
'''
from sys import stdin,stdout,argv
import numpy as np

def main(cases):
    res = []
    for A,B in cases:
        count = 0
        for n in range(A,B):
            digits = int(np.ceil(np.log10(n+1)))
            cache = set()
            for i in range(1,digits):
                m = (n%(10**i)) * (10**(digits-i))  + n//(10**i)
                if n < m <= B and m not in cache:
                    cache.add(m)
                    count += 1
        res.append(count)
    return res

def loadData(fin = stdin):
    cases = []
    T = int(fin.readline())
    for i in range(T):
        line = fin.readline()
        rc = line.split()
        cases.append((int(rc[0]),int(rc[1])))
    return cases

def output(res,file = stdout):
    for i in range(len(res)):
        print('Case #{}:'.format(i+1), res[i], file=file)

if __name__ == '__main__':
    if len(argv)>1:
        with open(argv[1]) as fin:
            cases = loadData(fin)
    else:
        cases = loadData()
    res = main(cases)
    output(res)