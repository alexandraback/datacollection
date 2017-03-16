'''
Created on 2013-05-04

@author: maplebaconburgr
'''

INPUT = 'B-small-attempt0.in';
OUTPUT = 'output.txt';

import math

def nCr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)

def diamonds(diamonds, x, y):
    n = x + y;
    minDiamonds = 0.5*n*(n+1);
    maxDiamonds = 0.5*(n+1)*(n+2);
    if diamonds <= minDiamonds:
        return 0.0;
    elif diamonds >= maxDiamonds:
        return 1.0;
    elif x == 0:
        return 0;
    else:
        print diamonds, "\t", minDiamonds;
        diamonds = diamonds - minDiamonds;
        print diamonds;
        want = y + 1;
        if want > diamonds:
            return 0;
        return (nCr(diamonds, want) * (2 ** -(diamonds)));
    return 0;

def main():
    #open files
    inFile = open(INPUT, 'r');
    outFile = open(OUTPUT, 'w');
    
    T = int(inFile.readline());
    
    for case in range(1, T+1):
        inLine = inFile.readline()[:-1].split(' ');
        inLine = [int(x) for x in inLine];
        print inLine;
        result = diamonds(inLine[0], inLine[1], inLine[2]);
        outFile.write('Case #' + str(case) + ': ' + str(result) +  '\n');
       # print 'Case #' + str(case) + ': ', size , others ,  '\n'
        
    #close files
    inFile.close();
    outFile.close();

if __name__ == '__main__':
    main();

    