
import numpy as np
import pylab as pl
import re 
import scipy as sc
import sys 
f = "foo" 


def code_value(val_in, code, BB):
    if(len(code)==0):
        return(val_in)
    else:
        return(code_value(val_in * BB + code[0], code[1:], BB))


####SWAP TWO LINES TO SWITCH FROM STDIN TO FILE INPUT
in_trimmed = lambda f: f.readline()[:-1]
with open('c:/Users/Fini/Documents/Career/Google/Code Jam/Coin/large.in', 'r') as f:
    Ncases = int(in_trimmed(f))
    CaseIn = [ [] for ncase in range(Ncases)]
    for ncase in range(Ncases):
        NN, JJ = [int(s) for s in in_trimmed(f).split(' ')]
        CaseIn[ncase] = [NN, JJ]

NumErrors = 0 
with open('c:/Users/Fini/Documents/Career/Google/Code Jam/Coin/large.out', 'r') as f:
    print(in_trimmed(f))
    for jline in range(JJ):
        linej = in_trimmed(f)
        print(linej)
        words = linej.split(' ')
        seq = words[0]
        factors = [int(nj) for nj in words[1:10]]
        remainders = [ -1 for fj in factors]
        for BB in range(2,11):
            code = [ int(cj) for cj in seq]
            FF   = factors[BB-2]
            remainders[BB-2] = code_value(0, code, BB) % FF
        if(remainders.count(0) == len(remainders)):
            print("All factors confirmed")
        else:
            NumErrors = NumErrors + 1
            print("Not confirmed!!!")
            print("Not confirmed!!!")
            print("Not confirmed!!!")
            print("Not confirmed!!!")
            print("Not confirmed!!!")
            print(remainders)
            print(factors)
    print("Got {} lines all together".format(jline+1))

if(NumErrors > 0):
    print('Error!!!!')
else:
    print('All factors of all lines confirmed')
