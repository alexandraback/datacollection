#!/usr/bin/python3
# vim:fileencoding=utf-8

import sys
import re
import glob
import itertools
from math import sqrt,floor,ceil
import pdb



def in_out():
    infiles = glob.glob("*.in")
    for infile in infiles:
        keyword = (sys.argv[1] if len(sys.argv)>1 else "test")
        if re.search(keyword, infile):
            return (open(infile,"r"), open(infile[:-2]+"out", "w+"))

def allink(y,r):
    return 2*y*y+2*y*r-y

def main():
    fin,fout = in_out()
    casenum = int(fin.readline()[:-1])
    for i in range(casenum):
        print(i+1)
        r,t=fin.readline()[:-1].split()
        r=int(r)
        t=int(t)
        print(r,t)
        m=max(floor(sqrt(t/2))-r,1)
        M=ceil(sqrt(t/2))
        print(m,M)
        for y in range(m,M):
            if allink(y,r) <= t and allink(y+1,r)>t:
                fout.write('Case #'+str(i+1)+": "+str(y)+"\n")
                break

    fout.flush()
    fout.seek(0)
    print(fout.read())

if __name__ == "__main__":
    main()

