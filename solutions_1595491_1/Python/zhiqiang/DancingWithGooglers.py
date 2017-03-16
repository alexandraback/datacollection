'''
Created on 2012-4-14

@author: zhiqiang
'''

from sys import stdin,stdout,argv

def main(cases):
    res = []
    for S,p,t in cases:
        abn = 0
        ren = 0
        for ti in t:
            if ti > 3*p-3:
                abn += 1
            elif ti >= 3*p-4 and ti>0:
                ren += 1
        res.append(abn+min(ren,S))
    return res

def loadData(fin = stdin):
    cases = []
    T = int(fin.readline())
    for i in range(T):
        line = fin.readline()
        rc = line.split()
        cases.append((int(rc[1]),int(rc[2]),[int(k) for k in rc[3:]]))
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