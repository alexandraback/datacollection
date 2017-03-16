#from pylab import *
from fractions import gcd
from scipy.misc import comb, factorial
import re, sys

def handle(infile, outfile):
    line = infile.readline().split();
    n = int(line[0]);
    l = [0] * 2 * n;
    for i in range(n):
        l[2*i:2*i+2] = [int(x) for x in infile.readline().split()];
    s = 0;
    m = 0;
    i1 = 0;
    done = False;
    score = [0] * n;
    while not done:
        done = True;
        play = False;
        for i in range(n):
            if score[i] < 2:
                done = False;
                if l[2*i + 1] <= s:
                    s += 2 - score[i];
                    m += 1;
                    score[i] = 2;
                    play = True;
                    #print i, 2, s
        if play:
            continue;
        i1 = -1;
        for i in range(n):
            if score[i] == 0:
                done = False;
                if l[2 * i] <= s:
                    if i1 < 0:
                        i1 = i;
                    elif l[2*i+1] > l[2*i1+1]:
                        i1 = i;
        if i1 >= 0:
            s += 1;
            m += 1;
            score[i1] = 1;
            play = True;
            #print i1, 1, s
        if not done and not play:
            outfile.write(' Too Bad');
            return;
    outfile.write(' %d' % m);
    #print m;

if len(sys.argv) != 2: exit();
infile = file(sys.argv[1] + '.in', 'r');
outfile = file(sys.argv[1] + '.out', 'w');

count = int(infile.readline());
for i in range(count):
    print 'Case #%d' % (i + 1);
    outfile.write('Case #%d:' % (i + 1));
    result = handle(infile, outfile);
    outfile.write('\n');
