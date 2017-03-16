#!/usr/bin/python

import re
import sys

tab = [ ['1', 'i', 'j', 'k'],
        ['i', '1', 'k', 'j'],
        ['j', 'k', '1', 'i'],
        ['k', 'j', 'i', '1'] ];

def printErr(msg) :
    #sys.stderr.write(msg);
    x = 1;
    x = x;
        
def rewrite(L, pos) :
    global tab;
    global sign;
    x, y = L[pos:pos+2];

    if x=='1':
        x = 0;
    else :
        if x=='i' :
            x = 1;
        else :
            if x=='j' :
                x = 2;
            else :
                if x=='k' :
                    x = 3;

    if y == '1' :
        y = 0;
    else :
        if y=='i' :
            y = 1;
        else :
            if y=='j' :
                y = 2;
            else :
                if y=='k' :
                    y = 3;

    if (x == 1 and (y == 1 or y == 3)) or (x == 2 and (y == 1 or y == 2)) or (x == 3 and (y == 2 or y == 3)) :
        sign *= -1;

    L[pos:pos+2] = tab[x][y];
    return L;

f = open("C-small-attempt4.in", "r");
T = f.readline();
m = re.search('[0-9]*', T);
T = int(m.group(0));

reSplit = re.compile(" +");
reNumber = re.compile("[0-9]+");
rePattern = re.compile("[i-k]");

for case in range(T) :
    sign = 1;
    line = f.readline();
    L, X = reNumber.findall(line);
    L = int(L);
    X = int(X);
    line = f.readline();
    pattern = rePattern.findall(line);
    word = pattern*X;
    printErr(str(L) + " " + str(X) + "\n");
    #printErr("case #" + str(case+1) + ": " + str(pattern) + " * " + str(X) + "\n");

    if len(word) < 3 :
        printErr("too small\n");
        print ("Case #" + str(case+1) + ": NO");
        continue;

    while word[0] != 'i' and len(word) > 3 :
        L = rewrite(word, 0);

    if word[0] != 'i' :
        printErr("wrong prefix\n");
        print ("Case #" + str(case+1) + ": NO");
        continue;

    while word[1] != 'j' and len(word) > 3 :
        L = rewrite(word, 1);

    if word[1] != 'j' :
        printErr("wrong body\n");
        print ("Case #" + str(case+1) + ": NO");
        continue;

    while len(word) > 3 :
        L = rewrite(word, 2);
        
    if word[2] != 'k' :
        printErr("wrong suffix\n");
        print ("Case #" + str(case+1) + ": NO");
        continue;
        
    else :
        if word == ['i', 'j', 'k'] and sign == 1 :
            print ("Case #" + str(case+1) + ": YES");
            continue;

    printErr("wrong sign ?\n");
    print ("Case #" + str(case+1) + ": NO");
