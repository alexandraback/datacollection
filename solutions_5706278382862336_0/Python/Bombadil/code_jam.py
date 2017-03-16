#! /usr/bin/python -tt
# -*- coding: utf-8 -*-

from fractions import gcd
from math import log
import re



fichier = open('workfile','r')
fout = open('file_out','w')

num_test = int((fichier.readline()).strip())
# caillou_N = f.readline().split()
# caillou_N = [float(i) for i in caillou_N]
# caillou_N.sort()

def f(a,b):
    if b == 1:
        return 0
    if 2**40%b != 0:
        return -1
    else:
        for k in range(1,40):
            if 2**k*a/b >= 1:
                return k

for m in range(0,num_test):

    ligne = ((fichier.readline()).strip())
    match = re.match(r"(\d*)/(\d*)",ligne)
    n1 = int(match.group(1))
    n2 = int(match.group(2))

    a = n1/(gcd(n1,n2))
    b = n2/(gcd(n1,n2))
    


    k = f(a,b)
    
    print k

    if k==-1:
        fout.write("Case #"+ str(m+1) +": "+ "impossible"+"\n")
    else:
        fout.write("Case #"+ str(m+1) +": "+str(k)+"\n")

    

    
    
