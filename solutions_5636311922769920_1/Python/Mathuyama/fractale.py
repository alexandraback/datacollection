import numpy as np

def getInfo(line):
    t = []
    for n in line.split(' '):
        t.append(int(n))
    return t

def parse(path):
    file = open(path,"r");
    nbCases = int(file.readline());
    txt = file.readlines();
    cases = []
    for line in txt:
        cases.append(getInfo(line));
    file.close()
    return cases

def workfractale(t):
    K = t[0] ## tiles nb
    C = t[1] ## iter fractal
    S = t[2] ## tiles available
    R = []
    if (K%C == 0):
        lel = 0
    else:
        lel = 1
    if (S < ((K/C)+lel)): 
        return "IMPOSSIBLE"
    counter = 0
    while (counter <= K-C):
        i = 0
        for c in range(C):
            i += (K**c)*(c+counter)
        R.append(str(i+1)+' ')
        counter += C
    i = 0
    if (counter != K):
        for c in range(K-counter):
            i += (K**c)*(K-c-1)
        R.append(str(i+1)+' ')
    return R

def outputfractale(tablal,path):
    file = open(path,'w');
    for i in range(len(tablal)):
        R = workfractale(tablal[i]);
        file.write("Case #"+str(i+1)+": "+''.join(R)+"\n");
    file.close();

tablal = parse("D-large.in");
outputfractale(tablal,"outputfractale.out");
