#!/usr/bin/python

import re
import sys

tab = [ ['1', 'i', 'j', 'k'],
        ['i', '1', 'k', 'j'],
        ['j', 'k', '1', 'i'],
        ['k', 'j', 'i', '1'] ];

def printErr(msg) :
    sys.stderr.write(msg);
    x = 1;
    x = x;
        
def rewrite(L, pos) :
    global tab;
    sign = 1;
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
    return sign;

def patternReduction(p) :
    times = 1;
    signP = 1;
    if len(p) < 2 :
        p = p+p;
        times = 2;

    while len(p) > 1:
        signP *= rewrite(p, 0);

    return signP, times;
    

f = open("C-large.in", "r");
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
    
    if L*X < 3 :
        print ("Case #" + str(case+1) + ": NO");
        continue;

    word = [];
    while len(word) < 4 and X > 0 :
        word += pattern;
        X -= 1;

    patternNb = 0;
    while word[0] != 'i' and len(word) + L*X > 3 and patternNb < 2 :
        if len(word) <= 3 and X > 0 :
            word += pattern;
            X -= 1;
            patternNb += 1;
        sign *= rewrite(word, 0);
        
    if word[0] != 'i' :
        print ("Case #" + str(case+1) + ": NO");
        continue;

    patternNb = 0;
    while word[1] != 'j' and len(word) + L*X > 3 and patternNb < 2 :
        if len(word) <= 3 and X > 0 :
            word += pattern;
            X -= 1;
            patternNb += 1;
        sign *= rewrite(word, 1);
        
    if word[1] != 'j' :
        print ("Case #" + str(case+1) + ": NO");
        continue;
    
    pSign, times = patternReduction(pattern);
    X = X//times + (X%times);

    while X > 2 :
        pp = [pattern[0], pattern[0]];
        signPP = rewrite(pp, 0);

        if X%2 == 1:
            word += pattern;
            sign *= pSign;
            X -= 1;
            
        X = X/2;
        pattern = pp;
        pSign = signPP;

    while len(word) + X*L > 3 :
        if len(word) <= 3 and X > 0 :
            word += pattern;
            sign *= pSign;
            X -= 1;
        sign *= rewrite(word, 2);
        
    if word[2] != 'k' :
        print ("Case #" + str(case+1) + ": NO");
        continue;

    else :
        if word == ['i', 'j', 'k'] and sign == 1 :
            print ("Case #" + str(case+1) + ": YES");
            continue;

    print ("Case #" + str(case+1) + ": NO");
