#!/usr/bin/python3
# vim:fileencoding=utf-8

import sys
import re
import glob
import itertools
from math import sqrt,floor,ceil
import pdb

sys.setrecursionlimit(10000)

def in_out():
    infiles = glob.glob("*.in")
    for infile in infiles:
        keyword = (sys.argv[1] if len(sys.argv)>1 else "test")
        if re.search(keyword, infile):
            return (open(infile,"r"), open(infile[:-2]+"out", "w+"))


def main():
    fin,fout = in_out()
    casenum = int(fin.readline()[:-1])
    for i in range(casenum):
        print(i+1)
        name,n=fin.readline()[:-1].split()
        n=int(n)
        print(name,n)
        #v=[int(i) for i in fin.readline()[:-1].split()]
        #print(v)

        L=len(name)
        #pdb.set_trace()
        vv=[]
        v=-1
        for j in range(L):
            if name[j] in 'aeiou':
                if j-v>n:
                    vv.append((v+1,j))
                v=j
        if v!=L-1 and L-v>n:
            vv.append((v+1,L))

        print(vv)
        y=0
        #if vv!=[]:
            #a,b=vv[0]
            #y=a*(L-a-n+1)
        p=0
        for a,b in vv:
            y+=(a-p)*(L-a-n+1)
            for k in range(b-a-n+1):
                y+=L-(a+k+n)+1
            p=b-n+1

        #for j in range(n,L+1):
            #for k in range(L-j+1):
                #v=-1
                #for l in range(k,k+j):
                    #if name[l] in 'aeiou':
                        #if l-v>n:
                            #y+=1
                            #break
                        #else:
                            #v=l

        fout.write('Case #'+str(i+1)+": "+str(y)+"\n")

    fout.flush()
    fout.seek(0)
    print(fout.read())

if __name__ == "__main__":
    main()

