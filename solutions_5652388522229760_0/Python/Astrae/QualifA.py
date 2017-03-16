# -*- coding: utf-8 -*-
"""
Created on Fri Apr 10 21:34:08 2015

@author: Fred
"""



def qualifA(n):
    n=int(n)
    if n==0:
        return "INSOMNIA"
    else:
        i=1
        digitsmanquant=[0,1,2,3,4,5,6,7,8,9]
        
        while len(digitsmanquant)>0:
            test=i*n
            for k in str(test):
                if int(k) in digitsmanquant:
                    digitsmanquant.remove(int(k))
            i=i+1
        return test
            
                
                



import numpy as np

def main(ifn='A-small-attempt0.in',ofn='output.txt'):
    with open(ifn) as inf:   # ouvre l'input et le renomme en inf
        with open(ofn,'w') as ouf:  # crée l'output dans lequel on va écrire
            noc = int(inf.readline().strip())  # permet de lire la 1ere ligne
                                               # en général le nbr de cas
                                               # le .strip() permet de virer les espace
            

            
            
            for tnoc in range(noc):          # boucle en fonction du nbr de cas

                ouf.write("Case #%d: " %(tnoc+1))   # case dans laquelle on écrit en sortie
                L=inf.readline().strip().split(' ') 
                resultat=qualifA(int(L[0]))

                    
                if type(resultat)==str:    
                    ouf.write("%s\n" %resultat)   # recopie le nombre puis saute une ligne                    
                else:
                    ouf.write("%d\n" %resultat)                 


       


