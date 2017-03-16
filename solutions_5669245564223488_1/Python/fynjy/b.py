#!/usr/bin/python

import sys;
import os.path; 
from collections import *;
from Queue import *;

def readi():
    return int(sys.stdin.readline().strip());

def readia():
    return [int(x) for x in sys.stdin.readline().strip().split()];

def readfa():
    return [float(x) for x in sys.stdin.readline().strip().split()];

def reads():
    return sys.stdin.readline().strip();

MOD = 1000000007;

def fact(n):
    res = 1;
    for i in xrange(1, n+1):
        res = (res * i) % MOD;
    return res;

def main():
    ordA = ord('a');
    nt = readi();
    for t in range(1, nt+1):
        N = readi();
        vags = sys.stdin.readline().strip().split();
        if len(vags) != N:
            print >> sys.stderr, "VERYBAD case ", t

        atBeg = [0] * 26;
        atMid = [0] * 26;
        atEnd = [0] * 26;
        beg = [' '] * N;
        mid = [' '] * N;
        end = [' '] * N;
        sing = [False] * N;

        good = True;
        iVag = 0;
        for vag in vags:
            numStrips = 0;
            chars = set();
            prevChar = ' ';
            for i in range(len(vag)):
                c = vag[i];
                cn = ord(c) - ordA;

                if i == len(vag) - 1 and (numStrips > 1 or (c != prevChar and i > 0)):
                    atEnd[cn] += 1;
                    end[iVag] = c;

                if c == prevChar:
                    continue;

                numStrips += 1;
                chars.add(c);

                if prevChar != ' ':
                    if numStrips > 2:
                        atMid[ord(prevChar) - ordA] += 1;
                        mid[iVag] = prevChar;
                    elif numStrips > 1:
                        atBeg[ord(prevChar) - ordA] += 1;
                        beg[iVag] = prevChar;
                prevChar = c;
            good = good and numStrips == len(chars);
            if numStrips == 1:
                beg[iVag] = vag[0];
                end[iVag] = vag[0];
            sing[iVag] = beg[iVag] == end[iVag];
            iVag += 1;

        #print atBeg;
        #print atMid;
        #print atEnd;
        #print beg;
        #print mid;
        #print end;
        #print sing;
        #print good;

        if good:
            for i in range(len(atBeg)):
                if (atBeg[i] + atMid[i] > 1 or atEnd[i] + atMid[i] > 1):
                    good = False;
        #print good;

        if not good:
            print "Case #%d: 0" % t;
            continue;

        #find linked components
        comp = [0] * N;
        nComp = 0;
        for iVag in range(N):
            if comp[iVag] != 0:
                continue;
            nComp += 1;
            q = deque();
            q.append(iVag);
            while len(q) > 0:
                iv = q.popleft();
                comp[iv] = nComp;
                ee = end[iv];
                bb = beg[iv];
                for niv in range(N):
                    if (beg[niv] == ee or end[niv] == bb) and comp[niv] == 0:
                        q.append(niv);
        #print "comps: ", comp, nComp;

        res = 1;

        for iComp in xrange(1, nComp + 1):
            if not good:
                break;
        
            compVags = filter(lambda x : comp[x[0]] == iComp, zip(range(N), vags));
            #print compVags;
            ggg = False;
            allSing = True;
            #numChains = 0;
            for (iVag, vag) in compVags:
                allSing = allSing and sing[iVag];
                #print "vag " , iVag, ", end: ", end[iVag], ", atEnd: ", atEnd[ord(end[iVag]) - ordA];
                if not sing[iVag] and atEnd[ord(beg[iVag]) - ordA] == 0:
                    ggg = True;
                    #numChains += 1;
                #if atEnd[ord(beg[iVag]) - ordA] == 0:

            if not ggg and not allSing:
                good = False;
                res = 0;
                break;


            numSingForChar = [0] * 26;
            for (iVag, vag) in compVags:
                if (sing[iVag]):
                    numSingForChar[ord(beg[iVag]) - ordA] += 1;
            #print "comp ", iComp, ", numSingForChar: ", numSingForChar, ", numChains ", numChains;


            for ns in numSingForChar:
                res = res * fact(ns) % MOD;
            #res = res * fact(numChains) % MOD;

        res = res * fact(nComp) % MOD;

        #print good;

        print "Case #%d: %d" % (t, res);
    

main();
