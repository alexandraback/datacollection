import sys
import math

def main():
    #infile = open('in')
    #infile = open('A-large.in')
    infile = open('A-small-attempt1.in')
    #infile = open('A-small-practice.in')
    #infile = open('A-large-practice.in')
    outfile = open('out', 'w')
    T = long(infile.readline())
    for i in xrange(T):
        outfile.write('Case #'+str(i+1)+': ' + solve(infile) + '\n')

def solve(infile):
    r,c,w = map(long, infile.readline().split())
    c1 = c / w
    res = c1* r
    if w > 1:
        if c % w == 0:
            res += w - 1
        else:
            res += w
    return str(res)

if __name__=='__main__':
    main()
