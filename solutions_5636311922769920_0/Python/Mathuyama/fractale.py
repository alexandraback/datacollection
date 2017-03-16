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

def workfractalesmall(t):
    K = t[0] ## tiles nb
    C = t[1] ## iter fractal
    S = t[2] ## tiles available
    return ' '.join([str(i) for i in range(1,K+1)])

    
def outputfractale(tablal,path):
    file = open(path,'w');
    for i in range(len(tablal)):
        R = workfractalesmall(tablal[i]);
        file.write("Case #"+str(i+1)+": "+R+"\n");
    file.close();

tablal = parse("D-small-attempt0.in");
outputfractale(tablal,"outputfractale.out");
