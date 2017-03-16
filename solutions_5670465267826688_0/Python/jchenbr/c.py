#!/usr/bin/python

import sys

def Multiply(x, y):
    return (
            x[0] * y[0] - x[1] * y[1] - x[2] * y[2] - x[3] * y[3],
            x[0] * y[1] + x[1] * y[0] + x[2] * y[3] - x[3] * y[2],
            x[0] * y[2] + x[2] * y[0] + x[3] * y[1] - x[1] * y[3],
            x[0] * y[3] + x[3] * y[0] + x[1] * y[2] - x[2] * y[1]);

def Power(x, e):
    ret = (1, 0, 0, 0);
    xx = x

    while e != 0:
        if (e & 1):
            ret = Multiply(ret, xx);
        e = e >> 1;
        xx = Multiply(xx, xx)
        #print "Power", ret, e

    return ret;

def GetQuat(ch):
    return ( 0, ch == 'i', ch == 'j', ch == 'k');

def SolvePre(prefix):
    
    for rep in range(4):
        pre = Power(prefix[-1], rep)

        for idx in xrange(len(prefix)):
            if Multiply(pre, prefix[idx]) == (0, 1, 0, 0):
                return (True, idx, rep)

    return (False, 0, 0)

def SolveSub(subfix):

    for rep in range(4):
        sub = Power(subfix[0], rep)

        for idx in xrange(len(subfix) - 1, -1, -1):
            if Multiply(subfix[idx], sub) == (0, 0, 0, 1):
                return (True, idx, rep)

    return (False, 0, 0)

if __name__ == "__main__":
    
    try:
        fin = open(sys.argv[1], 'r')
    except err:
        print "Can't open the input file";


    data = fin.readlines();

    total = int(data[0])

    for case in range(1, total + 1):

        nLen, nRep = [int(item) for item in data[case * 2 - 1].split()];
        
        line = data[ case * 2 ][:-1];

        prefix = [(1, 0, 0, 0) for item in range(nLen)];

        subfix = [(1, 0, 0, 0) for item in range(nLen)];

        prefix[0] = GetQuat(line[0]);
        for i in range(1, nLen):
            prefix[i] = Multiply(prefix[i - 1], GetQuat(line[i]));

        subfix[nLen - 1] = GetQuat(line[nLen - 1]);
        for i in range(nLen - 2, -1, -1):
            subfix[i] = Multiply(GetQuat(line[i]), subfix[i + 1]);

        ret = "NO";

        check = Power(subfix[0], nRep);
        #print "check", subfix[0], check

        if Power(subfix[0], nRep) == (-1, 0, 0, 0):
            bPre, idxPre, repPre = SolvePre(prefix)
            bSub, idxSub, repSub = SolveSub(subfix)

            #print "pre:", bPre, idxPre, repPre
            #print "sub:", bSub, idxSub, repSub


            nNeedRep = repPre + repSub + 2 - (idxPre < idxSub);
            if bPre and bSub and nNeedRep <= nRep:
                ret = "YES"

        print "Case #" + str(case) + ":", ret
