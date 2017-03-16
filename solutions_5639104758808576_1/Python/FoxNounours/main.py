#!/usr/bin/python

import re

f = open("A-large.in", "r");
T = f.readline();
m = re.search('[0-9]*', T);
T = int(m.group(0));

reSplit = re.compile(" +");
reEachNumber = re.compile("[0-9]");

for case in range(T) :
    line = f.readline();
    m = reSplit.split(line);
    lpersons = reEachNumber.findall(m[1]);
    summ = 0;
    nbFriends = 0;
    i = 0;
    for S in lpersons :
        if i > summ :
            nbFriends += i - summ;
            summ = i;
        summ += int(S);
        i += 1;
    
    
    print ("Case #" + str(case+1) + ": "+str(nbFriends));
