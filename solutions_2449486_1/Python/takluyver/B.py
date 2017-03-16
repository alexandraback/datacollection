# -*- coding: utf-8 -*-
fname = "B-large"
fin = open(fname+".in","r")
fout = open(fname+".out","w")
def gcj_read():
  linestr = fin.readline().strip()
  return [int(numb) for numb in linestr.split()]

numcases = gcj_read()[0]

import numpy as np

def get_stripes(pattern):
    for rowno in range(pattern.shape[0]):
        yield rowno, 0, pattern[rowno,:].max()
    for colno in range(pattern.shape[1]):
        yield colno, 1, pattern[:,colno].max()

for caseno in range(numcases):
    N,M = gcj_read()
    pattern = np.array([gcj_read() for _ in range(N)])
    while True:
        if pattern.size == 0:
            outstr = 'YES'
            break
        
        nextcut = pattern.min()
        cutthistime = False
        for rowno, axis, maxheight in get_stripes(pattern):
            if maxheight == nextcut:
                #print(pattern, rowno, axis)
                pattern = np.delete(pattern, rowno, axis)
                break
        
        else:
            outstr = 'NO'
            break
    
    print(caseno+1, outstr)
    fout.write("Case #"+str(caseno+1)+": "+ outstr +"\n")

fin.close()
fout.close()
