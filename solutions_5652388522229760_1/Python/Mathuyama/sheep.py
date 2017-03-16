import numpy as np

def getInfo(line):
    L=line.split(' ')
    for i in range(len(L)):
        L[i] = int(L[i])
    return L

def parse(path):
    file = open(path,"r");
    nbCases = int(file.readline());
    txt = file.readlines();
    cases = []
    for line in txt:
        cases.append(getInfo(line))
    file.close()
    return cases


def worksheep(n):
    value = n;
    if (value == 0): return "INSOMNIA"
    chiffres = np.array([False for i in range (10)]);
    chiffres = decomp(value,chiffres);
    while not(np.all(chiffres)):
        value += n;
        chiffres = decomp(value,chiffres);
    return value;

def decomp(n,chiffres):
    while(n>9):
        chiffres[n%10] = True;
        n = n//10;
    chiffres[n] = True;
    return chiffres;

def outputsheep(tablal,path):
    file = open(path,'w');
    for i in range(len(tablal)):
        R = worksheep(tablal[i][0]);
        file.write("Case #"+str(i+1)+": "+str(R)+"\n");
    file.close();


tablal = parse("A-large.in");
outputsheep(tablal,"outputsheep.out");
