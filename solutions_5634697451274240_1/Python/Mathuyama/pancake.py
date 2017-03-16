import numpy as np

def getInfo(line):
    t = []
    for c in line:
        if c == '-': t.append(-1);
        if c == '+' : t.append(+1);
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

def workpancake(t):
    n = len(t);
    plusIterator = n;
    counter = 0;
    while (plusIterator > 0):
        while (plusIterator>0 and t[plusIterator-1] == +1):
            plusIterator -= 1;
        if (plusIterator > 0):
            if (t[0] == (-1)):
                t = flip(t,plusIterator);
            else:
                flipIndex = plusIterator-1;
                while not(t[flipIndex] == 1):
                    flipIndex -= 1;
                t = flip(t,flipIndex+1);
            counter += 1;
    return counter;
    

def flip(t,i):
    if (i%2 == 1):
        r = i-1;
        t[i/2] = -t[i/2]
    else:
        r = i;
    for k in range(r/2):
        tmp = t[k];
        t[k] = -t[i-k-1];
        t[i-k-1] = -tmp;
    return t;

def outputpancake(tablal,path):
    file = open(path,'w');
    for i in range(len(tablal)):
        R = workpancake(tablal[i]);
        file.write("Case #"+str(i+1)+": "+str(R)+"\n");
    file.close();

tablal = parse("B-large.in");
outputpancake(tablal,"outputpancake.out");

