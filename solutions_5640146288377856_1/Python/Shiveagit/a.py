# Created By: Bryce Besler
import math;

T = int(raw_input());
for t in xrange(T):
    row = str(raw_input()).split(' ');
    R = int(row[0])
    C = int(row[1]);
    W = int(row[2]);

    flush = int(R*math.floor(C/W));

    if (C%W == 0):
        run = W -1;
    else:
        run = W;


    print "Case #{t}: {ans}".format(t=t+1, ans=flush+run)

