#from pylab import *
from fractions import gcd
from scipy.misc import comb, factorial
import re, sys

def handle(infile, outfile):
    line = infile.readline().split();
    c = int(line[0]);
    n = int(line[1]);
    line = infile.readline().split();
    p = [float(x) for x in line];
    pc = reduce(lambda x, y: x*y, p, 1);
    good = (n - c) + 1;
    bad = (n - c) + 1 + n + 1;
    x1 = good * pc + bad * (1 - pc);
    x2 = 1 + n + 1;
    #print x1, x2
    #oldx = n * 3;
    #dec = False;
    xmin = min(x1, x2);
    for t in range(c, 0, -1):
        good = good + 2;
        bad = bad + 2;
        pc = pc / p[t - 1];
        x = good * pc + bad * (1 - pc);
        if x < xmin:
            xmin = x;
        #if x < oldx:
        #    dec = True;
        #if dec:
        #    if x > oldx:
        #        break
    outfile.write(' %.6f' % xmin);

if len(sys.argv) != 2: exit();
infile = file(sys.argv[1] + '.in', 'r');
outfile = file(sys.argv[1] + '.out', 'w');

count = int(infile.readline());
for i in range(count):
    print 'Case #%d' % (i + 1);
    outfile.write('Case #%d:' % (i + 1));
    result = handle(infile, outfile);
    outfile.write('\n');
