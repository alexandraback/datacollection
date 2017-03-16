# -*- coding: utf-8 -*-
fname = "A-large"
fin = open(fname+".in","r")
fout = open(fname+".out","w")
def gcj_read():
  linestr = fin.readline().strip()
  return [int(numb) for numb in linestr.split()]

from math import log, ceil
inf = float('inf')

numcases = gcj_read()[0]

def scale_up(A, m):
    "returns (adds required, new A)"
    if A==1:
        return inf, 1
    if A > m:
        return 0, A+m
    n = ceil(log(m/(A-1), 2))
    return n, ((A-1)*2**n) + 1 + m

def min_changes(A, motes):
    #print(A, motes)
    removes = len(motes)
    nextmote = motes.pop()
    adds, A = scale_up(A, nextmote)
    adds_plus = (adds + min_changes(A, motes)) if motes else adds
    #print(removes, adds_plus, adds)
    return min(removes, adds_plus)

for caseno in range(numcases):
    A, N = gcj_read()
    motes = gcj_read()
    motes.sort(reverse=True)
    
    outstr = str(min_changes(A, motes))
    
    print("Case #"+str(caseno+1)+": "+ outstr)
    fout.write("Case #"+str(caseno+1)+": "+ outstr +"\n")

fin.close()
fout.close()
