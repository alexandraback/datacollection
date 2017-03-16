import numpy as np

def getInfo(line):
    t = []
    line = line.split(' ');
    for n in line:
        t.append(int(n));
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

########################

def up(T):
    n = len(T)
    for i in range(n):
        if (T[i] == 1):
            T[i] = 0;
        else:
            T[i] = 1;
            return T;

def createStr(T):
    S = ""
    for i in range(len(T)*2+2):
        S = S+str(T[i])
    return S

def workjamcoin(t):
    N = t[0];
    J = t[1];
    T = [0 for i in range ((N/2)-1)]
    R = ""
    for i in range(J):
        L = map (str, T)
        L = ''.join(L)
        L2 = T[::-1]
        L2 = map (str, L2)
        L2 = ''.join(L2)
        R = R + ("1"+L+L2+"1"+" 3 4 5 6 7 8 9 10 11\n")
        T = up(T)
    return R;
        

########################
        
def outputjamcoin(tablal,path):
    file = open(path,'w');
    for i in range(len(tablal)):
        R = workjamcoin(tablal[i]);
        file.write("Case #"+str(i+1)+": \n"+str(R)+"\n");
    file.close();

tablal = parse("C-large.in");
outputjamcoin(tablal,"outputjamcoin.out");
