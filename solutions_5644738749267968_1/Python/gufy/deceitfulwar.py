# -*- coding: utf-8 -*-

from itertools import repeat
from pylab import *
import numpy

infile = open('input.txt', 'r')
outfile = open("deceitfulwar-big-output.txt", "w")

numcases = int(infile.readline())

wrong = 0

for case in range(0, numcases):
    N = int(infile.readline())
    
    Naomi = zeros(N);
    Ken = zeros(N);
    
    naomiLine = infile.readline().split(" ")
    for i in range(0, N):
        Naomi[i] = float(naomiLine[i])
        
    Naomi.sort()
    
    kenLine = infile.readline().split(" ")
    for i in range(0, N):
        Ken[i] = float(kenLine[i])
        
    Ken.sort()
    
    i = 0;
    j = 0;
    dec_counter = 0;
    while (i < N) and (j < N):
        if (Ken[j] < Naomi[i]):            
            dec_counter = dec_counter + 1;
            j = j + 1
            i = i + 1
        else:
            i = i + 1;            
    
    i = 0;
    j = 0;
    war_counter = 0;
    while (i < N) and (j < N):
        if (Ken[j] > Naomi[i]):
            j = j + 1;
            i = i + 1;
            war_counter = war_counter + 1;
        else:
            j = j + 1;
            
    war_counter =  N - war_counter;

    print(Naomi)
    print(Ken)
    print(dec_counter, war_counter)
    
    outfile.write('Case #'+str(case+1)+': '+str(dec_counter)+' '+str(war_counter)+'\n')

outfile.close()